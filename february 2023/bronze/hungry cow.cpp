#include <bits/stdc++.h>
using namespace std;
long long zero = 0;
int main() {
    long long n, t; cin >> n >> t;
    vector<long long> day, amount;
    for (int i = 0; i < n; i++) {
        long long d, a; cin >> d >> a;
        day.push_back(d);
        amount.push_back(a);
    }
    day.push_back(t+1);
    amount.push_back(0);
    long long last_day = day[0];
    long long stock = amount[0];
    long long out = 0;
    for (int i = 1; i <= n; i++) {
        out += day[i] - last_day;
        stock -= day[i] - last_day;
        if (stock < 0) out += stock;
        stock = max(stock, zero) + amount[i];
        last_day = day[i];
    }
    cout << out << endl;

    return 0;
}
