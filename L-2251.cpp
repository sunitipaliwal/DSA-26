class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        map<int,int> diff;

        // Step 1: Difference array
        for (auto &f : flowers) {
            diff[f[0]]++;
            diff[f[1] + 1]--;
        }

        // Step 2: Sort people with index
        vector<pair<int,int>> q;
        for (int i = 0; i < people.size(); i++) {
            q.push_back({people[i], i});
        }
        sort(q.begin(), q.end());

        vector<int> ans(people.size());
        int curr = 0;
        auto it = diff.begin();

        // Step 3: Prefix sum + query
        for (auto &p : q) {
            int time = p.first;
            int idx = p.second;

            while (it != diff.end() && it->first <= time) {
                curr += it->second;
                it++;
            }

            ans[idx] = curr;
        }

        return ans;
    }
};
