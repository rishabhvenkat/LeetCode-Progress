class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxf = 0;
        int hash[26] = {0};
        while(r < s.size()) {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);
            while((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--, maxf = 0;
                for(int i = 0; i < 26; i++) maxf = max(maxf, hash[i]);
                l++;
            }
            if((r - l + 1) - maxf <= k) maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};