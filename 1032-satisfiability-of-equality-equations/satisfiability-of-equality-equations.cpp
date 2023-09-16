class DisjointSet {
    vector<int> rank;
    vector<int> parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0;i<=n;i++) parent[i] = i;
    }
    int FindUPar(int v){
        if(parent[v] == v) return v;

        return parent[v] = FindUPar(parent[v]);
    }

    void FindUnion(int u,int v){
        int par_u = FindUPar(u);
        int par_v = FindUPar(v);
        if(par_u == par_v) return;

        if(rank[par_u] < rank[par_v]) parent[par_u] = par_v;
        else if(rank[par_u] > rank[par_v]) parent[par_v] = par_u;
        else{
            parent[par_u] = par_v;
            rank[par_v]++;
        }
    }

};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);
        for(auto it: equations){
            int u = it[0] - 'a';
            int v = it[3] - 'a';
            if(it[1] == '='){
                ds.FindUnion(u,v);
            }
        }
        for(auto it: equations){
            int u = it[0] - 'a';
            int v = it[3] - 'a';
            if(it[1] == '!'){
                if(ds.FindUPar(u) == ds.FindUPar(v)) return false;
            }
        }
        return true;
    }
};