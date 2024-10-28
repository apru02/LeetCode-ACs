class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long> num_set;
        for (int num : nums) {
            num_set.insert(num);
        }
        int max_length = 0;
        for (long long num : num_set) {
            int length = 0;
            long long current = num;
            while (num_set.find(current) != num_set.end()) {
                length++;
                if (current > 100000) break; 
                current = current * current;
            }
            if (length > 1) {
                max_length = max(max_length, length);
            }
        }
        
        return max_length > 1 ? max_length : -1;
    }
};