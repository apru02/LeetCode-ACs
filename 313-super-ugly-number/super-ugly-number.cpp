typedef long long ll;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<ll> pos(k, 0), res(n);
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            ll temp = 4e10;
            for (int j = 0; j < k; j++) 
                temp = min(temp, res[pos[j]] * primes[j]);
            for (int j = 0; j < k; j++)
                pos[j] += temp == res[pos[j]] * primes[j];
            res[i] = temp;
        }
        return res[n - 1];
    }
};