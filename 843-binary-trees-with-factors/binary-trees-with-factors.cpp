class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int,int> index;
        int n = arr.size();
        int MOD = 1e9+7;
        for(int i = 0;i<n;i++) index[arr[i]] = i;
        vector<long long> dp(n,1);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(arr[i]%arr[j] == 0){
                    int x = arr[i]/arr[j];
                    if(index.find(x) != index.end()){
                        dp[i] = (dp[i] + dp[j]*dp[index[x]])%MOD;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++) ans = (ans+dp[i])%MOD;
        return ans;
    }
};