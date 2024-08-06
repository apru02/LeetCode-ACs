class Solution {
public:
    int minimumPushes(string word) {
        int arr[26] = {0} , count = 0;
        for(int i=0 ; i<word.size() ; i++)
            arr[word[i]-'a']++;
        sort(arr , arr+26);
        for(int i=25 ; i>=0 ; i--)
           count+=(arr[i]*(((25-i)/8)+1)); // cout<<arr[i];
      return count;

    }
};