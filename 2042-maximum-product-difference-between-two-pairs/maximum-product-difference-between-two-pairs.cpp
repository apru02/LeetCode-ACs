class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX , smini = mini , maxi = INT_MIN, smaxi = maxi;
        mini = *min_element(nums.begin(),nums.end());
        maxi = *max_element(nums.begin(),nums.end());
      unordered_map<int,int>mp;// To check the number of occurrence of maxi & mini
        for(auto it : nums)mp[it]++;
        for(int i=0;i<n;i++){
            if((nums[i]==maxi && mp[maxi]==1) ||(nums[i]==mini && mp[mini]==1))continue;
            smini = min(smini,nums[i]);
            smaxi = max(smaxi,nums[i]);
        }
        int res = (maxi*smaxi)-(mini*smini);
        return res;
    }
};