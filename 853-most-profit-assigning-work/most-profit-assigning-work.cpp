class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        int n = difficulty.size();
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        for(int i = 0;i<n;i++){
            maxi = max(maxi,v[i].second);
            v[i].second = maxi;
            // cout << "{"<<v[i].first <<" , "<<v[i].second<<"}";
        }
        // sort(worker.begin(),worker.end());
        int ans = 0;
        for(auto wk : worker){
            int l = 0;
            int r = n-1;
            int mid =(l+r)/2;
            int temp = -1;
            while(l<=r){
                if(v[mid].first <= wk) {
                    temp = mid;
                    l = mid+1;
                }
                else{
                    r=mid-1;
                }
                mid = (l+r)/2;
            }
            if(temp != -1) ans += v[temp].second;
        }
        return ans;
    }
};