#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        vals.push_back(a);
        vals[i]--;
    }
    int fG, lG, fH, lH;
    //get first and last of each
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') {
            fG = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'G') {
            lG = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'H') {
            fH = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'H') {
            lH = i;
            break;
        }
    }
    int out = 0;
    if (vals[fG] >= lG) {
        //g is a leader
        for (int i = 0; i < fG; i++) {
            if (i == fH) continue; //we will cover this later
            if (s[i] == 'H') {
                if (vals[i] >= fG) {
                    out++;
                }
            }
        }
    }
    if (vals[fH] >= lH) {
        for (int i = 0; i < fH; i++) {
            if (i == fG) continue; //we will cover this later
            if (s[i] == 'G') {
                if (vals[i] >= fH) {
                    out++;
                }
            }
        }
    }
    if ((vals[fG] >= lG || (fG <= fH && vals[fG] >= fH)) && (vals[fH] >= lH || (fH <= fG && vals[fH] >= fG))) { //wow we covered it
        out++;
    }

    cout << out << endl;
    return 0;
}
