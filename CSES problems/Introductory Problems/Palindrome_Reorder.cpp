#include <bits/stdc++.h>

using namespace std;

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    string s; cin >> s;
    map<char, int> Symb_Cnt;
    for (auto c : s) {
        Symb_Cnt[c]++;
    }
    int badCnt = 0;
    for (auto p : Symb_Cnt) {
        if (p.second%2 == 1) {
            badCnt++;
        }
    }
    if (badCnt > 1) {
        cout << "NO SOLUTION";
        return 0;
    }
    vector<char> pal(s.size());
    int l = 0, r = s.size() - 1;
    for (auto gr : Symb_Cnt) {
        //cout << gr.first << ' ' << gr.second << '\n';
        if (gr.second % 2 == 0) {
            while (gr.second > 0) {
                pal[l++] = gr.first;
                pal[r--] = gr.first;
                gr.second -= 2;
            }
        } else {
            pal[l + (r - l) / 2] = gr.first;
            gr.second--;
            while (gr.second > 0) {
                pal[l++] = gr.first;
                pal[r--] = gr.first;
                gr.second -= 2;
            }
        }
    }
    for (auto c : pal) {
        cout << c;
    }

    return 0;
}