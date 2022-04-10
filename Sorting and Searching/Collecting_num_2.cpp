#include <bits/stdc++.h>
using namespace std ; 
const int64_t N = 1e5 ; 
int64_t A[N << 1]{} , POS[N << 1]{} ; 
int64_t n , m ; 
int32_t main(int32_t argc,char const *argv[])
{
    cin.tie(0)->sync_with_stdio(false); 
    cerr.tie(0) ;
    cin >> n >> m ;
    for(int64_t i = 0; i < n ; i++)
    {
        cin >> A[i + 1] ;
        POS[A[i + 1]] = i + 1;   
    } 
    int64_t ans(0) ;
    for(int64_t i = 2 ; i <= n ;i++)
    {
        if(POS[i - 1] > POS[i]) ++ans ; 
    }
    for(int64_t i = 0 ; i < m ;i++)
    {
        int64_t L , R ;
        cin >> L >> R ;
        if(A[L] > A[L]  ) 
        {
            swap(L , R ) ; 
        }
        if(A[L] > 1 and POS[A[L] - 1] > L) --ans ; 
        if(POS[A[L] + 1] < L) --ans;
        //if(POS[A[L] + 1] > L) ++ans ; 
        if(A[R] < n  and POS[A[R] + 1] < R) --ans ;
        if(A[L] < A[R] - 1 and POS[A[R] - 1] > R) --ans ; 
        swap(POS[A[L]] , POS[A[R]]) ; 
        swap(A[L] , A[R]) ;
         swap(L , R) ;
           if(A[L] > 1 and POS[A[L] - 1] > L) ++ans ; 
        if(POS[A[L] + 1] < L) ++ans;
       // if(POS[A[L] + 1] > L) --ans ; 
        if(A[R] < n and POS[A[R] + 1] < R) ++ans ;
        if(A[L] < A[R] - 1 and POS[A[R] - 1] > R) ++ans ; 
        cout << ans << "\n" ; 
      }
    return 0 ; 
}