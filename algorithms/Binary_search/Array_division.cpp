#include <bits/stdc++.h>
using namespace std;

// Debugging utilities
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// Type aliases and macros
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()

// Fast IO
void fastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, k;

bool check(const vll &a, ll t)
{
    ll count = 1, sum = 0;
    for (ll x : a)
    {
        if (x > t) return false; 
        if (sum + x > t)
        {
            count++;
            sum = x;
        }
        else
        {
            sum += x;
        }
    }
    return count <= k;
}

void solve()
{
    cin >> n >> k;
    vll a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll l = *max_element(all(a));   
    ll h = accumulate(all(a), 0LL); 

    while (l < h)
    {
        ll mid = l + (h - l) / 2;
        if (check(a, mid))
            h = mid;
        else
            l = mid + 1;
    }

    cout << l << '\n';
}

int main()
{
    fastIO();
    int tc = 1;
    // cin >> tc;
    rep(t, 1, tc + 1)
    {
        solve();
    }
    return 0;
}
