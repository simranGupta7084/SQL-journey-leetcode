class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int i = 0;
        int n = intervals.size();

        // Part 1: Intervals completely before newInterval
        while (i < n &&
               intervals[i][1] < newInterval[0]) {

            answer.push_back(intervals[i]);
            i++;
        }

        // Part 2: Merge overlapping intervals
        while (i < n &&
               intervals[i][0] <= newInterval[1]) {

            newInterval[0] =
                min(newInterval[0], intervals[i][0]);

            newInterval[1] =
                max(newInterval[1], intervals[i][1]);

            i++;
        }

        answer.push_back(newInterval);

        // Part 3: Intervals completely after newInterval
        while (i < n) {
            answer.push_back(intervals[i]);
            i++;
        }

        return answer;
    }
};