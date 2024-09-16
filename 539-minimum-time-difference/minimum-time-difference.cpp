class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        for(int i = 0;i<timePoints.size();i++){
            int hours = 10*(timePoints[i][0]-'0') + (timePoints[i][1]-'0');
            int minutes = 10*(timePoints[i][3]-'0') + (timePoints[i][4]-'0');
            time.push_back(hours*60 + minutes);
        }
        sort(time.begin(),time.end());
        int n = time.size();
        int mini = time[0] + 24*60 - time[n-1];
        for(int i = 0;i<n-1;i++){
            mini = min(mini,time[i+1]-time[i]);
        }
        return mini;
    }
};