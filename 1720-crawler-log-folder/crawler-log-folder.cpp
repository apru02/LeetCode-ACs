class Solution {
public:
    int minOperations(vector<string>& logs) {
        int curr = 0;
        for(int i = 0;i<logs.size();i++){
            string temp = logs[i];
            int n = temp.size();
            if(n >=3 && temp[n-2]=='.' && temp[n-3]=='.') curr = max(0,curr-1);
            else if(temp[n-2]!='.') curr++;

        }
        return curr;
    }
};