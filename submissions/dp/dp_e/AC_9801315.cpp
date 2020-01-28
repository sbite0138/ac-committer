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
const ll INF = (1ll << 60);

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(101010, INF));
    dp[0][0] = 0;
    rep(i, n)
    {
        dp[i + 1] = dp[i];
        rep(j, 101010)
        {

            if (j - v[i] < 0)
            {
                continue;
            }
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - v[i]] + w[i]);
        }
    }
    int ans = 0;
    rep(i, 101010)
    {
        if (dp[n][i] <= m)
        {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
