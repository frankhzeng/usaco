#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> connections;
vector<ll> vals;
ll n;
vector<pair<pair<ll, ll>, ll>> moves;
vector<bool> vis;
vector<ll> sub;
ll find(ll ind) {
    if (vis[ind]) return 0;
    vis[ind] = true;
    ll sum = vals[ind];
    for (ll i : connections[ind]) {
        ll needed = find(i);
        sum += needed;
    }
    sub[ind] = sum;
    return sum;
}
void dfs(ll ind) {
    vis[ind] = true;
    for (ll i : connections[ind]) {
        if (!vis[i]) {
            if (sub[i] >= 0) dfs(i);
            if (sub[i] > 0) moves.push_back({{i, ind}, sub[i]});
        }
    }
    for (ll i : connections[ind]) {
        if (!vis[i]) {
            if (sub[i] < 0) {
                moves.push_back({{ind, i}, -sub[i]});
                dfs(i);
            }
        }
    }
}
int main() {
    cin >> n;
    vis.resize(n, false);
    sub.resize(n);
    connections = vector<vector<ll>>(n, vector<ll>());
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        sum += a;
        vals.push_back(a);
    }
    sum /= n;
    for (ll i = 0; i < n; i++) vals[i]-=sum;
    for (ll i = 0; i < n-1; i++) {
        ll a, b; cin >> a >> b;
        a--; b--;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    find(0);

    vis = vector<bool>(n, false);
    dfs(0);
    cout << moves.size() << endl;
    for (ll i = 0; i < moves.size(); i++) {
        cout << moves[i].first.first+1 << " " << moves[i].first.second+1 << " " << moves[i].second << endl;
    }
    
    return 0;
}
