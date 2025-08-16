#include <bits/stdc++.h>
using namespace std;

// Debugging utilities
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// Type aliases
#define ll long long
#define pii pair<int, int>
#define vi vector<int>

// Macros
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) ((int)(x).size())

// Fast IO
void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int max_val = a[0], min_val = a[0];
    int max_index = 0, min_index = 0;

    rep(i, 0, n) {
        if (a[i] > max_val) {
            max_val = a[i];
            max_index = i;
        }
        if (a[i] <= min_val) {
            min_val = a[i];
            min_index = i;
        }
    }

    int time;
    if (max_index < min_index)
        time = max_index + (n - 1 - min_index);
    else
        time = max_index + (n - 1 - (min_index + 1));

    cout << time << "\n";
}

int main() {
    fastIO();
    int tc = 1;
    // cin >> tc;
    rep(t, 1, tc + 1) {
        solve();
    }
    return 0;
}
