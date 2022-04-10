#include <bits/stdc++.h>
using namespace  std ;

  vector <int64_t > A(200005) ;  
  int64_t n , x; 
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false);
    cerr.tie(0) ; 
    map <int64_t , int64_t > Map ;
    int64_t ans(0), sum(0) ;
    cin >> n >> x; 
    Map[0] = Map[0] +1;
    for(int64_t i(0) ; i  < n ; i = i + 1 )
    {
        cin >> A[i] ;
        sum = sum + A[i ]; 
        ans = ans + Map[sum - x] ; 
         Map[sum] = Map[sum] + 1; 
    }
    return cout << ans , 0 ; 
}
