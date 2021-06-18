class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Method 1: 
        //          Step 1: Create an unordered set O(1)
        //          Step 2: Put all elements of nums1 into the set O(N)
        //          Step 3: Iterate through nums2 and check if the element exists in the set. If it does                               then add it to the return vector and delete it from the set O(M)
        // Runtime: O(M+N) = O(max(N,M)) where N is length of nums1 and M is length of nums2
        // Space: O(N) in the worst case, we can have all elements in nums1 being unique and nums2 is just                     copy of nums1
        
        // Step 1
        unordered_set<int> s;
        
        // Step 2
        for (int& num : nums1)
            s.insert(num);
        
        
        // Step 3
        vector<int> ret;
        for (int& num : nums2) {
            if (s.find(num) != s.end()) {
                ret.push_back(num);
                s.erase(num);
            }
        }
        
        return ret;
        
    }
};
