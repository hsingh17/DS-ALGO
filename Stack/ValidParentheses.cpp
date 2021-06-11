class Solution {
public:
    bool isValid(string s) {
        // Method is to use a stack
        // We push opening characters e.g: '(', '{', '['
        // Then when we come across a closing character, we 
        // pop from the stack and see if it the closing character matches the opening character
        // Runtime: O(N) where N is length of s. we need to iterate over all characters to determine
        //          if a string s is valid
        // Space: O(N) at worst we can just push everything in s into the stack
        stack<char> brackets;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                brackets.push(c);
            } else {
                // Nothing to match the closing
                if (brackets.empty()) return false;
                char open = brackets.top();
                brackets.pop();
                
                string open_close = string(1,open) + c;
                
                // The opening does not match the closing
                if (!(open_close == "()" || open_close == "{}" || open_close == "[]"))
                    return false;
            }
        }
        
        // We can still have things in the stack even if the loop didn't return false e.g: '([]{}'
        return brackets.empty();
    }
};
