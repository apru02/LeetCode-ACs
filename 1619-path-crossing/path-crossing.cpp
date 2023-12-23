class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        st.insert({0,0});
        int x= 0;
        int y = 0;
        for(auto it: path){
            if(it == 'N'){
                y++;
                if(st.find({x,y}) != st.end()){
                    return true;
                }
                else st.insert({x,y});
            }
            if(it == 'S'){
                y--;
                if(st.find({x,y}) != st.end()){
                    return true;
                }
                else st.insert({x,y});
            }
            if(it == 'E'){
                x++;
                if(st.find({x,y}) != st.end()){
                    return true;
                }
                else st.insert({x,y});               
            }
            if(it == 'W'){
                x--;
                if(st.find({x,y}) != st.end()){
                    return true;
                }
                else st.insert({x,y});               
            }
        }
        return false;
    }
};