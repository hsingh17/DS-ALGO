class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Method 1: Brute Force
        //           For each of N elements, include the kth element
        //           Then, calculate the sum from [i,N] and each addition of an element
        //           check if sum(i,i+j) == k.
        // Runtime: O(N^2) where N == len of nums
        // Space: O(1) 
        
        // This method doesn't pass.
        // int N = nums.size(), res = 0;
        // for (int i = 0; i < N; i++) {
        //     int cur_sum = 0;
        //     for (int j = i; j < N; j++) {
        //         cur_sum += nums[j];
        //         if (cur_sum == k) res++;
        //     }
        // }
        
        // Method 2: HashMap 
        //           Optimization of method 1. We can do store a running sum
        //           in a HashMap, and at each ith element check if nums[i]-k exists.
        //           Since the HashMap only stores running sums before the ith element,
        //           we can gurantee that if nums[i]-k exists then it will be a subarray.
        //           
        // Runtime: O(N)
        // Space: O(N)
        
        int res = 0, sum = 0, N = nums.size();
        unordered_map<int, int> r_sum;
        r_sum[0] = 1;
        for (int i = 0; i < N; i++) {
            sum += nums[i];
            if (r_sum.find(sum-k) != r_sum.end()) res += r_sum[sum-k];
            r_sum[sum]++;
        }
        
        return res;
    }
};
