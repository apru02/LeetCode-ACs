class Solution {
public:
    int climbStairs(int n) {
        int ahead1 = 1,ahead2 = 0,curr;
        for (int i =n-1;i>=0;i--){
            curr = ahead1 + ahead2;
            ahead2 = ahead1;
            ahead1 = curr;
        }
        return ahead1;
    }
};