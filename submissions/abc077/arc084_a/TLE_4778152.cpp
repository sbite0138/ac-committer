#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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
template <typename T>
void vshow(vector<T> v)
{
    rep(i, v.size())
    {
        cerr << v[i] << (i < v.size() - 1 ? "," : "");
    }
    cerr << endl;
}

int binarySearch(vector<int> v, int t)
{
    int r = v.size();
    int l = -1;
    while (l + 1 != r)
    {
        int med = (r + l) / 2;
        if (v[med] > t)
        {
            r = med;
        }
        else
        {
            l = med;
        }
    }
    return r;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a, b, c;
    ll ans = 0;
    rep(i, n)
    {
        int _;
        cin >> _;
        a.push_back(_);
    }
    rep(i, n)
    {
        int _;
        cin >> _;
        b.push_back(_);
    }
    rep(i, n)
    {
        int _;
        cin >> _;
        c.push_back(_);
    }
    sort(ALL(a));
    sort(ALL(b));
    sort(ALL(c));
    vshow(a);
    vshow(b);
    vshow(c);
    rep(i, n)
    {

        int start = binarySearch(b, a[i]);
        dumpl(start);
        rep(j, start, n)
        {
            dumpl(binarySearch(c, b[j]));
            ans += n - binarySearch(c, b[j]);
        }
    }
    cout << ans << endl;
    return 0;
}
