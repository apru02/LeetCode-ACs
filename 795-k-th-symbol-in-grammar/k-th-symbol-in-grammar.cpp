class Solution {
public:
    int kthGrammar(int n, int k) {
        int opp_flag = -1;
        while(n>0){
            int digits = pow(2,n-1);
            if(k > digits/2){
                if(n%2 == 0){
                    k = digits - k + 1;
                    opp_flag*= -1;
                }
                else{
                    k = digits - k + 1;
                }
            }
            if(k == 1){
                if(opp_flag == 1) return 1;
                else return 0;
            }
            n = n - 1;
        }
        return opp_flag ? 1 : 0;
    }
};