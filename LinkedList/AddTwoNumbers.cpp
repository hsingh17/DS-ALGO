/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Method 1:
        // Just do the problem like how you would logically.
        // We can use % 10 to find the digit in the ones place (if the sum of two node values >= 10)
        // Runtime: O(N) where N = max(|l1|, |l2|)
        // Space: O(N) if we use a new LL 
        //        O(1) if we use the longer of the two LL
        
        // ListNode* ret = new ListNode();
        // ListNode* node = ret;
        int carry = 0, length_l1 = 0, length_l2 = 0;
        ListNode* l1_head = l1;
        ListNode* l2_head = l2;
        ListNode* p_l1 = nullptr;
        ListNode* p_l2 = nullptr;
        
        while (l1 || l2) {
            // Because l1 and l2 can be different lengths
            // We need to check if l1 and l2 are actually valid to access
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;
            
            int sum  = l1_val + l2_val + carry;
            
            // We have a carry if the sum of the 2 nodes is >= 10
            carry = sum >= 10;
             
            // Confine sum to be in [0,9]
            sum %= 10;
            
            // // Create the node in the LL and move it forward
            // node->next = new ListNode(sum);
            // node = node->next;
            
            // Since we don't which one is the longer of the two LL
            // We can just set both of their current node values to be the sum
            // But at the end return the longer one
            if (l1) {
                l1->val = sum;
                length_l1++;
            }
            
            if (l2) {
                l2->val = sum;
                length_l2++;
            }
            
            // Move l1 and l2 forward, checking for nullptrs
            p_l1 = l1;
            p_l2 = l2;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        
        // Edge case where we still have carry after loop
        if (carry) {
            if (length_l1 > length_l2) 
                p_l1->next = new ListNode(carry);
            else
                p_l2->next = new ListNode(carry);
        }
        
        return (length_l1 > length_l2) ? l1_head : l2_head;
    }
};
