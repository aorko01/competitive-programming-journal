#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll low = a[n / 2], high = 2000000000;

    while (low != high)
    {
        ll mid = low + (high - low + 1) / 2;
        ll moves = 0;
        for (int i = n / 2; i < n; i++)
        {
            if (mid > a[i])
                moves += mid - a[i];
            if (moves > k)
                break;
        }

        if (moves <= k)
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << low << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}