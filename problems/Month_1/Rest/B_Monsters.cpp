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
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define ar array

// Macros
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES\n"
#define no cout << "NO\n"

// Loops
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto &x : a)

// Constants
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998244353;
const ll INF = 1e18;
const int INF_INT = 1e9;
const ld EPS = 1e-9;
const ld PI = acos(-1);

// Fast IO
void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void solve() {
    // Your solution here
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> v(k);
    set<ll> s;
    rep(i,0,n)
    {
        ll x;
        cin>>x;
        s.insert(x%k);
        v[x%k].push_back(i+1);
    }
    rep(j,0,v[0].size())
    {
        cout<<v[0][j]<<" ";
    }
    for (auto it = s.rbegin(); it != s.rend(); ++it) 
    {
        if(*it==0)
        continue;
        rep(m,0,v[*it].size())
        {
            cout<<v[*it][m]<<" ";
        }
    }
    cout<<endl;

}

int main() {
    fastIO();
    int tc = 1;
    cin >> tc;
    rep(t, 1, tc + 1) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}