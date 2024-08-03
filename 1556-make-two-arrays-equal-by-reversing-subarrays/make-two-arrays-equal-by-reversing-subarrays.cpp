class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if( target.size() != arr.size() )   return false;
        int a[1001]={0},maxi=INT_MIN;
        for(int i=0 ; i<arr.size() ; i++)
            a[arr[i]]++,a[target[i]]--,maxi=max(max(arr[i],target[i]),maxi);
        for(int i=0 ; i<=maxi ; i++)
            if( a[i] != 0 ) return false;
        return true;
    }
};