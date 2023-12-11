class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        while(i<n){
            if(arr[i]==arr[j]){
                i++;
            }
            else{
                if(i-j > n/4) return arr[j];
                j=i;
                i++;
            }
        }
        return arr[j];
    }
};