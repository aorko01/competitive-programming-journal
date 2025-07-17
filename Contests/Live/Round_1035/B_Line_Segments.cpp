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
    ll n;
    cin>> n;
    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vll points(n);
    ll sum=0;
    set<ll> s;
    ll maxi=LLONG_MIN;
    for (ll i = 0; i < n; i++) {
        cin >> points[i];
        if(points[i] > maxi) {
            maxi = points[i];
        }
        if(s.find(points[i]) == s.end()) {
            s.insert(points[i]);
        } else {
            s.erase(points[i]);
        }
        sum += points[i];
    }
    ll dist= pow(x2 - x1, 2) + pow(y2 - y1, 2);
    // if(dist == 0) {
    //    if(s.empty()) {
    //         cout << "Yes\n";
    //      } else {
    //         cout << "No\n";
    //      }
    // }
    // else
    // { 
    //     if(pow(sum,2)>=dist) {
    //         ll min_sum=sum - maxi;
    //         if(pow(min_sum,2) <= dist) {
    //             cout << "Yes\n";
    //             return;
    //         } 
    //         cout << "No\n";
    //     } else {
    //         cout << "No\n";
    //     }
    // }
    ll other_sum = sum - maxi;
    ll mini_sum;
    if(other_sum>maxi){
        mini_sum = 0;
    }
    else {
        mini_sum = maxi - other_sum;
    }
    if(pow(mini_sum, 2) <= dist && pow(sum, 2) >= dist) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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