class Solution {
public:
    int maximumLength(string s) {
        unordered_map<char, vector<int>> mp;
        int n = s.size();

        // Step 1: build groups
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            mp[s[i]].push_back(j - i);
            i = j;
        }

        int ans = -1;

        // Step 2: try each character
        for (auto &it : mp) {
            vector<int> &v = it.second;

            for (int len = 1; len <= 1000; len++) {
                int count = 0;
                for (int x : v) {
                    if (x >= len)
                        count += (x - len + 1);
                }
                if (count >= 3)
                    ans = max(ans, len);
            }
        }
        return ans;
    }
};