class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> substrFreq;
        unordered_map<char, int> charFreq;

        int i = 0;
        int distinct = 0;
        int ans = 0;

        for (int j = 0; j < s.size(); j++) {
           
            charFreq[s[j]]++;
            if (charFreq[s[j]] == 1)
                distinct++;

            
            if (j - i + 1 > minSize) {
                charFreq[s[i]]--;
                if (charFreq[s[i]] == 0)
                    distinct--;
                i++;
            }

           
            if (j - i + 1 == minSize && distinct <= maxLetters) {
                string sub = s.substr(i, minSize);
                substrFreq[sub]++;
                ans = max(ans, substrFreq[sub]);
            }
        }

        return ans;
    }
};
