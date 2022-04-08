#include <bits/stdc++.h>
using namespace std ;

const int64_t N = 1e5;  
int64_t A[N << 1]{} ; 
int64_t n , x ;

int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false); 
    cerr.tie(0 ) ;
     cin >> n >> x ;
     memset(A , -1,sizeof(A)) ; 
     for(int64_t i = 0 ; i < n; i++) cin >> A[i] ;
     sort(A , A +  n) ;   
     int64_t ans =  0 ;
     for(int64_t i = 0 , j = n -1;  i < j ; )
     {
         while(i < j and (A[i] + A[j]) > x) --j ; 
        
         
         if(i >= j ) break; 
          if(i < j and (A[i] + A[j] <= x) )
          ++ans  ;  
          ++i , --j ;  
     }
    return cout << n - ans , 0 ; 
}
