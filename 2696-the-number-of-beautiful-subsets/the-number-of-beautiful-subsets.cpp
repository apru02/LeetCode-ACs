class Solution {
public:
int solve(int ind,int k,vector<int>& nums,vector<int>& temp){
    int n = nums.size();
    if(ind >= n) {
        if(temp.size()) return 1;
        return 0;
    };
    int a = 0,b=0;
    int flag = 1;
    for(auto it:temp){
        if(abs(it-nums[ind]) == k) {
            flag = 0;
            break;
        }
    }
    if(flag){
        temp.push_back(nums[ind]);
        a = solve(ind+1,k,nums,temp);
        temp.pop_back();
    }
    b = solve(ind+1,k,nums,temp);
    return a + b;
}
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> temp = {};
        return solve(0,k,nums,temp);
    }
};