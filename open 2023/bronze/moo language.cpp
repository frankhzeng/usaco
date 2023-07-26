#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, c, p; cin >> n >> c >> p;
        vector<string> nouns, trans, intrans, conj;
        for (int i = 0; i < n; i++) {
            string a, b; cin >> a >> b;
            if (b == "noun") nouns.push_back(a);
            else if (b == "transitive-verb") trans.push_back(a);
            else if (b == "intransitive-verb") intrans.push_back(a);
            else conj.push_back(a);
        }
        int out = 0;
        int t1, t2, com, end;
        for (int type1 = 0; type1 <= intrans.size(); type1++) {
            int ncnt = nouns.size(), ccnt = conj.size();
            int periods = p, commas = c;
            int curr = 0;
            //create type1
            ncnt -= type1;
            curr += 2*type1;
            if (ncnt < 0) continue;
            
            //create type2
            int type2 = min(min((int)trans.size(), ncnt/2), 2 * min(ccnt, periods) + max(0, periods - ccnt));
            curr += 3 * type2;
            ncnt -= 2 * type2;
            
            int tot = type1+type2;
            int pcomb = min(tot/2, ccnt);
            curr += pcomb;
            periods -= tot - pcomb;
            if(periods < 0) continue;
            int endc = 0;
            if (type2 >= 1) {
                endc = min(commas, ncnt);
                curr += endc;
            }
            
            if (curr > out) {
                out = curr;
                t1 = type1;
                t2 = type2;
                com = pcomb;
                end = endc;
            }
        }
        cout << out << endl;
        if (out == 0) {
            cout << endl;
            continue;
        }
        
        vector<vector<string>> sent;
        for (int i = 0; i < t1; i++) {
            sent.push_back({nouns[nouns.size()-1], intrans[intrans.size()-1]});
            nouns.pop_back(); intrans.pop_back();
        }
        for (int i = 0; i < t2; i++) {
            sent.push_back({nouns[nouns.size()-1], trans[trans.size()-1], nouns[nouns.size()-2]});
            nouns.pop_back(); nouns.pop_back(); trans.pop_back();
        }
        string ans = "";
        for (int i = 0; i < sent.size(); i++) {
            for (string s: sent[i]) ans += s + " ";
            if (com > 0 && i % 2 == 0) {
                ans += conj[conj.size()-1] + " ";
                conj.pop_back();
                com--;
            } else {
                ans.pop_back();
                ans += ". ";
            }
        }
        ans.pop_back();
        if (end > 0) {
            ans.pop_back();
            for (int i = 0; i < end; i++) {
                ans += ", " + nouns[nouns.size()-1];
                nouns.pop_back();
            }
            ans += ".";
        }
        cout << ans << endl;
    }

    return 0;
}
