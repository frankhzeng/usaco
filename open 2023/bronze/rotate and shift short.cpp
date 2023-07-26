#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, t; cin >> n >> k >> t;
    vector<int> indices(k), out;
    for (int i = 0; i < k; i++) cin >> indices[i];
    indices.push_back(n);
    for (int i = 0; i < k; i++) for (int j = 0; j < indices[i+1] - indices[i]; j++) out.push_back(((j + (t % (indices[i+1] - indices[i]))) % (indices[i+1] - indices[i])) + indices[i]);
    for (int i = 0; i < out.size(); i++) {
        cout << out[(i+(n-(t%n))) % n];
        if (i+1 < out.size()) cout << " ";
    }
    return 0;
}
