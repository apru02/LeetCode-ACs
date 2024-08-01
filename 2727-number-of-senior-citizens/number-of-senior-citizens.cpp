class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(auto it:details){
            int age = 0;
            age+= (it[11]-'0')*10;
            age+= it[12]-'0';
            if(age > 60) cnt++;
        }
        return cnt;
    }
};