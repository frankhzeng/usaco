#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string curr; cin >> curr;
        string out(n, '.');
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (curr[i] == 'G') {
                int r = 0;
                for (int j = i; j <= i+(k*2) && j < n; j++) {
                    if (curr[j] == 'G') r = j;
                }
                //cout << "G=======" << endl;
                //cout << r << endl;
                int l = i;
                //cout << i << endl;
                //put it in the first element between r-k to l+k
                //cout << "bounds: " << max(r-k, 0) << " " << min(l+k, n) << endl;
                for (int j = max(r-k, 0); j <= min(l+k, n); j++) {
                    if (out[j] == '.') {
                        out[j] = 'G';
                        cnt++;
                        //cout << "placed g at " << j << endl;
                        break;
                    }
                }
                i += (k*2);
                //cout << "g next: " << i+1 << endl;
            }
        }
        for (int i = 0; i < n; i++) {
            if (curr[i] == 'H') {
                int r = 0;
                for (int j = i; j <= i+(k*2) && j < n; j++) {
                    if (curr[j] == 'H') r = j;
                }
                //cout << "H=======" << endl;
                //cout << r << endl;
                int l = i;
                //cout << i << endl;
                //put it in the first element between r-k to l+k
                //cout << "bounds: " << max(r-k, 0) << " " << min(l+k, n) << endl;
                for (int j = max(r-k, 0); j <= min(l+k, n); j++) {
                    if (out[j] == '.') {
                        out[j] = 'H';
                        cnt++;
                        //cout << "placed h at " << j << endl;
                        break;
                    }
                }
                i += (k*2);
                //cout << "h next: " << i+1 << endl;

            }
        }
        cout << cnt << endl << out << endl;
    }

    return 0;
}
