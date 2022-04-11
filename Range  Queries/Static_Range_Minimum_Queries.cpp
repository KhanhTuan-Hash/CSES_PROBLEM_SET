#include <bits/stdc++.h>
using namespace std ;

#define ll long long 

ll Seg[1 << 19]  ; 
inline void build_tree(ll pos[] , ll index , ll l , ll r)
{
    if(l == r)
    {
        Seg[index] = pos[l] ; 
        return ; 
    }
    ll mid = (l + r) >> 1;
    build_tree(pos , index << 1 | 1 , l , mid) ;
    build_tree(pos , (index << 1) + 2 , mid + 1 , r) ; 
    Seg[index] = min(Seg[index << 1 | 1] , Seg[(index << 1) + 2]) ; 
} 

inline ll Get(ll u , ll v , ll l , ll r , ll index)
{
    if(u > r or v < l) return LLONG_MAX ; 
    if(u <= l and v >= r)
    {
        return Seg[index] ;
    }
    ll mid = (l + r) >> 1 ; 
    ll L = Get(u , v , l , mid , index << 1 | 1) ; 
    ll R = Get(u , v , mid + 1 , r , (index << 1) + 2) ; 
    return min(L , R) ;  
}
inline void Solve()
{
    ll n , q ; 
    cin >> n >> q ;  
    ll pos[n] ; 
    for(ll i(0) ; i < n; i = i + 1)
    {
        cin >> pos[i]  ; 
    }
    build_tree(pos , 0 , 0 , n - 1)  ; 
    while(q--)
    {
        ll a , b; 
        cin >> a >> b;
        cout << Get(a - 1 , b - 1, 0 , n - 1 , 0 ) << "\n"  ;
    } 
}

int main()
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ; 
     return Solve() , 0 ;  
}