#include <bits/stdc++.h>
using namespace std ;

main()
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0)  ;
    int64_t n_test  ;
    cin >> n_test ; 
    for(int64_t a , b ; n_test--  ; )
    {
        cin >> a >> b ;
       /* if((a == 0 || b == 0)&& (a || b) != 0) 
        {
            cout << "NO\n" ; 
            return  0; 
        }
         if(a == 0 && b == 0)  
         {
             cout << "YES\n" ; return  0 ;
         }*/
        int64_t sum = a + b ; 
        cout << ((sum % 3 == 0 && (a << 1) >= b && (b << 1) >= a ) ? "YES\n" :"NO\n") ; 
        // yes :  3 6 
    }
    return  0 ;
}