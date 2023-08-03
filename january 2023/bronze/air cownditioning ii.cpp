#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> cstart, c_end, ctemp;
vector<int> astart, aend, atemp, acost;

string binary(int n) { //convert it to binary, each bit in the binary number is an on/off switch for that particular air conditioner
    // Size of an integer is assumed to be 10 bits
    string out = "";
    for (int i = 10; i >= 0; i--) {
        int k = n >> i;
        if (k & 1) out += "1";
        else out += "0";
    }
    return out;
}
int calculate(string state) {
    vector<int> temps(101, 0);
    int tcost = 0;
    for (int i = 0; i < state.size(); i++) {
        if (state[i] == '1') {
            tcost += acost[i];
            temps[astart[i]] += atemp[i];
            temps[aend[i]] -= atemp[i]; //this method is probably unnecessary and is just for faster runtime
            //basically instead of going through all the values and increasing them by a set amount you just save the distances between each value
            //so if the array is [0, 1, 2, 3] it would translate to [0, 1, 3, 6]
            //since it's only within a range you put a negative of any positive value u put in somewhere
            //so if you put a 1 in like this [0, 0, 1, 0, 0, 0]
            //you put in a -1 later so it'll go back to 0
            //[0, 0, 1, 0, 0, -1]
            //and it'll turn into this array
            //[0, 0, 1, 1, 1, 0]
        }
    }
    vector<int> utemps(101, 0);
    int curr = 0;
    for (int i = 0; i < temps.size(); i++) { //convert temps[] into an actual array of numbers and not distances between consecutive elements
        curr += temps[i];
        utemps[i] = curr;
    }

    bool works = true; //this loop and the one under utemps[] can probably be put into the same loop
    for (int i = 0; i < n; i++) {
        for (int j = cstart[i]; j < c_end[i]; j++) {
            if (utemps[j] < ctemp[i]) {
                works = false;
            }
        }
    }
    if (works) return tcost;
    if (!works) return -1; //the if on this line is unnecessary but compiler didn't complain so
}
int main() {
    //input
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--;
        cstart.push_back(a);
        c_end.push_back(b);
        ctemp.push_back(c);
    }
    for (int i = 0; i < m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--;
        astart.push_back(a);
        aend.push_back(b);
        atemp.push_back(c);
        acost.push_back(d);
    }
    //count up from 1 to 2^m and convert to binary, use this as on/off for conditioners
    int mini = 2147483647; //i need a better number to initiate this as
    for (int i = 0; i < pow(2, m); i++) {
        string b = binary(i);
        string state = b.substr(b.size() - m); //generate state
        int cost = calculate(state);
        if (cost != -1) {
            mini = min(mini, cost); //cost == -1 when it doesn't work
        }
    }
    cout << mini << endl;
    return 0;
}
