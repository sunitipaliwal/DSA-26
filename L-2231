class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);

        vector<char> even, odd;

        
        for (char c : s) {
            if ((c - '0') % 2 == 0)
                even.push_back(c);
            else
                odd.push_back(c);
        }

       
        sort(even.begin(), even.end(), greater<char>());
        sort(odd.begin(), odd.end(), greater<char>());

        int e = 0, o = 0;

        
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] - '0') % 2 == 0)
                s[i] = even[e++];
            else
                s[i] = odd[o++];
        }

        return stoi(s);
    }
};
