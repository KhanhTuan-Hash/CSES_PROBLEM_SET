#include <bits/stdc++.h>
using namespace std;
using i64 = long long ;
 
i64 A[200005]{} ;  
 
i64 n , q ; 
int main()
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ; 
    cin >> n >> q ; 
    for(int i(0) ; i < n ;  i = i + 1)
    {
        cin >> A[i + 1] ;
        A[i + 1] = A[i + 1]  + A[i]  ; 
    }
    for(i64 a ,b ; q--;  )
    {
        cin >> a >>  b ; 
        --a ; 
        cout << A[b] - A[a] << "\n"  ;  
    }
    return 0 ; 
}