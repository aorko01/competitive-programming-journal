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
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(all(a));
    ll min_odd=0,min_even=0,max_odd=n-1,max_even=n-1;
    bool odd_found=false,even_found=false;
    for(ll i=0;i<n;i++)
    {
        if(a[i]%2==0 && !even_found)
        {   
            min_even=i;
            even_found=true;
        }
        if(a[i]%2!=0 && !odd_found)
        {
            min_odd=i;
            odd_found=true;
        }
        if(even_found && odd_found)
        break;
    }
    even_found=false,odd_found=false;
    for(ll i=n-1;i>=0;i--)
    {
        if(a[i]%2==0 && !even_found)
        {   
            max_even=i;
            even_found=true;
        }
        if(a[i]%2!=0 && !odd_found)
        {
            max_odd=i;
            odd_found=true;
        }
        if(even_found && odd_found)
        break;
    }
    cout<<min((min_odd+n-1-max_odd),(min_even+n-1-max_even))<<endl;
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