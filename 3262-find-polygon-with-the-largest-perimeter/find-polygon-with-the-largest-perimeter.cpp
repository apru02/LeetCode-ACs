class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long int flag=0,cp[n];
        for(int i=0;i<n;i++)
        flag+=nums[i],cp[i]=flag;
        for(int i=n-1;i>=2;i--)
        {
            if(nums[i]<cp[i-1])
                return nums[i]+cp[i-1] ;
        }
        return -1;
    }
};