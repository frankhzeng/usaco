#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> rotate(vector<vector<char>> stamp, int n) {
    vector<vector<char>> temp(n, vector<char>(n));
    //loop through left-right upwards
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = stamp[n - j - 1][i];
        }
    }
    return temp;
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<char>> grid(n, vector<char>(n));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];
        int k; cin >> k;
        vector<vector<char>> stamp(k, vector<char>(k));
        for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) cin >> stamp[i][j];
        //cout << "================================" << endl;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) 
        //         cout << grid[i][j] << " ";
        //     cout << endl;
        // }
        // cout << endl;

        vector<vector<char>> stamped(n, vector<char>(n, '.'));
        for (int r = 0; r < 4; r++) { //rotations
            for (int i = 0; i < n - k + 1; i++) {
                for (int j = 0; j < n - k + 1; j++) {
                    bool validstamp = true;
                    //cout << i << " " << j << " =================" << endl;
                    for (int a = i; a < i+k; a++) {
                        for (int b = j; b < j+k; b++) {
                            //cout << "a, b" << " " << a << " " << b << endl;
                            if (stamp[a-i][b-j] == '*' && grid[a][b] == '.') {
                                validstamp = false;
                            }
                        }
                    }
                    //cout << "isvalid: " << validstamp << endl;
                    if (validstamp) {
                        for (int a = i; a < i+k; a++) {
                            for (int b = j; b < j+k; b++) {
                                if (stamp[a-i][b-j] == '*' && grid[a][b] == '*') {
                                    stamped[a][b] = '*';
                                }
                            }
                        }
                    }
                }
            }
            stamp = rotate(stamp, k);
        }
        bool works = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (stamped[i][j] != grid[i][j]) works = false;
            }
        }
        if (works) cout << "YES" << endl;
        if (!works) cout << "NO" << endl;
    }
    return 0;
}
