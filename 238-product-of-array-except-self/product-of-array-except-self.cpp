class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int mul = 1;
        int mul_without_zero = 1;
        int cnt_zero = 0;
        for(int i = 0;i<nums.size();i++){
            mul *= nums[i];
            if(nums[i] == 0) cnt_zero++;
            else mul_without_zero *= nums[i];
        }
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0){
                if(cnt_zero == 1) ans.push_back(mul_without_zero);
                else ans.push_back(0);
            }
            else{
                ans.push_back(mul/nums[i]);
            }
        }
        return ans;
    }
};