class Solution {
public:
    int lengthOfLastWord(string s) {
        int right = s.size() - 1;
        int count = 0;
        while(right >= 0){
            if(s[right] == ' ' && count == 0){
                right--;}
            else if( (s[right] >= 'a' && s[right] <= 'z')||(s[right] >= 'A' && s[right] <= 'Z')){
                count++;
                right--;
            }else{
                break;
            }
        }
        return count;   
    }
};