class Solution {
public:
    int specialArray(vector<int>& nums) {
        int bucket[1001] = {0};
        for (int num : nums) {
            bucket[num]++;
        }
        int total = nums.size();
        for (int i = 0; i < 1001; i++) {
            if (i == total) {
                return i;
            }
            total -= bucket[i];
        }
        return -1;
    }
};