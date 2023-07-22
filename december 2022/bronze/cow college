#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    pair<long long, long long> maxi = {0, 0};
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (v[i] * (v.size() - i) > maxi.first) {
            maxi.first = v[i] * (v.size()-i);
            maxi.second = v[i];
        }
    }
    cout << maxi.first << " " << maxi.second << endl;
    return 0;
}
