class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Method 1: 
        // Step 1: Create a Hashmap with a key of the string in sorted order and value a vector of all                          strings where when put into sorted order they're the key.
        // Step 2: Iterate through each string and sort the string and put it into the HashMap
        // Step 3: Iterate through the values of the HashMap and push them to a return vector
        // Runtime: O(N(KlgK)) where N is length of strs and K = max(str[0], strs[1], ... strs[N-1])
        // Space: O(N) since at worst we can N strings that are not anagrams of one another
        
        // Step 1
        unordered_map<string, vector<string>> anagrams;
        
        // Step 2
        for (string& str : strs) {
            string sorted_str(str);
            sort(sorted_str.begin(), sorted_str.end());
            anagrams[sorted_str].push_back(str);
        }
        
        // Step 3
        vector<vector<string>> ret;
        for (auto& p : anagrams)
            ret.push_back(p.second);
        
        return ret;
    }
};
