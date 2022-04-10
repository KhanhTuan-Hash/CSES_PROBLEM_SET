#include <bits/stdc++.h>
using namespace std ;

const int64_t N = 1e5 ;

int64_t n  ;
int64_t Room[N << 1]{};
array<int64_t , 3 > A[N << 1] ;

int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false);
    cerr.tie(0) ;
    cin >> n; 
    
    for(int64_t i(0) ; i < n ; i = i + 1)
    {
        cin >> A[i][1] >> A[i][0] ; 
        A[i][2] = i ; 
    } 
 
   sort(A , A + n) ; 

   multiset < array  < int64_t , 2 > > MSA ;
     for(int64_t i(0) ; i < n ; i = i + 1)
     {
         auto iter = MSA.lower_bound({A[i][1]}) ;
         if(iter != MSA.begin())
         {
             --iter ;
             Room[A[i][2]] = (*iter)[1] ; 
             MSA.erase(iter); 
         }
         else
             Room[A[i][2]] = MSA.size() ;
             MSA.insert({A[i][0], Room[A[i][2]]}) ; 
     }
     cout  << MSA.size()  << "\n" ;
      for(int64_t i(0) ; i < n ; i = i + 1)
      {
          cout << Room[i] + 1 << " " ;  
      }
      return 0 ; 
}