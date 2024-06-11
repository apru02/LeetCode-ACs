class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        map<int,int> mp2;
        for(int i = 0;i<arr1.size();i++) mp[arr1[i]]++;
        vector<int> ans;
        for(auto it:arr2){
            for(int i=0;i<mp[it];i++) {
                ans.push_back(it);
                mp2[it] = 1;
            }
        }
        vector<int> temp;
        for(int i=0;i<arr1.size();i++){
            if(mp2.find(arr1[i]) == mp2.end()) temp.push_back(arr1[i]); 
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++) ans.push_back(temp[i]);
        return ans;
    }
};