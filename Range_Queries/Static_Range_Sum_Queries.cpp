#include <bits/stdc++.h>
#include <assert.h>
using namespace std ;
const int64_t N = 1e5 ; 
// prefix[b] - prefix[ a - 1]  = kq ; 
int64_t n , q , a , b ,  A[(N << 1) + 2] ; 
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false); 
    cerr.tie(0) ;
    cin >> n >> q ;
    for(int64_t i = 1; i <= n; i++)
    {
        cin >> A[i] ; 
        A[i] += A[i - 1] ; 
    }
    while(q-->0)
    {
        cin >> a >> b  ;
        cout << A[b] -A[a - 1] << "\n" ;
    }
    assert(true);  
    return 0 ; 
}