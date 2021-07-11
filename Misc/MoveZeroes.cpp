class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Method 1:
        //          For every 0, keep swapping until a variable end. end keeps track of the point in which                       the last 0 was inserted.
        // Runtime: O(KN) where K = number of 0s and N is size of nums
        // Space: O(1)
//         int N = nums.size()-1, end = N;
        
//         for (int i = N; i >= 0; i--) {
//             if (nums[i] != 0) continue;
//             for (int j = i; j < end; j++) 
//                 swap(nums[j], nums[j+1]);
//             end--;
//         }
        
        // Method 2: 
        //          Create a queue of the non-zero elements. Keep replacing the                                                 elements until the queue is empty then fill with 0s.
        // Runtime: O(N)
        // Space: O(N)
//         queue<int> q;
//         int N = nums.size();
//         for (int& num : nums) {
//             if (num) 
//                 q.push(num);
//         }
        
//         int q_size = q.size();
//         for (int i = 0; i < N; i++) {
//             if (i < q_size) {
//                 nums[i] = q.front();
//                 q.pop();
//             } else {
//                 nums[i] = 0;
//             }
//         }
        // Method 3: Snowball method
        //           As we traverse the array, we can collect all the 0s like a snowball and then when we                        encounter a non-zero element, we can swap it with the first 0 in the snowball.
        // Runtime: O(N)
        // Space: O(1)
        int snowball = 0, N = nums.size();
        
        for (int i = 0; i < N; i++) {
            if (!nums[i]) 
                snowball++;
            else
                swap(nums[i], nums[i-snowball]);
        }
        
    }
};
