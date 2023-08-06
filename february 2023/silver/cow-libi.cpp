#include <bits/stdc++.h>
using namespace std;

bool can(vector<long long> a, vector<long long> b) {

    long long addedxy = (a[1] - b[1])*(a[1] - b[1]) + (a[2] - b[2])*(a[2] - b[2]);
    long long time = (a[0] - b[0]) * (a[0] - b[0]);

    return addedxy <= time;
}
int main() {

    long long g, n; cin >> g >> n;
    vector<vector<long long>> graze;
    for (long long i = 0; i < g; i++) {
        long long a, b, c; cin >> a >> b >> c;
        graze.push_back({c, a, b});
    }
    sort(graze.begin(), graze.end());

    long long out = 0;
    for (long long i = 0; i < n; i++) {
        long long x, y, t; cin >> x >> y >> t;
        vector<long long> curr({t, x, y});
        auto upper = upper_bound(graze.begin(), graze.end(), curr, [](vector<long long> a, vector<long long> b){return a[0] < b[0];});
        int upper2 = upper - graze.begin();
        upper2--;
        bool innocent = false;
        for (long long j = upper2; j <= upper2+1; j++) {
            if (0 <= j && j < g) {
                bool canreach = can(graze[j], curr);
                innocent = innocent || !canreach;
            }
        }

        out += innocent;
    }
    cout << out << endl;
    return 0;
}
