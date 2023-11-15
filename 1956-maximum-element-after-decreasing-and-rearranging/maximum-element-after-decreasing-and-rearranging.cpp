class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n =arr.size();
        int prev = 1;
        for(int i = 1;i<n;i++){
            if(arr[i] >= prev+1) prev = prev+1;
        }
        return prev;
    }
};