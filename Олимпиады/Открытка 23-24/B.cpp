#include <bits/stdc++.h>
//#include <bitset>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const int MAXN = 5e5;
vector<ll> st(MAXN * 4);
vector<ll> sp(MAXN * 4);
vector<ll> arr;

void apply(ll x, int v, int l, int r) {
    //cout << x << ' ' << v << ' ' << l << ' ' << r << '\n';
    sp[v] = x;
    //arr[l] = x;
    //Node curV; curV.v = x;
    //Node curV; curV.v = x;
    st[v] = x * (r - l);
    //cout << v << ' ' << st[v] << '\n';
}

/*Node merge(const Node& l, const Node& r) {
    Node res;
    res.v = l.v + r.v;
    return res;
}*/

void push(int v, int l, int r) {
    ll x = sp[v];
    if (x == 0) return;
    sp[v] = 0;
    int mid = l + (r - l) / 2;
    apply(x, 2 * v + 1, l, mid);
    apply(x, 2 * v + 2, mid, r);
}

void build (int v, int l, int r) {
    if (r - l == 1) {
        //Node curV;
        //curV.v = arr[l];
        st[v] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    //push(v, l, r);
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    st[v] = st[2 * v + 1] + st[2 * v + 2];
}

void update (int ql, int qr, ll x, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        return;
    } 
    if (ql <= l && r <= qr) {
        return apply(x, v, l, r);
    }
    int mid = l + (r - l) / 2;
    push(v, l, r);
    update(ql, qr, x, 2 * v + 1, l, mid);
    update(ql, qr, x, 2 * v + 2, mid, r);
    st[v] = st[2 * v + 1] + st[2 * v + 2];
}

ll get(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return st[v];
    }
    int mid = l + (r - l) / 2;
    push(v, l, r);
    return get(ql ,qr, 2 * v + 1, l, mid) + get(ql, qr, 2 * v + 2, mid, r);
}

