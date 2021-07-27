class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        // Method 1: Brute force is to check every substring starting from idx i 
        // Runtime: O(N^2)
        // Space: O(N)
        // unordered_set<char> found;
        // int best = 1;
        // for (int i = 0; i < s.size(); i++) {
        //     for (int j = i; j < s.size(); j++) {
        //         if (found.find(s[j]) != found.end()) 
        //             break;
        //         else 
        //             found.insert(s[j]);                    
        //     }
        //     best = max(best, (int) found.size());
        //     found.clear();
        // }
        // return best;
        
        // Method 2: Map contains the index were we last saw a character. Start indicates the starting idx                      of the current substring. When we encounter a char we've seen before, then set start                        to the last idx we saw it + 1 (since the char ahead of it are not yet repeating.).
        // Runtime: O(N)
        // Space: O(N)
        
        int best = 1, start = 0;
        map<char,int> fnd;
        
        for (int i = 0; i < s.size(); i++) {
            // Repeating char. in the window
            if (fnd.find(s[i]) != fnd.end() && fnd[s[i]] >= start) {
                best = max(best, i-start);
                start = fnd[s[i]]+1;
            }
            
            fnd[s[i]] = i;
        }
        
        best = max(best, (int)s.size()-start);
        return best;
    }
};
