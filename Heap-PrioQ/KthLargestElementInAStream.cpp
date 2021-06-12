class KthLargest {
public: 
    
    // Method 1:
    // Use PQ (max heap impl) and everytime we add a new val
    // We can pop from the pq k times then repush the popped elements
    // Runtime: O(klgN) where N is length of the pq because 
    //          reinserting the k popped elements each take lgN time complexity
    // Space: O(N) 
    // This method doesn't pass runtime restrictions!
    
//     priority_queue<int> pq;
//     int k;
//     KthLargest(int k, vector<int>& nums) {
//         this->k = k;
//         this->pq = priority_queue<int>(nums.begin(), nums.end());
//     }
    
//     int add(int val) {
//         // Add val to the pq
//         pq.push(val);
        
//         // Pop and save the elements
//         vector<int> save;
//         for (int i = 0; i < k; i++) {
//             save.push_back(pq.top());
//             pq.pop();
//         }
        
//         // Save the return value
//         int ret = save.back();
        
//         // Repush the elements
//         for (int num : save) 
//             pq.push(num);
        
//         return ret;
        
//     }
    
    // Method 2: To optimize previous solution, we know that the Kth largest element
    //           is the 1st smallest element in the subarray from indices [N-k, N).
    //           When we initalize our pq, we first create a min heap pq and pop until the pq
    //           size becomes k. This means we have the largest k elements. 
    //           Now when we add a new element, we just check if the value we're adding is 
    //           greater than the current top (current Kth largest element).
    //           If not then we just return the current top and don't need to add the value to pq
    //           since it will never be one of the Kth largest elements.
    //           If it is greater than we pop the current top, and add the new value 
    //           then return the top of the pq.
    // Runtime: O(lgk) just to insert the value if it's greater than the top
    // Space: O(k) only need k element pq
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        // Create min heap
        this->pq = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        
        // Edge case if nums is empty
        if (k < nums.size()) {
            while (pq.size() != k) pq.pop();
        }
    }
    
    int add(int val) {
        // Check if we need to add val
        // We need: !pq.empty() && pq.size() == k && val
        // in case the pq doesn't have k elements in it
        if (pq.size() >= k && val <= pq.top()) return pq.top();
        
        if (pq.size() >= k) pq.pop();
        pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
