class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int index=-1;
        for(int i = n-1;i>=0;i--){
            int digit = num[i]-'0';
            if(digit%2){
                index = i;
                break;
            }
        }
        string ans="";
        for(int j = 0;j<=index;j++) ans+=num[j];
        return ans;
    }
};