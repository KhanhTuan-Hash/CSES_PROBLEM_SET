#include <bits/stdc++.h>
using namespace std ;

#define ll long long 
ll n , q  , x ,  u , v , val , t ; 

struct Node
{
    ll Pre_max , sum  ;
    Node operator + (Node f)
    {
        return 
        {
            max(sum + f.Pre_max  , Pre_max)  ,  sum + f.sum
        } ; 
    }
} ;  
Node Seg[1LL << 19 ]{} ; 
ll A[1LL << 18]{} ; 

inline void build(ll index = 0 , ll l = 0  , ll r = n - 1)
{
    if(l == r)
    {
        Seg[index] = {max(0LL , A[l]) , A[l] } ;
    }
    else 
    {
    ll mid = (l + r) >> 1 ;
    build(index << 1 | 1 , l , mid) ;
    build((index << 1 )+ 2 , mid + 1 , r) ;
    Seg[index] = Seg[index << 1 | 1] + Seg[(index << 1) + 2] ; 
    }
}
inline void update (ll index = 0 , ll l = 0 , ll r = n - 1)
{
    if(l == r)
    {
        Seg[index] = {max(0LL ,val ) , val}  ;
    }
    else
    {
        ll mid = (l + r) >> 1 ;
        if(x <= mid)
        {
            update ( index << 1 | 1 , l , mid ) ;   
        }
        else
        {
              update((index << 1) + 2 ,  mid + 1 , r) ;
        }
        Seg[index] = Seg[index << 1 | 1] + Seg[(index << 1 ) + 2] ; 
    } 
} 
Node Get_prefix(ll index = 0  , ll l = 0  , ll r = n - 1 )
{
    if(u > r || v < l) 
    {
        return {0LL, 0LL} ; 
    }
    if(u <= l && v >= r)
    {
        return Seg[index] ; 
    }
    ll mid = (l + r) >> 1 ;
    Node L = Get_prefix(index << 1 | 1 , l , mid )  ;
    Node  R = Get_prefix((index << 1 ) + 2 , mid + 1 , r ) ; 
    return (L + R) ; 
}

inline void solve()
{
    cin >> n >> q ; 
    memset(A , 0LL, sizeof(A)) ; 
    for(ll i(0) ; i < n  ; i = i + 1)
    {
        cin >> A[i] ; 
    }
    build() ; 
    while(q-->0)
    {
        cin >> t ;
        if(t == 1)
        {
            cin >> x >> val   ,  x = x - 1 ; 
            update() ; 
        }
        else 
        {
            cin >> u >> v , --u , --v ; 
             cout << Get_prefix().Pre_max << "\n" ; 
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ;
    return solve() , 0 ; 
}