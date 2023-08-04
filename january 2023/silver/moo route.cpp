#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    vals.push_back(0);
    int i = 0;
    string out = "";
    while(!(i == 0 && vals[i] == 0)) {
        while (vals[i] > 0 && i < n) { // go right
            vals[i]--; i++;
            out += "R";
        }

        while (i > 0 && (vals[i-1] > 1 || vals[i] == 0)) { //go left
            //i > 0 to keep in bounds
            //vals[i-1] > 1 checks if the index you're going to is 1, in which case if there's any indexes to the right that should be travelled to but aren't you need to go right again, if not you can go left
            i--; vals[i]--;
            out += "L";
        }

    }
    cout << out << endl;
    return 0;
}
