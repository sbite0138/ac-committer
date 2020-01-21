#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
int main(int argc, char const *argv[])
{
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i, h)
    {
        cin >> g[i];
    }
    rep(i, h + 2)
    {
        rep(j, w + 2)
        {
            if (j == 0 || j == w + 1 || i == 0 || i == h + 1)
            {
                cout << "#";
            }
            else
            {
                cout << g[i - 1][j - 1];
            }
        }

        cout << endl;
    }
    return 0;
}
