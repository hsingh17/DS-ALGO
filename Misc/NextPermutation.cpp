class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Method 1:
        // 1. Keep ith element iff everything after isnt sorted in decreasing order because keeping ith                   element when everything after is sorted in decreasing order won't make the permutation                     longer. Update i to j (the point right before the decreasing order was broken)
        // 2. If not (everything after is in decreasing order) then swap ith element with next largest                   element and sort the remainder of nums in increasing order.
        
//         int left = 0;
//         while (left < nums.size()) {
//             bool dec = true;
//             for (int i = left+2; i < nums.size(); i++) {
//                 if (nums[i-1] < nums[i]) {
//                     dec = false;
//                     left = i-1;
//                     break;
//                 }
//             }
//             if (dec) break;
//         }
        
//         // If left is at the 2nd to last idx, we just need to swap the last two elements in nums.
//         if (left == nums.size()-2) {
//             swap(nums[left], nums[left+1]);
//             return;
//         }
        
//         // Find the NEXT STRICTLY largest element from [left+1, N]
//         int next_idx = left, next_largest = 1e9;
//         for (int i = left+1; i < nums.size(); i++) {
//             if (nums[i] == nums[left]) continue;
//             next_largest = min(next_largest, max(nums[left], nums[i]));
//             if (next_largest == nums[i])
//                 next_idx = i;
//         }
            
//         // Swap the nums[left] with the next largest number
//         swap(nums[left], nums[next_idx]);
        
//         // Selection sort the rest
//         for (int i = left == next_idx ? left : left+1; i < nums.size(); i++) {
//             int smallest = i;
//             for (int j = i+1; j < nums.size(); j++) {
//                 if (nums[j] < nums[smallest])
//                     smallest = j;
//             }
//             swap(nums[i], nums[smallest]);
//         }
        // Method 2: The optimal method is just my method but going from right to left, since it's faster                      to find the element we need to change.
        int i = nums.size()-2;
        for (; i >= 0; i--) {
            if (nums[i] < nums[i+1]) break;
        }
        
        // If i == -1 then the whole array must be reversed since it's all in decreasing order
        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Find the NEXT STRICTLY largest element from [left+1, N]
        //         // Find the NEXT STRICTLY largest element from [left+1, N]
        int next_idx = i, next_largest = 1e9;
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[j] == nums[i]) continue;
            next_largest = min(next_largest, max(nums[i], nums[j]));
            if (next_largest == nums[j])
                next_idx = j;
        }
        
        // Swap the nums[left] with the next largest number
        swap(nums[i], nums[next_idx]);
        
        // Sort the rest
        sort(nums.begin()+i+1, nums.end());
    }
};
