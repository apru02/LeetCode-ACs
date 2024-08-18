class LUPrefix {
public:
    vector<int> segTree;
    int N;

    LUPrefix(int n) : N(n) {
        segTree.resize(4 * N, 0);  // Resize the segment tree to 4 * N
        build(0, 1, N);
    }
    
    void build(int ind, int low, int high) {
        if (low == high) {
            segTree[ind] = 0;
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);
        segTree[ind] = segTree[2 * ind + 1] && segTree[2 * ind + 2];  // Initialize internal nodes
    }

    void update(int x, int low, int high, int ind) {
        if (x < low || x > high) return;
        if (low == high) {
            if (x == low) segTree[ind] = 1;
            return;
        }
        int mid = (low + high) / 2;
        update(x, low, mid, 2 * ind + 1);
        update(x, mid + 1, high, 2 * ind + 2);
        segTree[ind] = segTree[2 * ind + 1] && segTree[2 * ind + 2];
    }

    int query(int low, int high, int ind) {
        if (segTree[ind] == 1) return high;  // Entire range is covered
        if (low == high) return low - 1;  // Return the last uploaded video index
        int mid = (low + high) / 2;
        if (segTree[2 * ind + 1] == 1) {
            // If the left child is fully covered, continue to the right child
            return query(mid + 1, high, 2 * ind + 2);
        } else {
            // Otherwise, check the left child
            return query(low, mid, 2 * ind + 1);
        }
    }

    void upload(int video) {
        update(video, 1, N, 0);
    }

    int longest() {
        return query(1, N, 0);
    }
};
