#include <bits/stdc++.h>
using namespace std ;
const int64_t N = 1e5 ; 
array < int64_t , 2 > Fes[N << 1 ]; 
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ; 
    int64_t N_test ;
    cin >> N_test ;
    for(int64_t i = 0 ; i <  N_test ; i++)
    {
         cin >> Fes[i][1] >> Fes[i][0] ; // Start , End ; 
    }
    sort(Fes , Fes + N_test ) ; 
    int64_t ans(0) ; 
    int64_t len_mv(0 ); 
    for(int64_t i = 0 ; i  <N_test ; i++)
    {
        if( Fes[i][1] >= len_mv) 
        {
             ++ans ; 
            len_mv = Fes[i][0] ; 
           
        }
    }
    return cout << ans , 0 ; 
}