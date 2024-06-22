class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> arr;
        arr.push_back(-1);
        for(int i = 0;i<nums.size();i++){
            if(nums[i]%2) arr.push_back(i);
        }
        arr.push_back(nums.size());
        if(arr.size()-2 < k) {
            return 0;
        }
        int l = 1,r = k;
        int ans = 0;
        while(r < arr.size()-1){
            ans += (arr[l]-arr[l-1])*(arr[r+1]-arr[r]);
            l++;
            r++;
        }
        return ans;
    }
};