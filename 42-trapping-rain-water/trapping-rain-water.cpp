class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int start_index = 0;
        int last_index = n-1;
        for(int i =1;i<height.size();i++){
            if(height[i]<height[i-1]) {
                start_index = i-1;
                break;
            }
        }
        for(int i =n-2;i>=0;i--){
            if(height[i]<height[i+1]) {
                last_index = i+1;
                break;
            }
        }
        int max_height = height[0];
        int highest_index = 0;
        for (int i = 0;i<height.size();i++){
            if(height[i] >= max_height){
                max_height = height[i];
                highest_index = i;
            }
        }
        stack<int> st;
        st.push(height[start_index]);
        int temp_area = 0;
        int area = 0;
        
        for(int i = start_index+1;i<highest_index;i++){
            if (height[i] >= st.top()){
                area += temp_area;
                temp_area = 0;
                st.pop();
                st.push(height[i]);
            }
            else{
                temp_area += st.top() - height[i];
            }
        }
        area += temp_area;
        temp_area = 0;
        st = stack<int>();
        st.push(height[last_index]);
        for(int i = last_index-1;i>highest_index;i--){
            if (height[i] >= st.top()){
                area += temp_area;
                temp_area = 0;
                st.pop();
                st.push(height[i]);
            }
            else{
                temp_area += st.top() - height[i];
            }
        }
        area+=temp_area;
        return area;


    }
};