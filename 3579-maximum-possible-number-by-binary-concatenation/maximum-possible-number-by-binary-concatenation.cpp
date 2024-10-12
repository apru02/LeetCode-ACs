class Solution {
public:
    int bit_length(int x){
        int c = 0;
        while(x>0){
            x = x/2;
            c++;
        }
        return c;

    }
    int calc_num(int i,int j,int k,vector<int>&nums,vector<int>&bits){
        int sum = nums[i]*(pow(2,bits[j]+bits[k])) + nums[j]*(pow(2,bits[k])) + nums[k];
        return sum;
    }
    int maxGoodNumber(vector<int>& nums) {
        int maxi = INT_MIN;
        int l0 = bit_length(nums[0]);
        int l1 = bit_length(nums[1]);
        int l2 = bit_length(nums[2]);
        vector<int> bits = {l0,l1,l2};
        maxi = max(maxi,calc_num(0,1,2,nums,bits));
        maxi = max(maxi,calc_num(0,2,1,nums,bits));
        maxi = max(maxi,calc_num(1,0,2,nums,bits));
        maxi = max(maxi,calc_num(1,2,0,nums,bits));
        maxi = max(maxi,calc_num(2,1,0,nums,bits));
        maxi = max(maxi,calc_num(2,0,1,nums,bits));
        return maxi;

    }
};