class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> nodes(n+2,0);
        for(auto it:edges){
            nodes[it[0]]++;
            nodes[it[1]]++;
            if(nodes[it[0]] > 1) return it[0];
            if(nodes[it[1]] > 1) return it[1];
        }
        return 1;
    }
};