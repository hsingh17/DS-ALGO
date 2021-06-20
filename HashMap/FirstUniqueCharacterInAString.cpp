class Solution {
public:
    int firstUniqChar(string s) {
        // Method 1:
        //          Step 1: Create a HashMap of the characters in s and a pair which contains the freq and                             earliest occurrence of the character.
        //          Step 2: Iterate through the key value pairs in the HashMap and choose the character with                             minimum index and frequency 1.
        // Runtime: O(N) where N is the length of the string s
        // Space: O(N) 


        // Step 1
        unordered_map<char,pair<int,int>> m;
        for (int i = 0; i < s.size(); i++) {
            char& c = s[i];
            if (m.find(c) != m.end())
                m[c].first++;
            else
                m[c] = make_pair(1, i);
        }
        
        // Step 2
        int ret = 1e9;
        for (auto& p : m) {
            auto& freq_idx = p.second;
            if (freq_idx.first == 1)
                ret = min(ret, freq_idx.second);
        }
        
        return (ret == 1e9) ? -1 : ret;
    }
};
