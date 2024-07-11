class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int n = nums.size();
        int curr = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] != curr){
                if(count == 0){
                    curr = nums[i];
                    count=1;
                }
                else count--;
            }
            else{
                count++;
            }
        }
        return curr;
    }
};