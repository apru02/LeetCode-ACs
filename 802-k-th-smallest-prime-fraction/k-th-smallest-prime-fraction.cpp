class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<float, pair<int, int>>> a;
        int n = arr.size();
        float temp;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                temp = (float)arr[i] / (float)arr[j];
                a.push_back({temp, {i, j}});
            }
        }
        sort(a.begin(), a.end());
        // for (int i = 0; i < a.size(); i++) {
        //     cout << a[i].first << " " << arr[a[i].second.first] << "/"
        //          << arr[a[i].second.second] << endl;
        // }
        return {arr[a[k - 1].second.first], arr[a[k - 1].second.second]};
    }
};