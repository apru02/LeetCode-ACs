class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first_index = 0, second_index = 0;
        int ans = INT_MIN;
        int l = 0, r = 0;
        int n = fruits.size();
        int first = -1, second = -1;
        while (l <= r && r < n) {
            if (fruits[r] != first && fruits[r] != second) {
                first = fruits[first_index];
                second = fruits[r];
                l = first_index;
            }
            if (r > 0 && fruits[r] != fruits[r - 1])
                first_index = r;
            ans = max(ans,r-l+1);
            // cout<<ans<<endl;
            r++;
        }
        return ans;
    }
};