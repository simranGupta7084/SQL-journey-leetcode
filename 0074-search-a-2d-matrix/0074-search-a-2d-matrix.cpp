class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0;
        int high = rows*cols -1;

        while(low <= high){
            int mid = low+(high - low)/2;

            int row = mid/cols; // for find the row
            int col = mid%cols;    // for find the column

            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};