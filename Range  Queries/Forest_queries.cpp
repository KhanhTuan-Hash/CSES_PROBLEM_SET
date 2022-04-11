#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n , q ;
// prefix_sum on 2D
ll dp[1 << 10][1 << 10]{} ; 
inline void solve()
{
    cin >> n >> q ;
    for(ll i(1) ; i<= n ; i = i + 1 )
    {
        for(ll j(1) ; j <= n ; j = j + 1)
        {
            char s ;
            cin >> s ;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + (s == '*' && s != '.') - dp[i-1][j-1] ; 
        }
    }
    while(q--)
    {
        ll x1,y1,x2,y2 ;
        cin >> x1 >> y1 >> x2 >> y2 ;
        ll S = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1 -1] + dp[x1-1][y1-1]  ;
        cout << S << "\n" ; 
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ; 
    return solve() , 0 ;
}