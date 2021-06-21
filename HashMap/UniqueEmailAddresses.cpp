class Solution {
public:
    string parse_left(string& left) {
        // . = ignore
        // + = break (since we ignore everything after)
        string parsed_left = "";
        for (char& c : left) {
            if (c == '.') continue;
            if (c == '+' || c == '@') break;
            parsed_left += c;
        }
            
        return parsed_left+'@';
    }
    
    int numUniqueEmails(vector<string>& emails) {
        // Method 1:
        //          Step 1: Create an unordered set to maintain the UNIQUE emails
        //          Step 2: For each string, parse the local name and domain name (split at the @) and add it                             into the set. 
        //          Step 3: Return the size of emails
        // Runtime: O(N) where N is the length of emails
        // Space: O(N) since at worst we can have N unique emails
        
        // Step 1
        unordered_set<string> s;
        for (string& email : emails) {
            int idx_at = email.find('@') + 1;
            string left = email.substr(0, idx_at);
            string p_left  = parse_left(left);
            string right = email.substr(idx_at, email.size()-idx_at-1);
            s.insert(p_left + right);
        }
        
        return s.size();
    }
};
