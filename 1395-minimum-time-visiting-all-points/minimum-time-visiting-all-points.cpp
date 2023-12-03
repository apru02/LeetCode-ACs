class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for(int i = 1;i<points.size();i++){
            int max_diagonal=min(abs(points[i][0]-points[i-1][0]),abs(points[i][1]-points[i-1][1]));
            //cout<<max_diagonal<<endl;
            time += abs(points[i][0]-points[i-1][0])+abs(points[i][1]-points[i-1][1])-max_diagonal;
        }
        return time;
    }
};