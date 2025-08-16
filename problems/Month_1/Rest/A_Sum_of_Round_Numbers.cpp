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
    string s;
    cin>>s;
    vector<string> ans;
    ll n=s.size();
    rep(i,0,n)
    {
        if(s[i]!='0')
        {
            string s1="";
            s1+=s[i];
            rep(j,i+1,n)
            s1+='0';
            ans.push_back(s1);
        }
    }
    cout<<ans.size()<<endl;
    for(auto s2:ans)
    {
        cout<<s2<<" ";
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