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
    ListNode* new_head = nullptr;
    
    ListNode* helper(ListNode* node) {
        // Method 2: Recursively
        //           Recursively call helper function
        //           When we get to end of the LL
        //           save a pointer to the head.
        //           Then return that node and recursively build up the reversed LL
        // Runtime: O(N)
        // Space: O(N) because of the call stack
        
        // Base Case: Hit the end of the LL
        if (!node->next){
            new_head = node;
            return node;            
        }
        
        ListNode* node2 = helper(node->next);
        (node2)->next = node;
        return (node2)->next;
    }
    
    ListNode* reverseList(ListNode* head) {
        // Method 1: Iteratively
        //           Use 3 pointers
        //           prev --> points to previous node
        //           cur --> current node
        //           next --> next node (cur->next)
        //           Keep doing the following until next is nullptr
        //              cur->next = prev
        //              prev = cur
        //              cur = next
        //              next = next->next
        // Runtime: O(N) where N is length of the LL
        // Space: O(1)
        
        
//         // Check if head is valid
//         if (!head) return nullptr;
//         ListNode* prev = nullptr;
//         ListNode* cur = head;
//         ListNode* next = head->next;
        
//         while (true) {
//             cur->next = prev;
//             prev = cur;
//             // Break condition
//             if (!next) break;
//             cur = next;
//             next = next->next;
//         }
//         return cur;
        if (!head) return nullptr;
        ListNode* end = helper(head);
        (end)->next = nullptr;
        return new_head;
    }
};
