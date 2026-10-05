class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};
        int n = s.size(), m = t.size(); 
        
        int l = 0, r = 0, cnt = 0;
        int sIndex = -1, minLen = 1e9; 
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

      
        while (r < n) {
           
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--; 
           
            while (cnt == m) {
                int currentLen = r - l + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    sIndex = l;
                }

                hash[s[l]]++; 
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++; 
            }
            r++; 
        }

       
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};
