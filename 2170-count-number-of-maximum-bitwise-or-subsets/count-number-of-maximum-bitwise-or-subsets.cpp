class Solution {
public:
    int solve(int max_or, int curr, int ind, vector<int>& nums) {
        int n = nums.size();
        if (ind >= n) {  
            return (curr == max_or) ? 1 : 0;
        }

        int include = solve(max_or, curr | nums[ind], ind + 1, nums);

        int exclude = solve(max_or, curr, ind + 1, nums);

        return include + exclude;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for (int num : nums) {
            max_or |= num;
        }
        return solve(max_or, 0, 0, nums);
    }
};
