class RandomizedSet {
public:
    unordered_map<int,int> mp; //<num , index at which num is present>
    vector<int> ans;
    RandomizedSet() 
    {
        ios_base::sync_with_stdio(false);    
    }
    
    bool insert(int val) 
    {
        if(mp.find(val)!=mp.end())
        {
            return false;
        }    
        ans.push_back(val);
        mp[val]=ans.size()-1;
        return true;
    }
    
    bool remove(int val) 
    {
        if(mp.find(val)==mp.end())
        {
            return false;
        }    
        int index = mp[val]; 
        int last_ele = ans.back();

        mp[last_ele] = index;
        swap(ans[index],ans[ans.size()-1]); 

        ans.pop_back(); 
        mp.erase(val);
        return true;
    }
    
    int getRandom() 
    {
        return ans[rand()%ans.size()];    
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */