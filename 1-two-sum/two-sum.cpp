class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        for(int i = 0;i<n;i++){
            v[i]={nums[i],i};
        }
        sort(v.begin(),v.end());
        int l =0;
        int r = n-1;
        while(l<r){
            if(v[l].first + v[r].first < target){
                l++;
            }
            else if (v[l].first + v[r].first > target){
                r--;
            }
            else{
                return {v[l].second,v[r].second};
            }
        }
        return {-1,-1};
    }
};