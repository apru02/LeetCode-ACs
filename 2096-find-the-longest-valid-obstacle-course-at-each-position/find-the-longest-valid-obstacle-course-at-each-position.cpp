class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        vector<int> dp;
        for(int i=0; i<obstacles.size(); i++)
        {
            int index= upper_bound(dp.begin(), dp.end(), obstacles[i]) - dp.begin();
            
            if(index<dp.size())
            {
                dp[index]= obstacles[i];
                ans.push_back(index+1);
            } 
            else
            {
                dp.push_back(obstacles[i]);
                ans.push_back(dp.size());
            }
        }
        return ans;
    }
};