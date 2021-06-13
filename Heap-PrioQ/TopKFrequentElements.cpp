struct Comp {
    bool operator()(const pair<int,int>& left, const pair<int,int>& right) {
        return left.second < right.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Method 1:
        // 1. Create a map of val --> freq O(N)
        // 2. From the map, create a priority queue (maxheap) sorted by the freq value O(N) because of                     linear time heapify
        // 3. Then, pop from the pq k times to get the k most frequent elements O(k)
        // Runtime: O(N) where N is length of nums
        // Space: O(N) because of the map

        // Step 1
        unordered_map<int,int> m;
        for (int& num : nums) m[num]++;
        
        // Step 2
        vector<pair<int,int>> v;
        for (auto& p : m) v.push_back(p);
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> pq(v.begin(), v.end());
        
        // Step 3
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(pq.top().first);
            pq.pop();
        }
        
        return ret;
    }
};
