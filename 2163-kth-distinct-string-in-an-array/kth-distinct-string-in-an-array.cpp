class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
       unordered_map<string,int> hash;
        for(int i=0 ; i<arr.size() ; i++ )
            hash[arr[i]]++;
            int j=k;
        for(int i=0 ; i<arr.size() ; i++)
        {
            if(hash[arr[i]]==1)  k--;
            if(k==0) return arr[i]; 
        }
        return "";
    }
};