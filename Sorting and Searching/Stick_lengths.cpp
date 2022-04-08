#include <bits/stdc++.h>
using namespace std;
int64_t p[200005]= {} ; 
int64_t n ;
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false); 
    cerr.tie(0) ;
    cin >> n ;
    memset( p , -1, sizeof(p) ) ;
    for(int64_t i = 0 ; i < n ; i++)
    {
        cin >> p[i] ; 
    }
    sort( p , p + n) ;
    // tong = tong + |p[ban dau] - p[median] | 
    int64_t ans(0) ;
    for(int64_t i = 0 ; i < n ; i++)
    {
        ans = ans + abs(p[i] - p[i >> 1]) ; 
    }
    return cout << ans , 0 ;  
}