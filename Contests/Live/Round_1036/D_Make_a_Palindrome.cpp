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
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
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
void fastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll backward(vector<ll> &a, ll i,ll j, ll target)
{
    ll left = 0, right = i;
    while (left < right)
    {
        ll mid = left + (right - left) / 2;
        if (a[mid] > target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}
ll forward(vector<ll> &a, ll i, ll target)
{
    ll left = i , right = a.size() - 1;
    while (left < right)
    {
        ll mid = left + (right - left) / 2;
        if (a[mid] > target)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

void solve()
{
    // Your solution here
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vll forw(n);
    vll bacw(n);
    ll maxi_forward = INT_MIN;
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    ll maxi_backward = INT_MIN;
    rep(i, 0, n)
    {
        if (i == 0)
        {
            forw[i] = a[i];
        }
        else
        {
            forw[i] = max(forw[i - 1], a[i]);
        }
        maxi_forward = max(maxi_forward, forw[i]);
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            bacw[i] = a[i];
        }
        else
        {
            bacw[i] = max(bacw[i + 1], a[i]);
        }
        maxi_backward = max(maxi_backward, bacw[i]);
    }

    // vector<pll> x;
    // x=v;
    // sort(all(b));
    ll i = 0, j = n - 1;
    bool possible = true;
    while (i < j)
    {
        if (a[i] != a[j])
        {

            ll i1 = backward(bacw, i, a[i]);
            ll i2 = forward(forw, i, a[i]);
            bool found = false;
            if (i2 - i1 + 1 >= k)
            {
                found = true;
                i++;
            }
            i1 = backward(bacw, j, a[j]);
            i2 = forward(forw, j, a[j]);
            if (i2 - i1 + 1 >= k)
            {
                found = true;
                j--;
            }
            if (!found)
            {
                possible = false;
                break;
            }
        }
        else
        {
            i++;
            j--;
        }
    }
    if (possible)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    fastIO();
    int tc = 1;
    cin >> tc;
    rep(t, 1, tc + 1)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}