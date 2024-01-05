class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
            vector<int> temp;
            temp.push_back(nums[0]);
            int len = 1;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] > temp.back()) {
                    temp.push_back(nums[i]);
                    len++;
                }
                else {
                    auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
                    *it = nums[i];
                }
            }
            return len;
    }
};