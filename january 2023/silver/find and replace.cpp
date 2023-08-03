#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string s1, s2; cin >> s1 >> s2;
        if (s1 == s2) { //not having this somehow ruined the last 5 test cases
            cout << 0 << endl;
            continue;
        }
        int n = s1.size();
        vector<int> paths(52, -1);
        vector<int> in(52, 0);
        bool works = true;
        set<int> cnt;
        for (int i = 0; i < n; i++) {
            int c1 = s1[i] - 'a' < 0 ? s1[i] - 'A' : s1[i] - 'a' + 26;
            int c2 = s2[i] - 'a' < 0 ? s2[i] - 'A' : s2[i] - 'a' + 26; //put numbers between 0-52
            cnt.insert(c2);
            if (paths[c1] != c2 && paths[c1] != -1) { //if it already goes to another one, then one letter maps to 2 letters, which is impossible
                works = false;
                break;
            } else {
                if (paths[c1] == -1) in[c2]++;
                paths[c1] = c2;
                
            }
        }

        if (cnt.size() == 52 || !works) { //if we have all 52 characters and s1 != s2 it is impossible
            cout << -1 << endl;
        } else {
            int out = 0;
            for (int i = 0; i < 52; i++)
                if (paths[i] != i && paths[i] != -1) out++; //add all edges to the count
            vector<int> vis(52, -1);
            for (int r = 0; r < 52; r++) { //now we find all pure loops (a - > b - > c with no other inputs into any node)
                if (vis[r] == -1) {
                    int a = r;
                    while (a != -1 && vis[a] == -1) {
                        vis[a] = r;
                        a = paths[a];
                    }
                    if (a != -1 && a != paths[a] && vis[a] == r) { //if it enters into this if statement it has found a loop
                        int s = a;
                        bool pure = false; //i kinda messed this up, if pure = false then it IS pure, and if pure = true it is NOT pure
                        do { //now we make sure the loop is pure
                            vis[a] = 2;
                            if (in[a] > 1) {
                                pure = true;
                            }
                            a = paths[a];
                        } while (a != s);
                        if (!pure) {
                            out++;
                        }
                    }
                }
            }
            cout << out << endl;
        }
    }
    return 0;
}
