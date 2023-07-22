#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        //n is string length
        //m is amount of strings
        vector<string> inputs;
        vector<bool> outputs;
        for (int i = 0; i < m; i++) {
            string s; bool out;
            cin >> s >> out;
            inputs.push_back(s);
            outputs.push_back(out);
        }
        bool finished = false;
        //input/output done
        vector<bool> disq(m, false);
        //generate all possible if statements
        while(true) {
            bool foundIf = false;
            for (int ind = 0; ind < n; ind++) {
                if (finished) break;
                //loop through string
                for (int val = 0; val <= 1; val++) {
                    if (finished) break;
                    //which value the index of the string should be
                    for (int output = 0; output <= 1; output++) {
                        if (finished) break;
                        //which value the output should be
                        //go through all strings
                        bool works = false;
                        for (int i = 0; i < m; i++) {
                            if (disq[i]) continue;
                            if (inputs[i][ind] == '0' + val) {
                                //input is correct, check output
                                if (outputs[i] == output) {
                                    works = true;
                                    //there's one thing that works
                                }
                                if (outputs[i] != output) {
                                    works = false;
                                    break;
                                }
                            }
                        }
                        // cout << "ind, val, output, works:" << endl;
                        // cout << ind << "      " << val << "    " << output << "              " << works << endl;
                        if (works) {
                            foundIf = true;
                            int sum = 0;
                            for (int i = 0; i < m; i++) {
                                sum += disq[i];
                                if (inputs[i][ind] == '0' + val) {
                                    disq[i] = true;
                                }
                            }
                            if (sum == m) {
                                finished = true;
                            }
                        }
                        // for (int i = 0; i < m; i++) {
                        //     cout << disq[i] << " ";
                        // }
                        // cout << endl;
                        // cout << "=====================" << endl;
                    }
                }
            }
            if (!foundIf) {
                break;
            }
        }
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += disq[i];
        }
        if (sum == m) {
            cout << "OK" << endl;
        } else {
            cout << "LIE" << endl;
        }
    }

    return 0;
}