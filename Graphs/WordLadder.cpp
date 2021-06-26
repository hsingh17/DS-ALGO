class Solution {
public:
    // int best = 1e9;
    // unordered_map<string,int> best_paths;
    // unordered_map<string,vector<string>> adj;
    
//     int dfs(string cur_word, const string& end_word, const vector<string>& word_list, unordered_set<string>& seen, int path_length) {
//         // Base case / Step 3
//         if (cur_word == end_word)  {
//             best = min(best, path_length);
//             best_paths[cur_word] = min(best_paths[cur_word], 0);
//             return 1;
//         }
        
//         // Check if current path is longer than saved path
//         if (best_paths.find(cur_word) != best_paths.end() &&
//            path_length >= best_paths[cur_word]) return best_paths[cur_word];
        
//         best_paths[cur_word] = 1e9;
        
//         // Step 1
//         for (const string& word : adj[cur_word]) {
//             // This word is already in the path
//             if (seen.find(word) != seen.end()) continue;

//             seen.insert(word);
//             // dfs(word, end_word, word_list, seen, path_length+1);
//             int ret = dfs(word, end_word, word_list, seen, path_length+1);
//             seen.erase(word);         
//             best_paths[cur_word] = min(best_paths[cur_word], path_length);
//         }
        
//         return best_paths[cur_word];
//     }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Method 1:
        //          Brute Force Solution (Doesn't pass runtime)
        //          Step 1: Find all words with one letter difference from the current word
        //          Step 2: Recurse on those words and in each one of those recursive calls,
        //                  maintain a seen array so we don't cause infinite loops
        //          Step 3: Keep repeating until we hit the endWord (or don't), and return the length of                               the path
        //          Step 4: If we hit the endWord, save the minimum path length

        // Method 2:
        //          Improved Brute Force (still doesn't pass)
        //          Just like memoization in DP problems, we can save the best length path from the current                     word to the endWord.
        //          If the current path is longer than the saved path then return the saved path length.
        //          This should improve runtime.
        // unordered_set<string> seen;
        // seen.insert(beginWord);
        
        // dfs(beginWord, endWord, wordList, seen, 1);
        // dfs(beginWord, endWord, wordList, seen);
        
        // return (best == 1e9) ? 0 : best;
        
        // Method 3
        //         Instead of DFS, use BFS since DFS will brute force ALL paths to the endWord
        //         While BFS will search wide, and once it finds the endWord, it will be guaranteed to be                      the shortest to the endWord.

        // Find each words neighbors (words with only a single letter difference)
        unordered_map<string,vector<string>> adj;

        wordList.push_back(beginWord);
        for (string& word1 : wordList) {
            for (string& word2 : wordList) {
                int diff = 0;
                for (int i = 0; i < word1.size(); i++) {
                    if (word1[i] != word2[i]) diff++;
                    if (diff > 1) break;
                }
                
                if (diff == 1) 
                    adj[word1].push_back(word2);
            }
        }
        
        queue<pair<string,int>> bfs;
        unordered_set<string> seen;
        int ladder = 0;
        
        bfs.push(make_pair(beginWord,1));
        seen.insert(beginWord);
        
        while (!bfs.empty()) {
            string& cur_word = bfs.front().first;
            if (cur_word == endWord) return bfs.front().second;
            
            for (string& neighbor : adj[cur_word]) {
                if (seen.find(neighbor) != seen.end()) continue;
                bfs.push(make_pair(neighbor, bfs.front().second+1));
                seen.insert(neighbor);
            }
            
            bfs.pop();
        }
        
        return 0;
    }
};
