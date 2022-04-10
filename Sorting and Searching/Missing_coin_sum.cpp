#include<bits/stdc++.h>
using namespace std ;
int64_t DP[200005]{}; 
int64_t n ; 
template <class T ,class Y > inline bool maximize(T &a , Y b)
{
    if(a >=b) return false; 
    a =  b; 
    return true; 
}
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false);
    cerr.tie(0) ; 
    cin >> n ; 
  //  memset(X , -1, sizeof(X) ) ;
   int64_t X[n + 1] = {0 } ; 
    map < int64_t , int64_t > Map;
    for(int64_t i = 1 ; i <= n ; i++)
        cin >> X[i] ;
 
   sort(X + 1, X + n + 1) ; 
 
    DP[0] = 1 ; 
    for(int64_t i = 1 ; i <= n  ; i++ )
   {
       if(DP[i - 1] < X[i]) 
       {
           cout << DP[i - 1] <<"\n" ;
           return  0 ;
       }
       DP[i] = DP[ i- 1] + X[i] ; 
   }
   return cout << DP[n] , 0 ; 
}