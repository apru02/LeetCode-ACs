class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums) mp[it]++;
        int ans = 0;
        for(auto it:mp){
            if(it.second<2) return -1;
            if(it.second%3==0) ans+= it.second/3;
            else if(it.second%3==1) ans+= (it.second-4)/3 + 2;
            else ans+= (it.second/3)+1;
        }
        return ans;
    }
};