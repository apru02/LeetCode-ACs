class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> prefix_xor(n);
        prefix_xor[0] = nums[0];
        // cout<<prefix_xor[0]<<" ";
        for(int i = 1;i<n;i++){
            prefix_xor[i] = prefix_xor[i-1] ^ nums[i];
            // cout<<prefix_xor[i]<<" ";
        }

        vector<int> ans;
        for(int i = n-1;i>=0;i--){
            int temp = 0;
            for(int j = 0;j<maximumBit;j++){
                if ((prefix_xor[i] & (1<<j)) == 0) temp += (1<<j);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};