class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void reset(int x){
        parent[x] = x;
        rank[x] = 0;
    }
    bool connected(int x, int y) {
        return findUPar(x) == findUPar(y);
    }
};
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        DisjointSet ds(n);
        if(n==1) return true;
        for(int i = 0;i<n;i++){
            int x = nums[i];
            if (x==1) return false;
            for(int d = 2;d*d <= x;d++){
                if(x%d == 0){
                    if(mp.count(d)) ds.unionByRank(i,mp[d]);
                    else mp[d] = i;

                    while(x%d == 0) x/=d;
                }
            }
            if (x > 1){
                if (mp.count(x)) ds.unionByRank(i,mp[x]);
                else mp[x] = i;
            }
        }
        bool flag = true;
        for(int i = 0;i<n;i++){
            if (!ds.connected(i,0)){
                flag = false;
                break;
            }
        }
        return flag;

    }
};