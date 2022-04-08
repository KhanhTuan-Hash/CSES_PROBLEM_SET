#include <bits/stdc++.h>
#include <assert.h>
using namespace std ;
#define pb push_back
auto solve =[]() -> void
{
    int64_t n ; cin >> n ;
    int64_t sum = 1LL*n*(n + 1)  ;
    int64_t res = (sum >> 1) ; 
    if(n <= 1 || res & 1 || sum <= 1 )
    {
        cout << "NO" ;
       // return ; 
    } 
    else 
    {
        cout << "YES\n" ; 
   vector < int64_t > v1  ,v2 ; 
   // 7 
   /*for(int64_t i = 0 ; i < (n - 1) / 4 ; i++)
   {
       v1.pb(1LL*4*i + 1);  
       v1.pb(1LL*4*i + 4);
       v2.pb(1LL*4*i + 2) ; 
       v2.pb(1LL*4*i + 3);
   }
    if( n% 4)
    {
        v1.pb(1);
        v1.pb(2)  ;
        v2.pb(3)  ;
    }
    else
    {
        v1.pb(1)  ;
        v1.pb(4)  ;
        v2.pb(2);
        v2.pb(3)  ;
    }*/
   res  = res / 2LL ; 
    while(n)
    {
         int64_t diff  = res - n ;
    if(diff >= 0 )
    {
        v1.pb(n);
        res = res - n  ; // 6 - 4 = { 2, 2 }  ;
        // 16 - > {3 ,3} can't be happened
    }
    else 
    {
        v2.pb(n) ; 
    }
     n = n - 1 ;
    } 
     cout << v1.size() << "\n" ;
     for(int64_t &a : v1) cout << a << " " ;
     cout << "\n"  ;
      cout << v2.size() << "\n"  ;
      for(int64_t &b : v2) cout << b << " " ;
      cout << "\n" ; 
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