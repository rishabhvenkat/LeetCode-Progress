class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3] = {-1, -1, -1};
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                cnt += 1 + std::min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }
        return cnt;
    }
};

