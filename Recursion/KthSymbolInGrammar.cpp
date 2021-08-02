class Solution {
public:
//     int ret = -1;
//     void kthGrammar(const int& n, const int& k, int cur_n, int cur_k, int symbol) {
//         if (cur_n == n && cur_k == k) {
//             ret = symbol;
//             return;
//         }
        
//         if (cur_n > n)
//             return;
        
//         if (cur_n == n && cur_k != k)
//             return;
        
//         if (symbol == 0) {
//             kthGrammar(n, k, cur_n+1, (2*cur_k)-1, 0);
//             kthGrammar(n, k, cur_n+1, 2*cur_k, 1);
//         } else {
//             kthGrammar(n, k, cur_n+1, (2*cur_k)-1, 1);
//             kthGrammar(n, k, cur_n+1, 2*cur_k, 0);
//         }
//     }
    
//     int helper(const int& n, const double& k, int cur_n, int last_idx, int symbol) {
//         if (cur_n == n+1) 
//             return symbol;
        
//         int denom = 1;
//         for (int i = 0; i < n-cur_n; i++)
//             denom <<= 1;
        
//         int idx = ceil(k / denom);
//         if ((!symbol && idx != last_idx*2) || (symbol && idx == last_idx*2)) {
//                 return helper(n, k, cur_n+1, idx, 0);            
//         } else {
//             return helper(n, k, cur_n+1, idx, 1);
//         }
        
//         // Longer version of above
//         // if (!symbol) {
//         //     if (idx == last_k*2) {
//         //         return helper(n, k, cur_n+1, idx, 1);
//         //     } else {
//         //     }
//         // } else {
//         //     if (idx == last_k*2) {
//         //         return helper(n, k, cur_n+1, idx, 0);
//         //     } else {
//         //         return helper(n, k, cur_n+1, idx, 1);
//         //     }
//         // }
//     }
    
    
    int kthGrammar(int n, int k) { 
        // Method 1: Brute force all grammars
        // kthGrammar(n, k, 1, 1, 0);
        // return ret;
        
        // Method 2: Figure out direction of recursion at each step, so we don't waste time with                      unnecessary work.
//         if (n == 1) return 0;
        
//         return helper(n, k, 2, 1, 0);
        
        // Method 3: Unlike Method 2 this works bottom up, which ends up with cleaner code
        //           If k is even then parent is k/2 node above and this node is right child of parent
        //           If k is odd then parent is (k+1) / 2 node above and this node is left child of parent
        //           Depending on if above parent is 0 or 1 and if child is left or right return 1 or 0
        if (n == 1) return 0;
        
        if (!(k % 2))
            return kthGrammar(n-1, k/2) ? 0 : 1;
        else
            return kthGrammar(n-1, (k+1) / 2) ? 1 : 0;
    }
};
