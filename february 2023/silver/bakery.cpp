#include <bits/stdc++.h>
using namespace std;
long long n, X, Y;
vector<long long> A, B, C;
long long one = 1;
bool check(long long w) {
    long long lx = max(one, X-w); long long hx = min(X+Y - w - 1, X);
    for (long long i = 0; i < n; i++) {
        long long a = A[i], b = B[i], c = C[i], d = X + Y - w;
        if (b > a) {
            lx = max(lx, (-c + b * d + (b - a - 1)) / (b-a));
        } else if (a > b) {
            hx = min(hx, (c - b * d) / (a - b));
        } else {
            if (a * d > c) {
                return false;
            }
        }
    }
    return lx <= hx;
}
int main() {
    long long t; cin >> t;
    while(t--) {
        cin >> n >> X >> Y;
        A = vector<long long>(n);
        B = vector<long long>(n);
        C = vector<long long>(n);
        for (long long i = 0; i < n; i++) {
            cin >> A[i] >> B[i] >> C[i];
        }
        
        long long l = 0, r = (X+Y-2);
        
        while (r > l) {
            long long mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << endl;
    }


    return 0;
}
