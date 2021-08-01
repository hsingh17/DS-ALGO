class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Method 1: Brute force check if s can be fnd in t
        // Runtime: O(T)
        // Space: O(1)
        
        // If s is greater than t then it cant be a subsequence of t
        if (t.size() < s.size()) return false;
        int idx = 0;
        for (int i = 0; i < t.size(); i++) {
            if (s[idx] == t[i]) idx++;
            if (idx == s.size()) return true;
        }
        
        return idx == s.size();
    }
};
