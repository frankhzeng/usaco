#include <bits/stdc++.h>
using namespace std;

int main() {
    int inf = 2147483647;
    int n, m; cin >> n >> m;
    vector<vector<vector<int>>> flights(n+1, vector<vector<int>>());
    for (int i = 0; i < m; i++) {
        int c, r, d, s; cin >> c >> r >> d >> s;
        flights[c].push_back(vector<int>({r, d, s}));
    }
    for (int i = 1; i < n+1; i++) {
        int a; cin >> a;
        if (i == 1) continue;
        for (int j = 0; j < flights[i].size(); j++) {
            flights[i][j][0] -= a;
        }
        sort(flights[i].begin(), flights[i].end(), std::greater<>());
    }
    vector<int> out(n+1, inf);
    vector<int> vis(n+1, 0);
    out[1] = 0;
    
    queue<vector<int>> q;
    int ind = 0;
    
    for (vector<int> i : flights[1]) {
        q.push(i);
    }
    while (!q.empty()) {
        vector<int> curr = q.front();
        q.pop();
        int t1 = curr[0], a2 = curr[1], t2 = curr[2];
        out[a2] = min(out[a2], t2);
        
        while(vis[a2] < flights[a2].size() && flights[a2][vis[a2]][0] >= t2) {
            q.push(flights[a2][vis[a2]]);
            vis[a2]++;
        }
        
    }
    for (int i = 1; i < n+1; i++) {
        if (out[i] == inf) {
            cout << -1 << endl;
        } else {
            cout << out[i] << endl;
        }
    }
    return 0;
}
