class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       int initial_sum = 0;
       int n = customers.size();
       for(int i = 0;i<n;i++){
        if(!grumpy[i]) initial_sum += customers[i];
       }
       int ans = initial_sum;
       int l = 0;
       int r = minutes;
       int window_sum =  0;
       for(int i=0;i<minutes;i++) {
        if(grumpy[i]) window_sum+=customers[i];
       }
       ans = max(ans,ans+window_sum);

       while(r<n){
        if(grumpy[r]) window_sum+=customers[r];
        r++;
        if(grumpy[l]) window_sum-=customers[l];
        l++;
        ans = max(ans,initial_sum+window_sum);
       }
       return ans;
    }
};