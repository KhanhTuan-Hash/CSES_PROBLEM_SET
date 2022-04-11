#include <bits/stdc++.h>
#include <ext/array_allocator.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std ; 
using namespace __gnu_pbds ;
#define ll long long
 
template <class T ,class Y > inline bool maximize(T &a , Y b){if(a >= b) return false ;a = b ; return true ; } ; 
template <class T , class Y > inline bool minimize(T &a , Y b){if(a <= b) return false ; a = b ; return true ; } ; 
 
template < class O > using Ordered_Set = tree< O , null_type , less < O > , 
                       rb_tree_tag , tree_order_statistics_node_update > ; 
ll n  ;
 
inline void solve()
{
   Ordered_Set< array < ll , 2 > > Key ;
   cin >> n ; 
    for(ll i(1) ; i <= n ; i = i + 1)
    {
        ll a ;
        cin >> a ;
        Key.insert({i , a})  ; 
    }
    for(ll i(1) ; i <= n ; i = i + 1)
    {
        ll k; 
        cin >> k ;
        k = k - 1 ; 
        auto iter = Key.find_by_order(k) ;
        cout << (*iter)[1] << " " ; 
        Key.erase(iter) ;  
    }
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ; 
    return solve() , 0 ;
}