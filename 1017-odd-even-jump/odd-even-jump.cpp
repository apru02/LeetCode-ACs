class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> next_greater(n, -1), next_smaller(n, -1);
        vector<pair<int, int>> sort_by_value;
        stack<int> st;
        for(int i = 0; i < n; i++){
            sort_by_value.push_back({arr[i], i});
        }
        sort(sort_by_value.begin(), sort_by_value.end());
        for(auto [a, i] : sort_by_value){
            while(!st.empty() && st.top() < i){
                next_greater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        st = stack<int>();
        for(int i = 0; i < n; i++){
            sort_by_value[i] = {-arr[i], i};
        }
        sort(sort_by_value.begin(), sort_by_value.end());
        for(auto [a, i] : sort_by_value){
            while(!st.empty() && st.top() < i){
                next_smaller[st.top()] = i;
                st.pop(); 
            }
            st.push(i);
        }
        vector<bool> oddStartingPoint(n, false), evenStartingPoint(n, false);
        oddStartingPoint[n - 1] = evenStartingPoint[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--){
            if(next_greater[i] != -1){
                oddStartingPoint[i] = evenStartingPoint[next_greater[i]];
            }
            if(next_smaller[i] != -1){
                evenStartingPoint[i] = oddStartingPoint[next_smaller[i]];
            }
        }
        return accumulate(oddStartingPoint.begin(), oddStartingPoint.end(), 0);
    }
};