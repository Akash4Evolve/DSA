class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }

private:
    void backtrack(vector<string>& ans, string current, int open, int close, int max) {
        // Base case: If the string length reaches 2 * n, we found a valid combination
        if (current.length() == 2 * max) {
            ans.push_back(current);
            return;
        }

        // Choice 1: Add an open parenthesis if we have remaining pairs
        if (open < max) {
            backtrack(ans, current + "(", open + 1, close, max);
        }

        // Choice 2: Add a close parenthesis only if it won't exceed the open ones
        if (close < open) {
            backtrack(ans, current + ")", open, close + 1, max);
        }
    }
};
