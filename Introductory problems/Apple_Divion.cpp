#include <bits/stdc++.h>
using namespace std ;
template <class T , class Y > inline bool minimize(T &a , Y  b)
{
    if(a <= b) return false ;
    a = b ; 
    return true ;
}
int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false ) ; 
    cerr.tie(0)  ;
    int64_t Sum(0) , res( LLONG_MAX) ; 
        int64_t n ; 
    cin >> n ;
    vector<int64_t >A(n)  ;
   for(int64_t &X : A) 
   {
       cin >> X ; 
       Sum = Sum + X ; 
   }
   for(int64_t mask(0) ; mask < (1 << n) ; mask++)
   {
       int64_t tot(0)  ;
       for(int64_t i = 0 ; i < n ; i++)
         {
             if(mask & (1 << i)) 
             {
                 tot = tot + A[i]  ;
             }
         }
         int64_t temp = abs((Sum - tot) - tot ) ; 
         minimize(res, temp)  ;
    }
    return cout << res , 0 ;
}