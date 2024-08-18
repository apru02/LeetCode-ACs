class LUPrefix {
public:
    set<int>st;
    LUPrefix(int n) {
        for(int i=1;i<=n+1;i++)
        {
            st.insert(i);
        }
    }
    
    void upload(int video) {
        st.erase(video);
    }
    
    int longest() {
       return (*st.begin())-1;
    }
};