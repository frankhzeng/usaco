#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> directions;
    vector<int> vertical, horizontal;
    for (int i = 0; i < n; i++) { //input
        string a; int c; cin >> a >> c;
        directions.push_back(a);
        vertical.push_back(c);
    }
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        horizontal.push_back(c);
    }
    
    vector<vector<int>> v(n+1, vector<int>(n+1, 1)); //includes the spaces that have scores
    for (int i = 0; i < n; i++) {
        v[i][n]--; v[n][i]--;
    }
    //keep track of how many reach the current square
    int out1 = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == n) {
                //horizontal
                out1 += horizontal[j] * v[i][j];
            } else if (j == n) {
                //veritcal
                out1 += vertical[i] * v[i][j];
            } else if (directions[i][j] == 'R') {
                v[i][j+1] += v[i][j];
            } else {
                v[i+1][j] += v[i][j];
            }
        }   
    }

    cout << out1 << endl;
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y; x--; y--;
        //go through current path and subtract curr
        int curr = v[x][y];
        int x1 = x, y1 = y;
        while(x1 <= n+1 && y1 <= n+1) {//you physically can't subtract x and y, so don't check for x < 0 or y < 0
            if (x1 != n && y1 != n)
                if (directions[x1][y1] == 'R') y1++;
                else x1++;
            else break;
            v[x1][y1] -= curr;
        }
        //updated original
        if (directions[x][y] == 'R') directions[x][y] = 'D';
        else directions[x][y] = 'R';
        x1 = x; y1 = y;
        while(x1 <= n+1 && y1 <= n+1) {//you physically can't subtract x and y, so don't check for x < 0 or y < 0
            if (x1 != n && y1 != n)
                if (directions[x1][y1] == 'R') y1++;
                else x1++;
            else break;
            v[x1][y1] += curr;
        }
        int out = 0;
        //evaluate
        for (int i = 0; i < n; i++) {
            out += v[i][n] * vertical[i];
            out += v[n][i] * horizontal[i];
        }
        cout << out << endl;
    }

    return 0;
}