class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        parent.resize(4 * n * n);
        
        for (int i = 0; i < 4 * n * n; i++) {
            parent[i] = i;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int index = 4 * (i * n + j);
                char val = grid[i][j];
                
                // Connect internal parts of the cell
                if (val != '\\') {
                    unite(index, index + 1);
                    unite(index + 2, index + 3);
                }
                if (val != '/') {
                    unite(index, index + 2);
                    unite(index + 1, index + 3);
                }
                
                // Connect the cell to its neighbors
                if (i < n - 1) {
                    unite(index + 3, index + 4 * n);
                }
                if (j < n - 1) {
                    unite(index + 2, index + 4 + 1);
                }
            }
        }
        
        // Count the number of connected components
        int regions = 0;
        for (int i = 0; i < 4 * n * n; i++) {
            if (find(i) == i) {
                regions++;
            }
        }
        
        return regions;
    }
};
