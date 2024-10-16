class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        if(a){
            pq.push({a,'a'});
        }
        if(b){
            pq.push({b,'b'});
        }
        if(c){
            pq.push({c,'c'});
        }
        string ans="";
        char last='e';
        while(!pq.empty()){
            int maxi=pq.top().first;
            char c=pq.top().second;
            pq.pop();
            if(last!=c){
                last=c;
                int x=min(2,maxi);
                maxi-=x;
                while(x--){
                    ans.push_back(c);
                }
                if(maxi){
                    pq.push({maxi,c});
                }
            }
            else{
                if(pq.empty()){
                    return ans;
                }
                int newMaxi=pq.top().first;
                char newC=pq.top().second;
                pq.pop();
                last=newC;
                int x=min(1,newMaxi);
                newMaxi-=x;
                while(x--){
                    ans.push_back(newC);
                }
                if(newMaxi){
                    pq.push({newMaxi,newC});
                }
                if(maxi){
                    pq.push({maxi,c});
                }
            }
        }
        return ans;
    }
};