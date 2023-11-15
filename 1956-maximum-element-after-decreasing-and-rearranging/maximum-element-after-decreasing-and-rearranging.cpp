class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n =arr.size();
        vector<int> res(n);
        res[0] = 1;
        for(int i = 1;i<n;i++){
            if(arr[i] >= res[i-1]+1) res[i] = res[i-1]+1;
            else res[i] = res[i-1];
        }
        return res[n-1];
    }
};