class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          int n = s.size();
        
        // Assuming all ASCII characters
        int HashLen = 256; 
        
        /* Hash table to store last
        occurrence of each character*/
        int hash[HashLen]; 
        
        /* Initialize hash table with
        -1 (indicating no occurrence)*/
        for (int i = 0; i < HashLen; ++i) {
            hash[i] = -1;
        }

        int l = 0, r = 0, maxLen = 0;
        while (r < n) {
            
            /* If current character s[r] 
            is already in the substring*/
            if (hash[s[r]] != -1) {
                
                /* Move left pointer to the right
                of the last occurrence of s[r]*/
                l = max(hash[s[r]] + 1, l);
            }
            
            // Calculate the current substring length
            int len = r - l + 1;
            
            // Update maximum length found so far
            maxLen = max(len, maxLen);
            
            /* Store the index of the current
            character in the hash table*/
            hash[s[r]] = r;
            
            // Move right pointer to next position
            r++;
        }
       
        // Return the maximum length found
        return maxLen;  
    }
};