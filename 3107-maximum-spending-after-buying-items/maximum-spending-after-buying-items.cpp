class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
std::priority_queue<std::pair<
long long
, std::pair<
int
, 
int
>>, std::vector<std::pair<
long long
, std::pair<
int
, 
int
>>>, std::greater<std::pair<
long long
, std::pair<
int
, 
int
>>>> pq;
        int n = values.size();
        int m = values[0].size();
        for(int i = 0;i<n;i++){
            pq.push({values[i][m-1],{i,m-1}});
        }
        long long ans = 0;
        for(long long d = 1;d<=m*n;d++){
            ans += pq.top().first*d;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(col > 0) pq.push({values[row][col-1],{row,col-1}});
        }
        return ans;
    }
};