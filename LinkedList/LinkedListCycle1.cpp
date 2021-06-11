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
    bool hasCycle(ListNode *head) {
//         // Method 1: To solve this, we have 2 pointers: a slow and fast pointer.
//         // Slow pointer moves 1 step, while fast pointer moves 2 steps.
//         // When slow and fast pointer are in the cycle,
//         // eventually they will point to the same node.
//         // Runtime: O(N-C+kC)=O(N+(k-1)C)=O(N+kC) 
//         //          where N is the number of nodes in the LL.
//         //          C is the length of the cycle
//         //          k is the number of iterations before slow == fast
//         // Space: O(1) since the algo only needs constant space for a slow & fast pointer
        
//         // Check if head is nullptr
//         if (!head) return false;
        
//         // Create the slow and fast pointers
//         ListNode* slow = head;
//         ListNode* fast = head;
        
//         // Iterate until convergence
//         // If fast ever becomes nullptr that means there is no cycle
//         // this is because if there was a cycle, then fast will always
//         // be a valid, non-null node.
//         do {
//             slow = slow->next;
//             fast = (fast->next) ? (fast->next)->next : nullptr;
//         } while (slow != fast && fast);
        
//         return (slow == fast && fast);
        // Method 2 : Using a hashmap and 1 pointer, we can iterate over all 
        // nodes in the LL and save each one to a hashmap. If we come across a node
        // that is already been visited, then we have a cycle. If we get to end (e.g: 
        // are node becomes a nullptr) then we have no cycle.
        // Runtime: O(N) since we only need to go over each node at most once (except 
        // the node at the head of the cycle)
        // Space: O(N) since we need to store each node into a hashmap
        
        unordered_set<ListNode*> visited;
        while (head) {
            if (visited.find(head) != visited.end()) {
                return true;
            } else {
                visited.insert(head);
                head = head->next;
            }
        }
        
        return false;
    }
};
