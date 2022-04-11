#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll Seg[1 << 19]{} ;
ll A[200005]{} ;
ll n , m ;

inline void build(ll index , ll l , ll r)
{
    if(l == r)
    {
        Seg[index] = A[l] ; 
    }
    else 
    {
        ll mid = (l + r) >> 1 ;
        build(index << 1, l , mid) ;
        build(index << 1 | 1, mid + 1 , r) ; 
        Seg[index] = max(Seg[index << 1] , Seg[index << 1 | 1]) ;  
    }
}
inline void Get(ll val , ll index , ll l ,ll r)
{
    if( l == r)
    {
        Seg[index] = Seg[index] - val ;
        cout << l << " " ; 
    }
    else
    {
    ll mid = (l+r) >> 1 ;
    if(Seg[index << 1] >= val)
    {
        Get(val , index << 1 , l , mid) ;
    }
    else
    {
        Get(val , index << 1 | 1 , mid + 1 , r) ; 
    }
    Seg[index] = max(Seg[index << 1] , Seg[index << 1 | 1]) ; 
    }
}
inline void solve()
{
    cin >> n >> m ;
    for(ll i(1) ; i <= n ; i = i + 1) 
    {
        cin >> A[i] ;
    }
    build(1 ,1 , n) ;
    while(m--)
    {
        ll x ;
        cin >> x; 
        if(Seg[1] < x)
        {
            cout << 0 << " " ; 
        }
        else 
        {
            Get(x ,1 , 1 , n) ; 
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0);
    return solve() , 0; 
}