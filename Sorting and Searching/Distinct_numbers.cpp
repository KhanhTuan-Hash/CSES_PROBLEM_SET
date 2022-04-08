#include <bits/stdc++.h>
using namespace std ;
int32_t main(int32_t argc ,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ; 
    cerr.tie(0) ; 
    int64_t n ;
    cin >> n ; 
    set< int64_t > S ; 
    for(int64_t i = 0 ;  i < n; i++)
    {
        int64_t x ; 
        cin >> x ; 
        S.insert(x) ;
    }
    return cout << S.size() , 0 ; 
}