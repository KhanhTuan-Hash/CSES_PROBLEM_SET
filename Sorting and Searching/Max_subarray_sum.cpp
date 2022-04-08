// kadange algo 
#include <bits/stdc++.h>
using namespace std ;
template<class T , class Y > inline bool maximize(T &a , Y b)
{
    if(a >=b) return false;
    a = b ; 
    return true ; 
}

int64_t n ;

int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ;
    pair < int64_t , int64_t > ans{-1e18 , -1e18} ;
    cin >> n ;
    for(int64_t i = 0 ; i < n ; i++)
    {
        int64_t x ;
        cin >> x; 
        ans.first = max(ans.first + x , x) ; 
        maximize(ans.second , ans.first ) ;
    }
    return cout << ans.second <<"\n", 0 ; 
}