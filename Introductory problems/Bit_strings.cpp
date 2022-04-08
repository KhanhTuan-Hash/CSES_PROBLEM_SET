#include <bits/stdc++.h>
#include <assert.h>
using namespace std ;
#define pb push_back
const int64_t mod = 1e9+7 ; 
// count convert from num_10 to num_2 
// a^b mod MOD
int64_t bpow(int64_t a , int64_t n,int64_t mu) 
 {
	int64_t res = 1;
	while (n > 0) {
	    if (n & 1) res = (res * a) % mu;
	    a = (a * a) % mu;
	    n >>= 1;
	}
	return res;
}
auto solve =[]() -> void
{
    int64_t n ;
    cin >>  n ;
    if( n <= 200)
    {
    int64_t res = (1 << n)  ; 
    res%=mod ;
    cout << res << '\n' ; 
    }
    else 
    {
       cout << bpow(2 , n , mod ) << "\n"  ; 
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