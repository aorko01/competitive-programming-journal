#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):" , dbg_out(__VA_ARGS__)
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
    ll n,m;
    cin >> n >> m;
    if(n*(n+1)/2 < m) {
        cout<<-1 << '\n';
        return;
    }
    if(m<n) {
        cout << -1 << '\n';
        return;
    }
    vector<pair<ll,ll>> ans;
    ll root = 0;
    if(m<2*n)
    {
        root = m-n+1;
        cout << root << '\n';
        ans.push_back({root, 1});
        for(ll i=2; i<=n; i++)
        {
            if(i == root) continue;
            ans.push_back({i, 1});
        }
        for(ll i=0;i<ans.size(); i++)
        {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }
    else
    {
        root = n;
        cout<<root<<endl;
        set<ll> not_used;
        for(ll i=2; i<=n; i++)
        {
            if(i == root) continue;
            not_used.insert(i);
        }
        ll sum = m-n;
        ll i=1;
        ll used=0;
        ll val ;
        for(; i<n; i++)
        {
            auto it = not_used.find(sum-(n-1-i));
            if(it != not_used.end())
            {
                val = *it;
                used++;
                ans.push_back({root, val});
                not_used.erase(it);
                sum -= val;
                break;
            }
            else
            {
                auto it = *prev(not_used.end());
                ans.push_back({root, it});
                used++;
                not_used.erase(it);
                sum -= it;
            }

        }
        
        for(auto it = not_used.begin(); it != not_used.end(); it++)
        {
            ans.push_back({*it, val});
            used++;
        }
        for(;used < n-1; used++)
        {
            ans.push_back({root, 1});
        }
        sort(ans.begin(), ans.end());
        for(ll i=0;i<ans.size(); i++)
        {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
        
    }



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}