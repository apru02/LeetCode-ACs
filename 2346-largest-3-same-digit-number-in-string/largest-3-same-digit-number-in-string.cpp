class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans = "";
        for(int i = 0;i<=n-3;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                string temp = "";
                for(int j = i;j<i+3;j++) temp += num[j];
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};