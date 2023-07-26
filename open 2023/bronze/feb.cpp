#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; string s; cin >> n >> s;
    int mini = 0, maxi = 0;
    int i = 0;
    while (i < n) {
        if (s[i] == 'F') {
            i++; continue;
        }
        //not f
        int a = i+1;
        while(a < n && s[a] == 'F') a++;
        if (a >= n) break;
        int fsize = a - i - 1;
        if (s[a] == s[i]) {
            if (fsize%2==0) mini++;
            maxi+=fsize+1;
        } else {
            if (fsize%2==1) mini++;
            maxi += fsize;
        }
        i = a;
    }
    int bf = 0, ef = 0;
    while(bf < n && s[bf] == 'F') bf++;
    while(ef < n && s[n - 1 - ef] == 'F') ef++;
    
    if (bf == n) {
        mini = 0; maxi = n-1;
    } else {
        maxi += bf;
        maxi += ef;
    }
    vector<int> out;
    if (bf == 0 && ef == 0) {
        for (int i = mini; i <= maxi; i+=2) out.push_back(i);
    } else {
        for (int i = mini; i <= maxi; i++) out.push_back(i);
    }
    cout << out.size() << endl;
    for (int i : out) {
        cout << i << endl;
    }
    return 0;
}
