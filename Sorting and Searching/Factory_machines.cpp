#include <bits/stdc++.h>
using namespace std;

#define N (int64_t)(1e18)
#define base (int64_t)(1e5)
int64_t n , t; 
int64_t A[base << 1 | 1]{} ; 
 int32_t main(int32_t argc,char*argv[])
 {
     cin.tie(0)->sync_with_stdio(false) ;
     cerr.tie(0) ; 
     cin >> n >> t ; 
     memset(A , -1, sizeof(A) ) ; 
     for(int64_t  i(0) ; i  < n ;  i = i + 1) cin >> A[i]; 
     sort(A , A + n) ; 
     int64_t l(1) , r(1e18) ;  
     while(l < r) 
     {
         int64_t mid((l + r ) >> 1) ; 
         int64_t ans(0) ;  
         for(int64_t i(0) ; i  < n ; i = i + 1)
             ans += min(mid / A[i] , (int64_t)1e9) ; // >> 1 

        if(ans >=t )
        {
            r = mid ; 
        }
        else
        {
            l = mid + 1 ; 
        }
     }
     return cout << l  , 0 ; 
 }