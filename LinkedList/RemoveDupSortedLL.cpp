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
    ListNode* deleteDuplicates(ListNode* head) {
//         // Method 1: Since the prompt doesn't say inplace
//         // we can just add each value into a ordered_set ()
//         // then create a new linked list from the values.
//         // Runtime: O(NlgN) where N is the number of nodes in the list. This
//         //          is the runtime because, at worst, where each node is unique,
//         //          we will need to iterate over all N nodes and insert into an 
//         //          balanced BST which has O(lgN) insert.
//         // Space: O(N) since at worst we can add each node's value to the HashMap,
//         //        also we need to create a new LL of size O(N).
        
//         // Check if head is nullptr
//         if (!head) return head;
        
//         set<int> s;
//         ListNode* node = head;
        
//         // Traverse LL till the end
//         while (node) {
//             s.insert(node->val);
//             node = node->next;
//         }
        
//         // Recreate the new LL
//         // Need iterator to traverse a set
//         auto it = s.begin();
//         ListNode* new_LL = new ListNode(*it);
//         node = new_LL;
//         // Adv the iterator
//         it++;
        
//         // Keep iterating till we have all the unique values
//         while (it != s.end()) {
//             node->next = new ListNode(*it);
//             it++;
//             node = node->next;
//         }
        
//         return new_LL;
        
        // Method 2: We do everything in-place and return the head.
        // We need 2 pointers where 1 pointer points to the first element in a
        // a chain of duplicate elements, and the other keeps moving forward till
        // it encounters a node with a different value. Then, we take the first pointer
        // and have it point to the node pointed by the 2nd node, and repeat till the
        // 1st pointer reachs nullptr (EDGE CASE: where 2nd pointer reaches nullptr but 
        // there was a chain of duplicates)
        // Runtime: O(N) since we need to traverse all N nodes
        // Space: O(1) we only need constant space for two pointers
        
        // Check if head is valid
        if (!head) return head;
        
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        
        while (node1) {
            // Move past all the duplicates
            while (node2 && node1->val == node2->val) {
                // Not really necessary to pass but it's good
                // to free dynamically allocated memory
                ListNode* copy = node2;
                node2 = node2->next;
                delete copy;
            }
            // Remove the duplicates by having node1 point
            // to where node2 is currently (a non-duplicate value node)
            node1->next = node2;
            node1 = node2;
            node2 = (node2) ? node2->next : nullptr;
        }
        
        return head;
    }
};
