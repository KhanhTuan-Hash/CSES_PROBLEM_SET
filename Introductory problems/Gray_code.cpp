// generate by bitmask(sinh nhi phan co do dai n)
#include <bits/stdc++.h> 
using namespace std ;

main()
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ;
    int64_t n; 
    cin >> n; 
    for(int64_t mask = 0 ; mask < (1 << n) ; mask++)
    {
        bitset <32> j(mask ^ (mask >> 1)) ; 
        string str = j.to_string()  ;
        cout << str.substr(32 - n)  << "\n" ; 
    }
    return 0 ; 
}
