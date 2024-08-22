#define ui unsigned int
class Solution {
public:
    int findComplement(int num) {
        ui j = 1<<(int)(log2(num));

        // cout<<j<<endl;
        return num^(j*2 - 1);
    }
};