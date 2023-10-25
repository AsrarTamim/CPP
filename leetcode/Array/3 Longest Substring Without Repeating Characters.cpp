class Solution {
public:
    // This function calculates the length of the longest substring without repeating characters
    int lengthOfLongestSubstring(string s) {
        // Get the size of the input string
        int n = s.size();
        
        // Create an unordered map to store the last known index of each character
        unordered_map<char, int> mp;
        
        // Initialize the map with all characters set to -1
        for (char c = 'a'; c <= 'z'; c++) {
            mp[c] = -1;
        }
        
        // Initialize variables to keep track of the current longest substring
        int ans = 0; // Length of the longest substring
        int l = 0;   // Left pointer of the current substring
        int r = 0;   // Right pointer of the current substring
        
        // Iterate through the input string
        for (int i = 0; i < n; i++) {
            if (mp[s[i]] == -1) { 
                // If the character is not seen before, update the right pointer
                mp[s[i]] = i;
                r = i;
            } else { 
                // If the character is repeated, update the left pointer to skip the previous occurrence
                l = max(l, mp[s[i]] + 1);
                mp[s[i]] = i;
                r = i;
            }
            
            // Calculate the length of the current substring and update the maximum length
            ans = max(ans, r - l + 1);
            
            // If left pointer is greater than right pointer, break (no valid substring)
            if (l > r) break;
        }
        
        // Handle a special case where the first character is a whitespace
        if (s.size() > 0 && isspace(s[0])) ans = 1;
        
        // Return the length of the longest substring without repeating characters
        return ans;
    }
};
