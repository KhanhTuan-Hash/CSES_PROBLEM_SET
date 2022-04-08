#include <bits/stdc++.h>
using namespace std ;
const int64_t N = 1e5; 
int64_t a[N << 1]{} , b[N << 1]{} ; 
int64_t n , m , k  ; 
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ; 
    cin >> n >> m >> k  ; 
    memset(a , -1, sizeof(a)) ; 
    memset( b, -1, sizeof(b)) ; 
    for(int64_t i = 0; i < n ; i++) cin >> a[i] ;
    for(int64_t i = 0 ; i < m ; i++) cin >> b[i] ; 
    sort(a , a + n) ; sort(b , b + m) ;  
    int64_t ans =  0 ; 
    for(int64_t p_1 = 0 , p_2 = 0 ; p_1 < n ; p_1++)
    {
        while(p_2 < m  and b[p_2] < a[p_1] - k )
            ++p_2 ; 
        if(p_2< m and b[p_2] <= a[p_1] + k )
             ++ans , ++p_2 ; 
            //  cerr << res.first  << " " << res.second << "\n" ; 
    }
    return cout << ans , 0 ; 
}