#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k; cin >> n >> k;
    vector<long long> days;
    for (int i = 0; i < n; i++) {
        long long a; cin >> a;
        days.push_back(a);
    }
    long long extendFromLast; //numbers to up to 1e14
    long long lastDay = -1e15;
    long long totalCost = 0;
    for (int i = 0; i < n; i++) {
        //check if it's less money to extend the subscription from the last one or to create a new subscription
        //include current in calculating days
        extendFromLast = days[i] - lastDay;
        //calculate creating new subscription
        long long newSub = k + 1;
        totalCost += min(newSub, extendFromLast);
        lastDay = days[i];
    }
    cout << totalCost << endl;
    return 0;
}
