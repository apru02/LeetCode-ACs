bool v(char a){
    a=tolower(a);
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
        return true;
        return false;

}
class Solution {
public:
    bool halvesAreAlike(string s) {
        int flag=0;
        for(int i=0;i<s.size();i++)
        {
            if(s.size()/2>i && v(s[i]))
                flag++;
            if(s.size()/2<=i && v(s[i]))
            flag--;
        }
        if(flag==0)return true;
        return false;
    }
};