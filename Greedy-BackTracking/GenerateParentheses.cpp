class Solution {
public:
    vector<string> ret;
    
    void helper(string& s, int open, int close) {
        // Case 4
        if (!open && !close) {
            ret.push_back(s);
            return;
        }
        
        // Case 3
        if (open > close) return;
        
        // Case 1 
        if (open <= close && open) {
            s.push_back('(');
            helper(s, open-1, close);
            s.pop_back();
        }
        
        // Case 2
        if (open < close) {
            s.push_back(')');
            helper(s, open, close-1);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        // Method 1: Backtracking
        //           We can backtrack to create each string. 
        //           Case 1: # opening == # closing --> recurse on only opening brace
        //           Case 2: # opening < # closing --> recurse on both cases (if nonzero) if # opening = 0                              then only closing.
        //           Case 3: # opening > # closing --> not valid case since we have more closing than                                    opening
        //           Case 4: # opening == # closing == 0 --> a valid combination of parentheses
        string s = "";
        helper(s,n,n);
        return ret;
    }
};
