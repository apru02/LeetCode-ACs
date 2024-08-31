class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        long long n = health.size();
        vector<long long> time;
        vector<pair<long double,int>> arr; 
        
        for(int i=0;i<n;i++){
            time.push_back(1LL*ceil((1.0*health[i])/(1.0*power)));
            long double dps = 1LL*(1.0*damage[i])/(1.0*time[i]);
            arr.push_back({dps,i});
        }
        
        sort(arr.rbegin(),arr.rend());
        long long ans=0,sum=0;
        for(int i=0;i<n;i++){
            sum += (1LL*damage[arr[i].second]);
        }
        for(int i=0;i<n;i++){
            ans += 1LL*sum*(time[arr[i].second]);
            sum -= damage[arr[i].second];
        }
        return ans;
    }
};