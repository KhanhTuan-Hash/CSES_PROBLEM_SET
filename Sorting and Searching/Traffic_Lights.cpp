#include <bits/stdc++.h>
using namespace std ;
const int64_t N = 1e5 ;
int64_t x , n ;
int64_t p[N << 1] = {} ;
map < int64_t , int64_t > Mp ; 
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false); 
    cerr.tie(0) ;
    cin >> x >> n ;
    set < int64_t > S;
    S.insert(0) ; S.insert(x) ;
    Mp[x] = 1;
    for(int64_t i = 0 ; i < n ;i++)
    {
        cin >> p[i] ;
        auto iter = S.upper_bound(p[i]) ; 
        int64_t j = *iter ;
        --iter ;
        int64_t k = *iter ;
        --Mp[j - k] ;
        if(!Mp[j - k])
            Mp.erase(j - k ) ;
        S.insert(p[i]) ; 
        Mp[j - p[i]]++ ;
        Mp[p[i] - ]++ ;
        cout << ((--Mp.end())->first) << " "; 
        
     //  cerr << ((Mp.end()--)->second ) << " " << *iter << "\n" ;
     
    }
 //   cerr << S.size()  << "\n" ; 
    return  0 ;
}