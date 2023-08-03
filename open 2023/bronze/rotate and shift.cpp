#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, t; cin >> n >> k >> t;
    vector<int> indices;
    for (int i = 0; i < k; i++) {
        int a; cin >> a;
        indices.push_back(a);
    }
    indices.push_back(n); //so we cover the last element
    vector<int> out;
    for (int i = 0; i < k; i++) {
        int offset = t % (indices[i+1] - indices[i]); //start value (if we wanna loop through 6, 7, 8, 9, then this value is 6)
        for (int j = 0; j < indices[i+1] - indices[i]; j++) {

            out.push_back(((j + offset) % (indices[i+1] - indices[i])) + indices[i]);
        }
    }
    int start = n-(t%n);
    for (int i = 0; i < out.size(); i++) { //print in a way that it'll cover the rotation we did to use this solution
        cout << out[(i+start) % n];
        if (i+1 < out.size()) cout << " ";
    }
    return 0;
}
