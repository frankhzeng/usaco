#include <bits/stdc++.h>
using namespace std;
 int main() {
    string s; cin >> s;
    long long out = 0;
    vector<long long> v(7, 0);
    long long l = s.size();
    string b = "bessie";
    for (long long i = 0; i < s.size(); i++) {
        v[0]++;
        for (long long j = 5; j >= 0; j--) {
            if (s[i] == b[j]) {
                v[j+1] += v[j];
                v[j] = 0;
            }
        }
        out += (v[6] * l);
        v[0] += v[6];
        v[6] = 0;
        l--;
    }
    cout << out << endl;

    return 0;
}
