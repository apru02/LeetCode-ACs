class Solution {
public:
    int hIndex(vector<int>& citations) {
        map<int,int> mp;
        for(int i = 0;i<citations.size();i++){
            for(int j = 0;j<=citations[i];j++){
                mp[j]++;
            }
        }
        int h = 0;
        for(int i = 0;i<=citations.size();i++){
            if(mp[i] >=i) h =max(h,i);
        }
        return h;
    }
};