class Solution {
public:
    int minSwaps(string s) {
        stack<char> st; // Stack to track unbalanced parentheses

        for(auto &i : s)
            if(i == '[')
                st.push(i); // Push opening bracket to the stack
            else if(!st.empty() && st.top() == '[')
                st.pop(); // Excluding balanced pairs
            else
                st.push(i); // Push closing bracket to the stack

        int unbalancedPairs = st.size() / 2;
        int swaps = ceil(unbalancedPairs / 2.0);
        return swaps;
    }
};