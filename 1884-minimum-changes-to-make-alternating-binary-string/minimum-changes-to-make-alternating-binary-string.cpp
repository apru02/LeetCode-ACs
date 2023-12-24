class Solution {
public:
    int minOperations(string s) {
        int a = 0,b=1;
        int cnt1=0,cnt2=0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '1'){
                if(a==0) cnt1++;
                if(b==0) cnt2++;
                a = a^1;
                b = b^1;
            }
            else{
                if(a==1) cnt1++;
                if(b==1) cnt2++;
                a = a^1;
                b = b^1;               
            }
        }
        return min(cnt1,cnt2);
    }
};