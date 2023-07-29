#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>());
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int a; cin >> a;
            v[i].push_back(a);
        }
    }

    vector<int> out(n, 0);
    for (int i = n-2; i >= 0; i--) {
        out[i] = out[i+1] + v[i][1];
        int maxi = -1e9-1, mini = 1e9+1;
        bool works = true;
        for (int j = i; j < n; j++) {
            maxi = max(maxi, out[j]);
            mini = min(mini, out[j]);
            if (maxi - mini != v[i][j-i]) {
                works = false;
                break;
            }
        }
        if (!works) out[i] = out[i+1] - v[i][1];
    }
    for (int i = 0; i < out.size(); i++) {
        cout << out[i];
        if (i < out.size()-1) cout << " ";
    }
    return 0;
}
