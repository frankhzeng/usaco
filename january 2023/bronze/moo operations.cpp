#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        if (s.size() <= 2) { //can't add letters, it's automatically impossible
            cout << "-1" << endl;
            continue;
        }
        int mini = 3;
        for (int i = 1; i < s.size()-1; i++) {
            if (s[i] == 'O') {
                //cout << "o found" << endl;
                if (s[i-1] == 'M' && s[i+1] == 'O') { //all these if statements encompass the only possible configurations that can turn into "MOO"
                    mini = min(mini, 0);
                    break; //smallest possible, why go throuhg the rest
                }
                if (s[i-1] != 'M' && s[i+1] != 'O') {
                    mini = min(mini, 2);
                }
                if (s[i-1] == 'M' || s[i+1] == 'O') {
                    mini = min(mini, 1);
                    continue;
                }
            }
        }
        if (mini == 3) { //if this is still 3 then you can't turn anything into "MOO"
            cout << -1 << endl;
            continue;
        }
        cout << mini + s.size() - 3 << endl; //mini has been set to the # of moves the 3 letters need to turn into MOO (0, 1, 2) so you just need to remove all the other letters
    }
    return 0;
}
