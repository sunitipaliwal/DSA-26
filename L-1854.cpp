class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
       
        vector<int> diff(2051, 0);

       
        for (auto &log : logs) {
            diff[log[0]]++;   // birth year
            diff[log[1]]--;   // death year (not included)
        }

        int maxPop = 0;
        int currPop = 0;
        int ansYear = 1950;

       
        for (int year = 1950; year <= 2050; year++) {
            currPop += diff[year];

            if (currPop > maxPop) {
                maxPop = currPop;
                ansYear = year;
            }
        }

        return ansYear;
    }
};
