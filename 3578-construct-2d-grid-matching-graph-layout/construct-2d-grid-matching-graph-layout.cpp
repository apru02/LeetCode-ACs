class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> deg(n);

        // store degrees of all nodes in deg vector and adjacency list we all well aware of
        for(auto it:edges){
            int u=it[0], v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        
        // now find one node having minimum number of connections and as its variable name suggests 
        // he will sit at the corner and it is logical as well becuase we will prefer maximum degree 
        // waaali node to be sitted at the cneter of the grid
        int konePeBaithneWala=min_element(deg.begin(), deg.end())-deg.begin();

        // first row ko prepare karlo rest uske through ban jayengay
        vector<int> firstRowKaMaal={konePeBaithneWala};

        // nothing new in the visited array as it is maitained for keeping track of already sorted nodes
        vector<int> vis(n, 0);
        vis[konePeBaithneWala]=1;

        for(int i=0; i<firstRowKaMaal.size(); i++){
            int node=firstRowKaMaal[i];

            // Bhai ab yeh -> firstRowKaMaal.size()>=2 , islie hai ki mai nahi chahunga 
            // linear array bane , bcoz it would not work in many of the cases
            if(firstRowKaMaal.size()>=2 && deg[firstRowKaMaal.back()]==deg[konePeBaithneWala]){
                break;
            }

            // node ke bagal me mein koshish krunga kii sabse phele chhoti degree walo ko jagah mile
            // fir wahi reason kii we will try to keep maximum number of connection wali ko node in the 
            // center part of the grid
            sort(adj[node].begin(), adj[node].end(), [&](int a, int b){
                return deg[a]<deg[b];
            });

            // now place adjacent nodes simply
            for(auto neighbour:adj[node]){
                if(!vis[neighbour]){
                    firstRowKaMaal.push_back(neighbour);
                    vis[neighbour]=1;
                    break;
                }
            }
        }
        
        // first Row prepared now process all the other rows
        int cols=firstRowKaMaal.size();
        int rows=n/cols;
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        ans[0]=firstRowKaMaal;
        for(int r=1; r<rows; r++){
            for(int c=0; c<cols; c++){
                for(auto neighbour:adj[ans[r-1][c]]){
                    if(!vis[neighbour]){
                        ans[r][c]=neighbour;
                        vis[neighbour]=true;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};