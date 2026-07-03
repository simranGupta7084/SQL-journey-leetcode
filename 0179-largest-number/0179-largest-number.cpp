class Solution {
public:
    // bool camp

    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(int c: nums){
            ans.push_back(to_string(c));
            
        }
        sort(ans.begin(),ans.end(),[](const string& a,const string &b){
        return a+b > b+a;
    });

        if(ans[0] =="0") return "0";

        string res;
        for(string s : ans){
            res+= s;
        }
        return res;
    }
};