class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int right = 0, left = 0, maxlen = 0;
        vector<int> hash(256, -1);
        while (right < n) {
            if (hash[s[right]] != -1) {
                if (hash[s[right]] >= left) {
                    left = hash[s[right]] + 1;
                }
            }
            int len = right - left + 1;
            maxlen = max(len, maxlen);
            hash[s[right]] = right;
            right++;
        }
        return maxlen;
    }
};