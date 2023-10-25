class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
            vector<int> adj[n];
            for(int i = 0;i<n;i++){
                if(i != headID){
                    adj[manager[i]].push_back(i);
                }
            }
            queue<pair<int,int>> q;
            q.push({headID,0});
            int total_time = 0;
            while(!q.empty()){
                int node = q.front().first;
                int TimeStamp = q.front().second;
                q.pop();
                total_time = max(total_time,TimeStamp);
                if(adj[node].size() > 0){
                    //total_time+=informTime[node];
                    for(auto it:adj[node]){
                        q.push({it,TimeStamp+informTime[node]});
                    }
                }
            }
            return total_time;
              
    }
};


