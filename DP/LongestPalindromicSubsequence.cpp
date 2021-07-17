class Solution {
public:
    // int ret = 0;
//     bool is_palindrome(const string& t) {
//         int lo = 0, hi = t.size()-1;
//         while (lo < hi) {
//             if (t[lo++] != t[hi--]) return false;
//         }

//         return true;
//     }
    
//     void helper(const string& s, string& t, int k) {
//         if (k == s.size()) {
//             if (is_palindrome(t)) ret = max(ret, (int)t.size());
//             return;
//         }
        
//         t.push_back(s[k]);
//         helper(s,t,k+1);
//         t.pop_back();
//         helper(s,t,k+1);
//     }
    
    int helper(const string& s, int left, int right) {
        if (left == right-1) {
            if (s[left] == s[right]) 
                return 2;
            else
                return 1;
        }
        
        if (left == right) return 1;
        
        if (s[left] == s[right]) {
            return 2 + helper(s, left+1, right-1);
        } else {
            int best_left = helper(s, left, right-1);
            int best_right = helper(s, left+1, right);
            return max(best_left, best_right);
        }
        
    }
    
    int longestPalindromeSubseq(string s) {
//         // Method 1: Brute Force all subsequences (this works but is really bad runtime)
//         int ret = 0;
//         int N = s.size();
//         for (int i = 0; i < 1<<N; i++) { 
//             string t = "";
//             for (int j = 0; j < N; j++) {
//                 if ((i >> j) & 1) t.push_back(s[N-j-1]);
//             }
            
//             if (is_palindrome(t)) ret = max(ret, (int)t.size());
//         }
        
//         return ret;
//      }
        
        // Method 1b: Recursive Brute Force
        // string t = "";
        // helper(s,t,0);
        // return ret;
        
        // Method 2: Brute Force (this one is the intended brute force)
        //          Check if left and right character of subsequence are the same.
        //          If they are then split into a single recursive case where we increase left and                             decrement right.
        //          If not then split into two cases, one where we include left char and the other where we                     include right char.
        //          From there, we return the maximum of the subcases or if only one recursive case then                       add 2 to it (since left and right are the same char).
        //          Base case is a two characters (left == right-1)
        // return helper(s, 0, s.size()-1);
        
        // Method 3: DP
        //           Create 2D DP array. DP[i][j] = longest palindormic subsequence between idx i and idx j
        //           if S[i] != S[j] --> DP[i][j] = max(DP[i+1][j], DP[i][j-1]) 
        //                               DP[i+1][j] --> no include character i 
        //                               DP[i][j-1] --> no include character j
        //           else --> DP[i][j] = 2 + DP[i-1][j-1]
        //                               DP[i-1][j-1] = subproblem between idx i and idx j
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        
        for (int i = s.size()-1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j < s.size(); j++) {
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        
        return dp[0][s.size()-1];
    }
 };

