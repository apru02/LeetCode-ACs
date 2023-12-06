class Solution {
public:
    int totalMoney(int n) {
        int m = n/7;
        int ans = 0;
        ans += m*(56+(m-1)*7)/2;
        if(n%7){
            int k = n%7;
            for(int i =m+1;i<=m+k;i++) ans+=i;
        }
        return ans;
    }
};