void solve() { 
    int n; cin >> n;
    arr.resize((1 << n));
    for (int i = 0; i < (1 << n); i++) {
        cin >> arr[i];
    }
    build(0, 0, (1 << n));
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, k; ll x; cin >> l >> r >> k >> x;
            bitset<(32)> bitK(k);
            int cntK = 0;
            if (bitK.test(0) == 0) {
                for (int i = 0; i < (int)bitK.size(); i++) {
                    if (bitK.test(i) == 1) {
                        break;
                    }
                    cntK++;
                } 
            } else {
                for (int i = 0; i < (int)bitK.size(); i++) {
                    if (bitK.test(i) == 0) {
                        break;
                    }
                    cntK++;
                }
            }
            int per = (1 << cntK);

            //int a = l ^ k;
            //int f = r ^ k;
            //int a, b, c, d, e, f;
            if (bitK.test(0) == 0) {
                //ll res = 0;
                int a, b, c, d, e, f, g, h, i, j;
                //per = (1 << cntK);
                a = l ^ k;
                c = 0; d = -1;
                if (a % per == 0) {
                    if (a / per % 2 == 1) {
                        b = a + per - 1;
                        /*if (r - l >= per * 2) {
                            a -= per;
                        }*/
                        a -= per;
                    } else {
                        b = a + per - 1;
                    }
                } else {
                    if (a / per % 2 == 0) {
                        b = (a + per - 1) / per * per - 1;
                    } else {
                        b = (a + per - 1) / per * per - 1;
                        //int g, h;
                        d = b - per;
                        c = d - per + 1; 
                    }
                }
                if (b - a > r - l) {
                    //cout << get(a, b + 1, 0, 0, (1 << n)) << '\n';
                    update(a, b + 1, x, 0, 0, (1 << n));
                    continue;
                } else {
                    //res += get(a, b + 1, 0, 0, (1 << n));
                    update(a, b + 1, x, 0, 0, (1 << n));
                }
                //res += get(c, d + 1, 0, 0, (1 << n));
                update(c, d + 1, x, 0, 0, (1 << n));
                j = r ^ k;
                g = (1 << n)  + 1;
                h = (1 << n);
                if (j % per == 0) {
                    if (j / per % 2 == 1) {
                        i = j;
                    } else {
                        i = j;
                        g = i + per;
                        h = g + per - 1;
                    }
                } else {
                    i = j / per * per;
                    if (j / per % 2 == 0){
                        g = i + per;
                        h = g + per - 1;
                    }
                }
                //res += get(g, h + 1, 0, 0, (1 << n));
                update(g, h + 1, x, 0, 0, (1 << n));
                //res += get(i, j + 1, 0, 0, (1 << n));
                update(i, j + 1, x, 0, 0, (1 << n));

                if (c != 0) {
                    if (g != (1 << n) + 1) {
                        if (b - a + d - c + h - g + j - i + 4 == r - l + 1) {
                            //cout << res << '\n';
                            continue;
                        } 
                    } else {
                        if (b - a + d - c + j - i + 3 == r - l + 1) {
                            //cout << res << '\n';
                            continue;
                        }
                    }
                    //cout << res << '\n';
                    //continue;
                } else {
                    if (g != (1 << n) + 1) {
                        if (b - a + h - g + j - i + 3 == r - l + 1) {
                            //cout << res << '\n';
                            continue;
                        } 
                    } else {
                        if (b - a + j - i + 2 == r - l + 1) {
                            //cout << res << '\n';
                            continue;
                        }
                    }
                }         
                if (c != 0) {
                    e = d + per + 1;
                    if (g != (1 << n) + 1) {
                        f = g - 2 * per;
                    } else {
                        f = i - 2 * per;
                    }
                } else {
                    e = b + per + 1;
                    if (g != (1 << n) + 1) {
                        f = g - 2 * per;
                    } else {
                        f = i - 2 * per;
                    }
                }
                //cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << '\n';
                //res += get(e, f + 1, 0, 0, (1 << n));
                update(e, f + 1, x, 0, 0, (1 << n));
                //cout << res << '\n';
            } else {
                int a, b, c, d, e, f;
                //per = (1 << cntK);
                a = l ^ k;
                if (a % per == 0) {
                    b = a;
                } else {
                    b = a / per * per;
                }
                c = b + per;
                f = r ^ k;
                if (f % per == 0) {
                    e = f + per - 1;
                } else {
                    e = (f + per - 1) / per * per - 1;
                }
                d = e - per;
                //cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
                if (a - b >= r - l) {
                    //cout << get(b, a + 1, 0, 0, (1 << n)) << '\n';
                    update(b, a + 1, x, 0, 0, (1 << n));
                    continue;
                } 
                if (a - b + 1 + e - f + 1 < r - l + 1) {
                    update(b, a + 1, x, 0, 0, (1 << n));
                    update(d, c + 1, x, 0, 0, (1 << n));
                    update(f, e + 1, x, 0, 0, (1 << n));
                    //cout << get(b, a + 1, 0, 0, (1 << n)) + get(d, c + 1, 0, 0, (1 << n)) + get(f, e + 1, 0, 0, (1 << n)) << '\n';
                }  else {
                    update(b, a + 1, x, 0, 0, (1 << n));
                    update(f, e + 1, x, 0, 0, (1 << n));
                    //cout << get(b, a + 1, 0, 0, (1 << n)) + get(f, e + 1, 0, 0, (1 << n)) << '\n';
                }
                //cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
                /*for (int i = 0; i < (1 << n); i++) {
                    cout << arr[i] << ' ';
                }*/
                //for (int i = 7; i < 15; i++) cout << st[i] << ' ';
                //cout << '\n';
            }

            //update(fEl, a + 1, v, 0, 0, (1 << n));
            //update(b, c + 1, v, 0, 0, (1 << n));
            //update(d, lEl + 1, v, 0, 0, (1 << n));
            //cout << "aboba\n";
            //cout << per << ' ' << fEl << ' ' << lEl << ' ' << a << ' ' << b << ' ' << c << ' ' << d << '\n';
        } else {
            int l, r, k; cin >> l >> r >> k;
            bitset<(32)> bitK(k);
            int cntK = 0;
            if (bitK.test(0) == 0) {
                for (int i = 0; i < (int)bitK.size(); i++) {
                    if (bitK.test(i) == 1) {
                        break;
                    }
                    cntK++;
                } 
            } else {
                for (int i = 0; i < (int)bitK.size(); i++) {
                    if (bitK.test(i) == 0) {
                        break;
                    }
                    cntK++;
                }
            }
            int per = (1 << cntK);

            //int a = l ^ k;
            //int f = r ^ k;
            //int a, b, c, d, e, f;
            if (bitK.test(0) == 0) {
                ll res = 0;
                int a, b, c, d, e, f, g, h, i, j;
                //per = (1 << cntK);
                a = l ^ k;
                c = 0; d = -1;
                if (a % per == 0) {
                    if (a / per % 2 == 1) {
                        b = a + per - 1;
                        /*if (r - l >= per * 2) {
                            a -= per;
                        }*/
                        a -= per;
                    } else {
                        b = a + per - 1;
                    }
                } else {
                    if (a / per % 2 == 0) {
                        b = (a + per - 1) / per * per - 1;
                    } else {
                        b = (a + per - 1) / per * per - 1;
                        //int g, h;
                        d = b - per;
                        c = d - per + 1; 
                    }
                }
                if (b - a > r - l) {
                    cout << get(a, b + 1, 0, 0, (1 << n)) << '\n';
                    continue;
                } else {
                    res += get(a, b + 1, 0, 0, (1 << n));
                }
                res += get(c, d + 1, 0, 0, (1 << n));
                j = r ^ k;
                g = (1 << n)  + 1;
                h = (1 << n);
                if (j % per == 0) {
                    if (j / per % 2 == 1) {
                        i = j;
                    } else {
                        i = j;
                        g = i + per;
                        h = g + per - 1;
                    }
                } else {
                    i = j / per * per;
                    if (j / per % 2 == 0){
                        g = i + per;
                        h = g + per - 1;
                    }
                }
                res += get(g, h + 1, 0, 0, (1 << n));
                res += get(i, j + 1, 0, 0, (1 << n));

                if (c != 0) {
                    if (g != (1 << n) + 1) {
                        if (b - a + d - c + h - g + j - i + 4 == r - l + 1) {
                            cout << res << '\n';
                            continue;
                        } 
                    } else {
                        if (b - a + d - c + j - i + 3 == r - l + 1) {
                            cout << res << '\n';
                            continue;
                        }
                    }
                    //cout << res << '\n';
                    //continue;
                } else {
                    if (g != (1 << n) + 1) {
                        if (b - a + h - g + j - i + 3 == r - l + 1) {
                            cout << res << '\n';
                            continue;
                        } 
                    } else {
                        if (b - a + j - i + 2 == r - l + 1) {
                            cout << res << '\n';
                            continue;
                        }
                    }
                }         
                if (c != 0) {
                    e = d + per + 1;
                    if (g != (1 << n) + 1) {
                        f = g - 2 * per;
                    } else {
                        f = i - 2 * per;
                    }
                } else {
                    e = b + per + 1;
                    if (g != (1 << n) + 1) {
                        f = g - 2 * per;
                    } else {
                        f = i - 2 * per;
                    }
                }
                //cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << '\n';
                res += get(e, f + 1, 0, 0, (1 << n));
                cout << res << '\n';
            } else {
                int a, b, c, d, e, f;
                //per = (1 << cntK);
                a = l ^ k;
                if (a % per == 0) {
                    b = a;
                } else {
                    b = a / per * per;
                }
                c = b + per;
                f = r ^ k;
                if (f % per == 0) {
                    e = f + per - 1;
                } else {
                    e = (f + per - 1) / per * per - 1;
                }
                d = e - per;
                //cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
                if (a - b >= r - l) {
                    cout << get(b, a + 1, 0, 0, (1 << n)) << '\n';
                    continue;
                } 
                if (a - b + 1 + e - f + 1 < r - l + 1) {
                    cout << get(b, a + 1, 0, 0, (1 << n)) + get(d, c + 1, 0, 0, (1 << n)) + get(f, e + 1, 0, 0, (1 << n)) << '\n';
                }  else {
                    cout << get(b, a + 1, 0, 0, (1 << n)) + get(f, e + 1, 0, 0, (1 << n)) << '\n';
                }
            }
            //int b = (a + per - 1) / per * per;
            
            /*int fEl = l ^ k;
            int lEl = r ^ k;
            int a = (fEl + per - 1) / per * per;
            // fEl - a -- update
            int b = a + per;
            int c = lEl / per * per;
            // b - c -- update
            int d = (lEl + per - 1) / per * per - per;*/

            //cout << per << ". " << fEl << ' ' << a << "; " << b << ' ' << c << "; " << d << ' ' << lEl << '\n';

            /*ll res = 0;
            res += get(fEl, a + 1, 0, 0, (1 << n));
            res += get(b, c + 1, 0, 0, (1 << n));
            res += get(d, lEl + 1, 0, 0, (1 << n));
            cout << res << '\n';*/
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}