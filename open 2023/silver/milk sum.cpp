#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n; cin >> n;
    vector<long long> arr;
    for (long long i = 0; i < n; i++) {
        long long a; cin >> a;
        arr.push_back(a);
    }
    vector<long long> s(n);
    iota(s.begin(), s.end(), 0);
    sort(s.begin(), s.end(), [&](long long a, long long b){ return arr[a] < arr[b];});
    //if a 1 is at index 4 in s[], then that means arr[1] went to arr[4] after sorting
    vector<long long> pos(n, -1);
    for (long long i = 0; i < n; i++) pos[s[i]] = i;
    sort(arr.begin(), arr.end());
    long long sum = 0;
    long long initial = 0;
    vector<long long> psum(n+1, 0);
    for (long long i = 0; i < n; i++) {
        sum += arr[i];
        initial += (i+1) * arr[i];
        psum[i+1] = sum;
    }
    long long q; cin >> q;
    while (q--) {
        long long i, v; cin >> i >> v;
        i--;
        i = pos[i];
        long long out = initial;
        long long i2 = lower_bound(arr.begin(), arr.end(), v) - arr.begin();
        if (v > arr[i]) i2--; //if we're switching it out for a larger one you have to decrement all the indexes between i and i2
        out -= (i+1) * arr[i];
        out += (i2+1) * v;
        if (i2 >= i) out -= psum[i2+1] - psum[i+1];
        else out += psum[i] - psum[i2];
        cout << out << endl;
    }
    return 0;
}
