#include <bits/stdc++.h>
class Solution {
public:
int Bsearch(int x,vector<int>& days){
        int r = days.size() - 1;
        int l = 0;
        int mid = (l+r)/2;
        while(l<=r){
            if(days[mid] == x){
                return mid;
            }
            if(days[mid]< x){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
            mid = (l+r)/2;
        }
        return mid;
    }

int f(int ind, vector<int>& days, vector<int>& costs, vector<int>& dp) {
    int n = days.size();
    if (ind >= n) return 0;
    if (dp[ind] != -1) return dp[ind];

    int OneDay = costs[0] + f(ind + 1, days, costs, dp);

    int nextValidDay = days[ind] + 6;
    int ind_seven_days = upper_bound(days.begin(),days.end(),nextValidDay)-days.begin();
    int SevenDay = costs[1] + f(ind_seven_days, days, costs, dp);

    nextValidDay = days[ind] + 29;
    int ind_thirty_days = upper_bound(days.begin(),days.end(),nextValidDay)-days.begin();
    int ThirtyDay = costs[2] + f(ind_thirty_days, days, costs, dp);

    int minCost = min(OneDay, min(SevenDay, ThirtyDay));
    return dp[ind] = minCost;
}

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        return f(0,days,costs,dp);
    }
};