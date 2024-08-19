class Solution {
public:
    int minSteps(int n) {
        int copy = 0;
        int paste = 1;
        int opr = 0;
        while(paste!=n){
            if(n%paste == 0){
                copy = paste;
                opr++;
            }
            paste+=copy;
            opr++;
        }
        return opr;
    }
};