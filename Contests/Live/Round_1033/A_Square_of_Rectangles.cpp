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
    ll l1,b1,l2,b2,l3,b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    bool possible = false;
    if(l1+l2+l3 == b1 && b1 == b2 && b2 == b3) {
        possible = true;
    } else if(l1+l2 == l3 && b1+b3==l3)
    {
        possible = true;
    } 
    else if(l1+l3 == l2 && b1+b2==l2)
    {
        possible = true;
    } 
    else if(l2+l3 == l1 && b2+b1==l1)
    {
        possible = true;
    } 
    else if(b1+b2+b3 == l1 && l1 == l2 && l2 == l3) {
        possible = true;
    } else if(b1+b2 == b3 && l1+l3==b3)
    {
        possible = true;
    } 
    else if(b1+b3 == b2 && l1+l2==b2)
    {
        possible = true;
    } 
    else if(b2+b3 == b1 && l2+l1==b1)
    {
        possible = true;
    }
    cout << (possible ? "YES" : "NO") << '\n';

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