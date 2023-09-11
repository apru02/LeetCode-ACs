class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        map<int,vector<int>> mp;
        vector<vector<int>> ans;
        for(int i =0;i<n;i++){
            mp[groupSizes[i]].push_back(i);
        }
        for(auto it:mp){
            int l = it.second.size();
            int grpSize = it.first;
            int i =0;
            while(i<l){
                vector<int> temp(grpSize);
                for(int j = 0;j<grpSize;j++){
                    temp[j] = it.second[i];
                    i++;
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};