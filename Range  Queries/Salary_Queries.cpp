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
                       
                       ll n ,q ;
                       Ordered_Set < array < ll , 2 > > Key  ; 
                       ll A[1 << 18]{} ; 
                        inline void solve()
                       {
                           cin >> n >> q ; 
                           for(ll i(0) ; i <= n - 1 ; i = i + 1)
                           {
                               cin >> A[i] ;
                               Key.insert({A[i] , i})  ; 
                           }
                           for(ll i(0) ; i <= q - 1; i = i + 1)
                           {
                               char ch ;
                               cin >> ch ;
                               if(ch == '!')
                               {
                                   ll k , x ;
                                    cin >> k >> x ;
                                    k = k - 1 ;
                                    Key.erase({A[k] , k}) ; 
                                    A[k] = x ;
                                    Key.insert({A[k] , k})  ; 
                               }
                               else 
                               {
                                   ll a , b;
                                   cin >> a >>  b;
                                   cout << Key.order_of_key({b + 1, 0}) - Key.order_of_key({a , 0}) << "\n" ; 
                               }
                           }
                       }

                       int main()
                       {
                           cin.tie(0)->sync_with_stdio(false) ;
                           cerr.tie(0) ; 
                           return solve() , 0 ;
                       }