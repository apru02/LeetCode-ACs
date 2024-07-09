class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total = 0;
        double n = customers.size();
        double curr = 0; 
        for(int i = 0;i<n;i++){
            curr = max(curr,(double)customers[i][0])+customers[i][1];
            total += curr-customers[i][0];
            // cout<<curr<<endl;
        }
        // cout << total;
        return total/n ;
    }
};