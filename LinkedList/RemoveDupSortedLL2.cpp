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
        // Method 1: We can use a dictionary to keep track of all node values
        // and their respective frequencies. Then, we can create the new LL
        // using only the values that have a frequency of 1.
        // Runtime: O(NlgN) since for each N nodes we need to insert/update
        //          which requires lgN time for a self-balancing BST
        // Space: O(N) since at worst we can keep track of N unique nodes
//         if (!head) return nullptr;
        
//         map<int,int> m;
//         ListNode* node = head;
        
//         // Iterate over the LL and keep track of frequency of values
//         while (node) {
//             m[node->val]++;
//             node = node->next;
//         }
        
//         // Recreate the new LL with only distinct values
//         ListNode* new_head = new ListNode();
//         node = new_head;
//         for (const auto& p : m) {
//             if (p.second == 1) {
//                 node->next = new ListNode(p.first);
//                 node = node->next;
//             }
//         }
        
//         return new_head->next;
        // Method 2:
        // We can do it inplace with 3 nodes and 1 variable: prev, node1, node2, fnd
        // prev: keeps track of the LL such that everything up to and including prev is distinct
        // node1 and node2 are used to determine if elements are distinct.
        // fnd determines the number of nodes whose value == node1->val.
        // Repeat the following steps for all N nodes until node2 is nullptr
        // Case 1: Fnd == 1
        //         This means that node1 and node2 only fnd one node who has the same val as node1
        //         This is a distinct element, so we set prev = node1, node1=node2. Repeat
        // Case 2: Fnd >= 1 (Found >= 1 nodes with non-distinct value)
        //         Subcase 2a: If it occurs at beginning of LL (prev == nullptr), then we set
        //                      head = node1 = node2
        //                     Repeat
        //         Subcase 2b: In the middle, then we set prev->next=node2, node1=node2
        //         Subcase 2c: At the end of LL (node2 == nullptr), prev->next=node2, node1=node2
        // Runtime: O(N) since we only iterate over all N elements once
        // Space: O(1) only need 3 pointers and a variable
        
        // Check if head is valid
        if (!head) return nullptr;
        
        ListNode* prev = nullptr;
        ListNode* node1 = head;
        ListNode* node2 = head;
        
        while (node2) {
            int fnd = 0;
            
            // Find all non-distinct elements
            while (node2 && node1->val == node2->val) {
                fnd++;
                node2 = node2->next;
            }
            
            // Case 1
            if (fnd == 1) {
                prev = node1;
            } else if (prev && fnd >= 1) {
                // Case 2b/c
                prev->next = node2;
            } else if (!prev && fnd >= 1) {
                // Case 2a
                head = node2;
            }
            node1 = node2;
        }
        
        return head;
    }
};
