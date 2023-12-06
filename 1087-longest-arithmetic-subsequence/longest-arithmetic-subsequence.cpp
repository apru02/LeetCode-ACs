class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        
        if(nums.size()<=2)
        {
            return nums.size();
        }
        int ans  = 0;
        unordered_map<int,int>jd[nums.size()];
      
        for(int i=1; i<nums.size(); i++)
        {
            for(int j = 0; j<i; j++)
            {
                int diff = nums[i]-nums[j];
                int cnt  = 1;
                if(jd[j].count(diff)!=0)
                {
                    cnt+=jd[j][diff];
                    jd[i][diff]=cnt;
                }
                else
                {
                    jd[i][diff]=1+cnt;
                }
                ans  = max(ans,jd[i][diff]);
            }

        }

        return ans;

    }
};