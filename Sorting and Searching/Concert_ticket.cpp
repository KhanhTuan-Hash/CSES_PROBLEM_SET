#include <bits/stdc++.h>
using namespace std;

const int64_t N = 1e5 ;

int64_t H[N << 1]{} , T[N << 1]{} ; 

int64_t n , m ; 

int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false); 
    cerr.tie(0) ;
    cin >> n >> m ;
    multiset < array  < int64_t , 2 > > S ;
    for(int64_t i = 0 ; i < n ; i++)
    {
        int64_t cost; 
        cin >> cost ;
        S.insert({cost , i}) ; 
    }
    for(int64_t i = 0 ; i < m ; i++)
    {
        int64_t max_cost; 
         cin >> max_cost  ; 
         auto iter = S.lower_bound({max_cost + 1 , 0} ) ; 
         if(iter == S.begin())
         {
             cout << -1 <<"\n" ; 
         } 
         else
         {
             --iter ; 
             cout << (*iter)[0] << "\n" ;
              S.erase(iter) ;  
         }
    }
    return 0 ; 
}
