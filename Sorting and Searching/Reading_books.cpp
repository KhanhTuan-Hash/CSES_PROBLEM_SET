#include <bits/stdc++.h>
using namespace std ;
const int64_t N = 1e5 ;
int64_t A[N << 1]{} , prefix[N << 1]{} ; 
int64_t n ; 
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false); 
    cerr.tie(0) ;
    cin >> n ; 
    prefix[0] = 0 ; 
    int64_t sum(0) ; 
    for(int64_t i(0) ;  i < n ;  i = i + 1)
    {
        cin >> A[i ]; 
        sum = sum + A[i] ; 
    }
    sort(A , A + n); 
    return cout << max(1L*sum , (A[n - 1] << 1LL)) << "\n" , 0 ; 
}