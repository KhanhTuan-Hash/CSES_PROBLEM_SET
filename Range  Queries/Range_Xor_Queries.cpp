#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair < ll , ll > node ; 

ll Seg[1 << 19 ]{} ; 
ll A[200005]{} ; 
ll n , q ; 
inline void build(ll index , ll l , ll r)
{
    if( l == r)
    {
        Seg[index] = A[l] ;
        return ; 
    }
    ll mid = (l + r) >> 1 ;
    build(index << 1 , l , mid) ;
    build(index << 1 | 1 , mid + 1 ,r)  ;
    Seg[index] = (Seg[index << 1] ^ Seg[index << 1 | 1])  ;
} 
inline void update(ll index , ll l , ll r , ll d , ll val)
{
    if(d > r || d < l) return ; 
    if(l == r && l == d)
    {
        Seg[index] = val ;
        return ; 
    }
    ll mid = (l + r) >> 1 ;
    update(index << 1 , l , mid , d , val) ;
    update(index << 1 | 1 , mid + 1 , r , d , val) ;
    Seg[index] = (Seg[index << 1] ^ Seg[index << 1 | 1])  ;
}
inline ll Get_sum(ll index , ll l , ll r , ll u , ll v)
{
    if(u > r || v < l) return 0 ; 
    if(u <= l && v >= r)
    {
        return Seg[index] ;
    }
    ll mid = (l + r) >> 1 ;
    ll L = Get_sum(index << 1 , l , mid , u , v) , R = Get_sum(index << 1 | 1 , mid + 1 , r , u , v) ; 
    return (L ^ R) ;  
}
auto solve =[]() -> void
{
    cin >> n >> q ;
    for(ll i(1) ; i <= n ; i = i + 1)
    {
        cin >> A[i] ;
    }
    build(1 ,1 , n) ;
    for(ll i(1) ; i <= q ; i = i + 1)
    {
        ll a , b ;
        cin >> a >> b;
            cout << Get_sum(1 , 1 , n , a , b) << "\n" ; 
    }
};
int main()
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ;
    return solve() , 0 ; 
}