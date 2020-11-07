#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;
int N = 20;
int M = 100;
typedef struct Pos Pos;
struct Pos {
    int y, x;
};

typedef struct State State;
struct State {
    vector<vector<int>> grid;
    int x, y;
    stack<int> card;
};
State state;
int score = 0;

map<int, pair<int, int>> pos;

void init()
{
    state.grid = vector<vector<int>>(N, vector<int>(N, -1));
    rep(i, M)
    {
        int x, y;
        cin >> y >> x;
        state.grid[y][x] = i;
        pos[i] = { y, x };
    }
}

int rec(vector<vector<int>>& dist, vector<vector<int>>& cost, vector<vector<int>>& par, int num, int visited, int cur)
{
    if (cost[visited][cur] >= 0) {
        return cost[visited][cur];
    }
    if (visited == (1 << num) - 1) {
        cost[visited][cur] = 0;
        return 0;
    }
    int ans = IINF;
    for (int i = 0; i < num; i++) {
        if ((visited >> i) & 1) {
            continue;
        }
        int tmp = rec(dist, cost, par, num, visited | 1 << i, i) + dist[cur][i];
        if (tmp < ans) {
            ans = tmp;
            par[visited][cur] = i;
        }
    }
    //cerr << visited << " " << cur << " " << par[visited][cur] << endl;
    cost[visited][cur] = ans;
    return ans;
}

vector<int> TSP(int start, int num)
{

    vector<pair<int, int>> points;
    points.push_back({ state.y, state.x });
    for (int i = start; i < start + num; i++) {
        points.push_back(pos[i]);
    }
    num++;
    assert(num == points.size());
    vector<vector<int>> dist(num, vector<int>(num, 0));
    vector<vector<int>> cost(1 << (num), vector<int>(num, -1));
    vector<vector<int>> parent(1 << (num), vector<int>(num, 0));

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {

            dist[i][j] = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
        }
    }
    rec(dist, cost, parent, num, 1, 0);
    int idx = 0;
    int visited = 1;
    vector<int> ans;
    for (int i = 1; i < num; i++) {

        idx = parent[visited][idx];
        visited |= 1 << idx;
        ans.push_back(idx - 1 + start);
        //cerr << idx << endl;
    }
    return ans;
}

void I()
{
    assert(state.grid[state.y][state.x] != -1);
    state.card.push(state.grid[state.y][state.x]);
    pos[state.grid[state.y][state.x]] = { IINF, IINF };
    state.grid[state.y][state.x] = -1;
    cout << "I";
}
void O()
{
    //cout << state.grid[state.y][state.x] << endl;
    assert(state.grid[state.y][state.x] == -1);
    assert(!state.card.empty());
    state.grid[state.y][state.x] = state.card.top();
    pos[state.card.top()] = { state.y, state.x };
    state.card.pop();
    cout << "O";
}

int findInsideCard(pair<int, int> target)
{
    int yhigh = max(target.first, state.y);
    int ylow = min(target.first, state.y);
    int xhigh = max(target.second, state.x);
    int xlow = min(target.second, state.x);
    int ret = -1;
    int dist = IINF;

    rep(i, M)
    {
        if (pos[i].first == IINF)
            continue;
        if (pos[i] == target) {
            continue;
        }
        if (pos[i].first == state.y && pos[i].second == state.x) {
            continue;
        }

        if (ylow <= pos[i].first && pos[i].first <= yhigh && xlow <= pos[i].second && pos[i].second <= xhigh) {
            int curdist = abs(pos[i].first - state.y) + abs(pos[i].second - state.x);
            if (curdist < dist) {
                ret = i;
                dist = curdist;
            }
        }
    }
    return ret;
}

void moveRobotSub(pair<int, int> target, bool isSwipe)
{
    assert(target.first != IINF);
    while (target.first > state.y) {
        bool pickOtherCard = false;

        if (isSwipe && state.y + 1 < N && state.grid[state.y][state.x] != -1 && state.grid[state.y + 1][state.x] == -1 && state.y < N / 2) {
            I();
            pickOtherCard = true;
        }

        cout << "D";
        score++;
        state.y++;
        if (pickOtherCard) {
            O();
        }
    }
    while (target.first < state.y) {
        bool pickOtherCard = false;
        if (isSwipe && state.y - 1 >= 0 && state.grid[state.y][state.x] != -1 && state.grid[state.y - 1][state.x] == -1 && state.y > N / 2) {
            I();
            pickOtherCard = true;
        }
        cout << "U";
        score++;
        state.y--;
        if (pickOtherCard) {
            O();
        }
    }
    while (target.second > state.x) {
        bool pickOtherCard = false;
        if (isSwipe && state.x + 1 < N && state.grid[state.y][state.x] != -1 && state.grid[state.y][state.x + 1] == -1 && state.x < N / 2) {
            I();
            pickOtherCard = true;
        }

        cout << "R";
        score++;
        state.x++;
        if (pickOtherCard) {
            O();
        }
    }
    while (target.second < state.x) {
        bool pickOtherCard = false;
        if (isSwipe && state.x - 1 >= 0 && state.grid[state.y][state.x] != -1 && state.grid[state.y][state.x - 1] == -1 && state.x > N / 2) {
            I();
            pickOtherCard = true;
        }

        cout << "L";
        score++;
        state.x--;
        if (pickOtherCard) {
            O();
        }
    }
    //cout << "fin" << endl;
}
void moveRobotSub(int target, bool isSwipe)
{
    moveRobotSub(pos[target], isSwipe);
}

void moveRobot(pair<int, int> target, bool isSwipe)
{
    if (isSwipe == false) {
        moveRobotSub(target, false);
        return;
    }
    while (int t = findInsideCard(target)) {
        if (t == -1) {
            break;
        }
        moveRobotSub(t, true);
    }
    moveRobotSub(target, true);
}

void moveRobot(int target, bool isSwipe)
{
    moveRobot(pos[target], isSwipe);
}

void pickup(vector<int>& targets)
{
    for (auto&& target : targets) {
        moveRobot(target, true);
        //cerr << "bacl" << endl;
        I();
    }
}
void vomit(int num)
{
    assert(state.grid[state.y][state.x] == -1);
    O();
    vector<pair<int, int>> points = { { state.y, state.x } };
    rep(i, num - 1)
    {
        pair<int, int> newp;
        int dist = IINF;
        rep(y, N)
        {
            rep(x, N)
            {
                if (state.grid[y][x] != -1)
                    continue;
                int curdist = 0;
                for (auto&& p : points) {
                    curdist += abs(p.first - y) + abs(p.second - x);
                }
                if (curdist < dist) {
                    newp = { y, x };
                    dist = curdist;
                }
            }
        }
        moveRobot(newp, false);
        // cerr << 123 << endl;
        O();
        //cerr << 456 << endl;

        points.push_back(newp);
    }
}

void relax(int start, int num)
{
    vomit(num);
    for (int i = start; i < start + num; i++) {
        moveRobot(i, false);
        I();
    }
}

int main()
{
    init();
    int S = 10;
    int start = 0;
    int rem = M;
    while (rem > 0) {
        auto ret = TSP(start, min(S, rem));
        pickup(ret);
        relax(start, min(S, rem));
        start += S;
        rem -= S;
    }
    cout << endl;
    cerr << "score:" << 4000 - score << endl;
    return 0;
}