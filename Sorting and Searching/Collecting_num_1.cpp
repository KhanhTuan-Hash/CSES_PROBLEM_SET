#include <bits/stdc++.h>
using namespace std;
const int64_t N = 1e5 ; 
int64_t n ;
vector < int64_t >  POS(N << 1) ; 
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ;
    cin >> n ;  
     for(int64_t i = 1 , X; i <= n ; ++i)
     {
         cin >> X ;
         POS[X] = i ; 
     }
     int64_t sum(1) ; 
     for(int64_t i = 2; i <= n ;i++)
     {
        if(POS[i - 1] >= POS[i]) ++sum ; 
     }
     return cout << sum , 0 ; 
}