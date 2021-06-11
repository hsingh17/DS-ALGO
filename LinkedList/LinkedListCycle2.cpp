/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
//         // Method 1: Using slow & fast pointers we can first
//         // detect if there is a cycle. If there is no cycle return nullptr.
//         // If there is a cycle, we can start one of the pointers back to head of LL
//         // and move each pointer one step and they will meet at the head.
//         // Runtime: O(N) where N is number of nodes in LL
//         // Space: O(1) we only need constant space for the pointers
        
        
//         // Check if head is valid
//         if (!head) return nullptr;
        
//         // Detect if there is a cycle
//         ListNode* slow = head;
//         ListNode* fast = head;
//         do {
//             slow = slow->next;
//             fast = (fast->next) ? (fast->next)->next : nullptr;
//         } while (slow != fast && fast);
        
//         // No cycle: fast is nullptr
//         if (!fast) return nullptr;
        
//         // Find the node where the cycle begins
//         slow = head;
//         while (slow != fast) {
//             slow = slow->next;
//             fast = fast->next;
//         }
        
//         return slow;
        // Method 2: We can use one pointer and a hashmap. We hash every node we come across
        // If there is a cycle, then the first node we visit for the second time will
        // be the head of the cycle.
        // Runtime: O(N) 
        // Space: O(N) since we need to place every node in the HashMap
        
        // Check if head is valid
        if (!head) return nullptr;
        
        unordered_set<ListNode*> visited;
        
        while (head) {
            // Found the head of the cycle
            if (visited.find(head) != visited.end()) return head;
            visited.insert(head);
            head = head->next;
        }
        
        // No cycle in the linked list
        return nullptr;
    }
};
