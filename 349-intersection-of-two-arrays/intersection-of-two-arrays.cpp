class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       map<int,int> mp1;
       map<int,int> mp2;
       for(auto it:nums1) mp1[it] = 1;
       for(auto it:nums2) mp2[it] = 1;
       vector<int> ans;
       for(auto it:mp1){
           if(mp2[it.first]) ans.push_back(it.first);
       } 
       return ans;
    }
};