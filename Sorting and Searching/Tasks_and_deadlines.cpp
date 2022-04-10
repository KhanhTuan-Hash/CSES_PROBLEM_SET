#include <bits/stdc++.h>
using namespace std ;
const int64_t N = 1e5 ; 
array  < int64_t , 2 > A[N << 1]{} ; 
int64_t n ; 
vector < int64_t   > B(N << 1) , C(N << 1) ;

int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ;
   cin >> n ; 
    int64_t ans(0) ; 
    for(int64_t i(0) ; i < n ; i= i +1) cin >> A[i][0] >> A[i][1] ;
    sort(A , A + n) ; 
    int64_t temp(0 ) ;
    for(int64_t i(0) ;  i < n ; i = i + 1 )
    {
        temp  = temp + A[i][0] ; // f 
        int64_t diff =  A[i][1] - temp ; 
        ans = ans + diff ; 
    }
    return cout << ans ,0  ;
}
