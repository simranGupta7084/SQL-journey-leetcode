class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int  i = 0;
        int j = 1;
        int n = nums.size();
        int c = 0;
        while(j<n){
            if(i == j){
                j++;
                continue;
            }
            if(nums[j]-nums[i] == k){
                c++;
                i++;
                j++;
                while(j<n && nums[j] == nums[j-1]){
                    j++;
                }
            }else if(nums[j]-nums[i] < k){
                j++;
            }else{
                i++;
            }
        }
        return c;
    }
};