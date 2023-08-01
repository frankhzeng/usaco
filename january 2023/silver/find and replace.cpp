#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string s1, s2; cin >> s1 >> s2;
	if (s1 == s2) {
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
            int c2 = s2[i] - 'a' < 0 ? s2[i] - 'A' : s2[i] - 'a' + 26;
            cnt.insert(c2);
            if (paths[c1] != c2 && paths[c1] != -1) {
                works = false;
                break;
            } else {
                if (paths[c1] == -1) in[c2]++;
                paths[c1] = c2;
                
            }
        }

        if (cnt.size() == 52 || !works) {
            cout << -1 << endl;
        } else {
            int out = 0;
            for (int i = 0; i < 52; i++)
                if (paths[i] != i && paths[i] != -1) out++;
            vector<int> vis(52, -1);
            for (int r = 0; r < 52; r++) {
                if (vis[r] == -1) {
                    int a = r;
                    while (a != -1 && vis[a] == -1) {
                        vis[a] = r;
                        a = paths[a];
                    }
                    if (a != -1 && a != paths[a] && vis[a] == r) {
                        int s = a;
                        bool pure = false;
                        do {
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
