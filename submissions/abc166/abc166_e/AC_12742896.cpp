#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    VL v(n);
    VL add(n);
    VL sub(n);
    rep(i, n)
    {
        cin >> v[i];
        add[i] = v[i] + i;
        sub[i] = v[i] - i;
    }
    map<ll, ll> msub;
    rep(i, n)
    {
        msub[sub[i]]++;
    }
    ll ans = 0;
    rep(i, n)
    {
        msub[sub[i]]++;
        ans += msub[-add[i]];
    }
    cout << ans << endl;

    return 0;
}