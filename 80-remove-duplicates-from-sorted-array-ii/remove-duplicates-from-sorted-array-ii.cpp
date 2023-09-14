#include<bits/stdc++.h>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]<3) temp.push_back(nums[i]);
        }
        int ans = temp.size();
        for(int i = 0;i<ans;i++) {
            nums[i] = temp[i];
        }
        return ans;
    }
};