#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, n; cin >> c >> n;
    
    vector<int> t(n);
    queue<int> q;
    vector<int> d(1 << c, -1);
    for (int i = 0; i < n; i++) {
        string a; cin >> a;
        replace(a.begin(), a.end(), 'G', '0');
        replace(a.begin(), a.end(), 'H', '1');
        int dec = stoi(a, nullptr, 2);
        t[i] = dec;
        q.push(dec);
        d[t[i]] = 0;
    }
    
    while(!q.empty()) {
        int m = q.front(); q.pop();
        for (int i = 0; i < c; i++) {
            int nm = m ^ (1 << i);
            if (d[nm] == -1) {
                d[nm] = d[m] + 1;
                q.push(nm);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << c - d[((1 << c) - 1) ^ t[i]] << endl;
    }

    return 0;
}
