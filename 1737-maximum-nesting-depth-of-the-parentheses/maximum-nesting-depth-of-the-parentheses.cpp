#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<int> st;
        for(auto it: s){
            if(it == '('){
                st.push('(');
                ans = max(ans, static_cast<int>(st.size()));

            } 
            else if(it == ')'){
                if (!st.empty() && st.top() == '(') st.pop();
            }
        }
        return ans;
    }
};

