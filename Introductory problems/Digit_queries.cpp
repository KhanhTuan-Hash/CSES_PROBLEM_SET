#include <bits/stdc++.h>
using namespace std ; 

inline int64_t bpow(int64_t a, int64_t n)
{ 
    int64_t res(1)  ;
    while(n)
    {
        if(n & 1) res = (1LL*res*a)  ; 
        
        n = ( n >> 1) ; 
        a = (1LL*a *a )  ;
     }
     return res ; 
}
int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false )  ;
    cerr.tie(0)  ;
    auto solve = []() -> void
    {
       int64_t n_test ; 
        for(cin >> n_test ; n_test--; )
        {
             int64_t N ;
             cin >> N ;
             int64_t _size(1) ; 
             for(int64_t temp = 9 ;; N = N - temp , _size = _size + 1 , 
                   temp = 9*(bpow(10 , _size - 1)) * _size )
                   {
                       int64_t Diff = N - temp ; 
                       if(Diff <= 0) break ;  
                   }
                   N = N - 1 ; 
                   int64_t res = (N /_size) + bpow(10 , _size - 1)  ;
                   //debug : cerr << res << " " << N/_size << " " << N % _size << "\n"  ; 
                   string str = to_string(res) ;  
                //cerr << str << "\n"  ;
                cout << str[N % _size] << "\n"  ;
        }
    } ; 
    solve() ;  
    return 0 ;
}