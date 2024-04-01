class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = 0;
        int n = s.size();
        int f1;
        for(int i = n-1;i>=0;i--){
            if(s[i]!=' '){
                f1 = i;
                break;
            }
        }
        for(int i = f1;i>=0;i--){
            if(s[i]==' '){
                break;
            }
            c++;
        }
        return c;
    }
};