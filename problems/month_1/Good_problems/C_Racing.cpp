#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << endl; }

template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    ll n;
    cin >> n;

    vector<ll> ans(n);
    for (ll i = 0; i < n; i++) {
        cin >> ans[i];
    }

    vector<pair<ll, ll>> heights(n);
    for (ll i = 0; i < n; i++) {
        cin >> heights[i].first >> heights[i].second;
    }

    vector<pair<ll, ll>> valid_heights(n + 1);
    valid_heights[0] = {0, 0}; 

    for (ll i = 0; i < n; i++) {
        ll lo = valid_heights[i].first;
        ll hi = valid_heights[i].second;

        ll new_lo = INF;
        ll new_hi = -INF;

        if (ans[i] == -1 || ans[i] == 0) {
            new_lo = min(new_lo, lo);
            new_hi = max(new_hi, hi);
        }

        if (ans[i] == -1 || ans[i] == 1) {
            new_lo = min(new_lo, lo + 1);
            new_hi = max(new_hi, hi + 1);
        }

        new_lo = max(new_lo, heights[i].first);
        new_hi = min(new_hi, heights[i].second);

        if (new_lo > new_hi) {
            cout << -1 << endl;
            return;
        }

        valid_heights[i + 1] = {new_lo, new_hi};
    }
    ll now=valid_heights[n].second;
    for(ll i=n-1;i>=0;i--)
    {
        if(ans[i]==1)
        now--;
        else if(ans[i]==-1)
        {
            if(valid_heights[i].second<now)
            {
                ans[i]=1;
                now--;
            }
            else
            ans[i]=0;
        }
    }
    for(ll i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
