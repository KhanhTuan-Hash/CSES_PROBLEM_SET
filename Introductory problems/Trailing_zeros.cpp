#include <bits/stdc++.h>
#include <assert.h>
using namespace std ;
#define pb push_back
const int64_t mod = 1e9+7 ; 

auto solve =[]() -> void
{
   int64_t n ; 
   cin >> n ; 
  if(n < 5) 
{
    if (n == 0 )
    {
        cout << 1  ;return ; 
    }
    cout << 0 ; 
}
else if(n == 5) cout << 1 ; 
   // 5 = 120  have 1 traling zero (minimum num )
   else{
       int64_t fac = 0 ; 
       for(int64_t i = 5  ;  i < n ; i = i*5)
       {
           fac  = fac  + n/i ; 
       }
       cout << fac << "\n"  ; 
   }
} ; 

int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0);
    solve()  ; 
    assert(true)  ;
    return 0  ;
}