class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> answer;

        for (vector<int>& current : intervals) {

            // If answer is empty or intervals do not overlap
            if (answer.empty() ||
                current[0] > answer.back()[1]) {

                answer.push_back(current);
            }
            else {
                // Intervals overlap, so update ending point
                answer.back()[1] =
                    max(answer.back()[1], current[1]);
            }
        }

        return answer;
        
    }
};