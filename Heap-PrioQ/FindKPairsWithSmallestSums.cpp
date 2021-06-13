struct Comp {
    bool operator()(const vector<int>& lhs, const vector<int>& rhs) {
        return (lhs[0] + lhs[1]) > (rhs[0] + rhs[1]);
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         // Method 1: Brute Force
//         //          1. Create every possible pair O(NM)
//         //          2. Create a minheap pq from it O(NM)
//         //          3. Pop from heap k times or until pq is empty O(k) 
//         // Runtime: O(NM) where N is length of nums1 and M is length of nums2
//         // Space: O(NM) since we will need to store every possible pair
        
//         // Step 1
//         vector<vector<int>> v;
//         for (int& i : nums1) 
//             for (int& j : nums2) 
//                 v.push_back({i,j});
        
//         // Step2
//         priority_queue<vector<int>, vector<vector<int>>, Comp> pq(v.begin(), v.end());
        
//         // Step 3
//         vector<vector<int>> ret;
//         for (int i = 0; i < k && !pq.empty(); i++) {
//             ret.push_back(pq.top());
//             pq.pop();
//         }
        
//         return ret;
        
        
        // Method 2: Optimized approach
        //          To optimize, we need to realize that because both arrays are sorted in INCREASING order                     the first pair to be included will always include the first elements in each array.
        // Step 1: Create tuples including 0th element from nums1 and [0, k-1] elements from nums2 and                        index of the elements from nums1 (which is 0 in the beginning) O(k)
        // Step 2: Create a pq from these tuples O(k)
        // Step 3: Do the following for k iterations or until pq is empty. O(k)
        //       Step 3a: Pop from the pq and add to the return vector
        //       Step 3b: Add into the pq a new tuple containing the NEXT element from nums1, the current                             element from nums2, and advance the current index of the element from nums1.                               Making sure to check index boundaries.
        // Runtime: O(k)
        // Space: O(k)
        
        
        // Step 1
        vector<vector<int>> v;
        for (int i = 0; i < nums2.size() && i < k; i++)
            v.push_back({nums1[0], nums2[i], 0});
        
        // Step 2
        priority_queue<vector<int>, vector<vector<int>>, Comp> pq(v.begin(), v.end());
        
        // Step 3
        vector<vector<int>> ret;
        for (int i = 0; i < k && !pq.empty(); i++) {
            auto save = pq.top();
            pq.pop();
            ret.push_back({save[0], save[1]});
            
            if (save[2] < nums1.size()-1) {
                int new_idx = save[2]+1;
                pq.push({nums1[new_idx], save[1], new_idx});                
            }
        }
        
        return ret;
    }
};
