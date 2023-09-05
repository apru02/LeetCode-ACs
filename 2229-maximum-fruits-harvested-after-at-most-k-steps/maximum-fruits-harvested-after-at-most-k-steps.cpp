class Solution {
private:
    bool valid(int l, int r, int k, int sp){
        if(r <= sp) return sp - l <= k;
        if(l >= sp) return r - sp <= k;
        
        int x = r - sp;
        int y = sp - l;

        return ( ((2*x + y) <= k) || ((2*y + x) <= k));
    }
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

        int n = fruits.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int maxi = 0;
        while(right < n){
            sum += fruits[right][1];
            while(left <= right && !valid(fruits[left][0],fruits[right][0],k,startPos)){
                sum -= fruits[left][1];
                left++;
            }
            maxi = max(maxi,sum);
            right++;
        }
        return maxi;
    }
};