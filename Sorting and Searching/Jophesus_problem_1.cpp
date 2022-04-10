#include <bits/stdc++.h>
using namespace std ; 
int64_t n ;

int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0 ) ;
    cin >> n;
    pair < int64_t , int64_t > a { 1,  0 } ; 
    while(n)
    {
     for(int64_t i = 2 ;  i <= n ; i = i + 2 )
     {
         cout << 1LL*i*a.first  + a.second << " " ;
     }
     if(n & 1)
     {
         cout << a.first + a.second << " " ;
         a.second = a.second + a.first ; 
     }
     else
     {
         a.second = a.second - a.first ; 
     }
     a.first = (a.first << 1) ;
     n = (n >> 1)  ; 
    }
    return 0  ;
}