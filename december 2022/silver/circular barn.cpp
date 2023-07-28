#include <bits/stdc++.h>
using namespace std;
int maxi = 5e6+5;
vector<int> comp(maxi, false);
vector<int> mini(maxi, 0);
vector<int> last({2, 1, 2, 3});
int main() {
    mini[1] = 1;
    //generate all primes (alg is called sieve of eratosthenes)
    for (int i = 2; i < maxi; i++) {
        if (!comp[i]) {
            for (int j = i; j < maxi; j+=i) {
                comp[j] = true;
            }
            last[i%4] = i;
        }
        mini[i] = (i - last[i%4]) / 2 + 1;
    }
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int out = maxi;
        for (int i = 0; i < n; i++) {
            int curr; cin >> curr;
            if (mini[curr] / 2 < out / 2) out = mini[curr];
        }
        if (out % 2 == 1) cout << "Farmer John" << endl;
        else cout << "Farmer Nhoj" << endl;
    }
    return 0;
}
