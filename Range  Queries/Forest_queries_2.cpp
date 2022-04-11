#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair < ll , ll > node ; 

ll dp[1 << 12][1 << 12] ={} ;   

ll n , q ; 
// '.' : empty square  , '*':  tree 
// l_1 ,r _ 1 : tung 
// l_2 , r-2  : hoanh 
// index_1 : hoanh , index_2 : tung
inline void build_Y(ll l_1 , ll r_1 , ll l_2 , ll r_2 , ll index_y1 , ll index_y2 )
{
     if(l_1 == r_1)
     {
         if(l_2 == r_2)
         {
             char s ;
             cin >> s ;
             dp[index_y1][index_y2] = ((s == '*' && s != '.') ? 1 : 0 ) ; 
         }
         else 
        {
              dp[index_y1][index_y2] = dp[index_y1 << 1][index_y2] + dp[index_y1 << 1 | 1][index_y2]  ; 
        }
        return ; 
     }
     ll mid = (l_1 + r_1) >> 1 ;
     build_Y(l_1 , mid , l_2 , r_2 , index_y1 , index_y2 << 1)  ;
     build_Y(mid + 1 , r_1 , l_2 , r_2 , index_y1 , index_y2 << 1 | 1)  ; 
     dp[index_y1][index_y2] = dp[index_y1][index_y2 << 1] + dp[index_y1][index_y2 << 1 | 1]  ; 
     return  ; 
}
inline void build_X(ll l_2 , ll r_2 , ll l_1 , ll r_1 , ll index_y1)
{
   if(l_2 == r_2)
   {
       //change : 
       build_Y(l_1 , r_1 , l_2 ,r_2 , index_y1 , 0 )  ; 
       return ; 
   }
   ll mid = (l_2+ r_2  ) >> 1 ;
   build_X(l_2 , mid , l_1 , r_1 , index_y1 << 1)  ;
   build_X(mid + 1 , r_2 , l_1 , r_1 , index_y1 << 1 | 1) ; 
   build_Y(l_1 , r_1 , l_2 , r_2  ,index_y1 , 0 ) ; 
   return ; 
}
inline void update_Y(ll l_1 , ll r_1 , ll val_y , ll l_2 , ll r_2 , ll index_y1 , ll index_y2)
{
    if(l_1 == r_1)
    {
        dp[index_y1][index_y2] = ((l_2 == r_2 ) ? (1 - dp[index_y1][index_y2]) : 
                                    (dp[index_y1 << 1][index_y2] + dp[index_y1 << 1 | 1][index_y2])) ; 
        return ; 
    }
    ll mid = (l_1 + r_1 ) >> 1 ;
    if(val_y <= mid)
    {
        update_Y(l_1 , mid ,val_y , l_2 ,r_2 , index_y1 , index_y2 << 1 ) ; 
    }
    else 
    {
        update_Y(mid + 1 , r_1 , val_y , l_2 , r_2 , index_y1 , index_y2 << 1 | 1) ; 
    }
    dp[index_y1][index_y2] = dp[index_y1][index_y2 << 1] + dp[index_y1][index_y2 << 1 | 1] ;  
    return  ; 
}
inline void update_X(ll l_2 , ll r_2 , ll l_1 , ll r_1 , ll val_x , ll val_y ,  ll index_y1 )
{
    if(l_2 == r_2 )
    {
        update_Y(l_1 , r_1 , val_y , l_2 , r_2 , index_y1 , 0 ) ; 
        return ; 
    }
    ll mid = (l_2 + r_2 ) >> 1 ;
    if(val_x <= mid)
    {
        update_X(l_2 , mid , l_1 , r_1 , val_x , val_y , index_y1 << 1) ; 
    }
    else 
    {
        update_X(mid + 1, r_2 , l_1 , r_1 , val_x , val_y , index_y1 << 1 | 1) ; 
    }
    update_Y(l_1 , r_1 , val_y , l_2 , r_2 , index_y1 , 0 ) ; 
    return ; 
}
inline ll Get_forest_Y(ll l_1 , ll r_1 , ll y1 , ll y2 , ll index_y1 , ll index_y2)
{
    if(y1 > r_1 || y2  < l_1 ) return 0LL;
    if(y1 <= l_1 && y2 >= r_1 )
    {
        return dp[index_y1][index_y2] ; 
    }
    ll mid = (l_1 + r_1 ) >> 1; 
    ll L = Get_forest_Y(l_1 , mid , y1 , y2 , index_y1 , index_y2 << 1) ;
    ll R = Get_forest_Y(mid + 1 , r_1 , y1 , y2 , index_y1 , index_y2 << 1 | 1) ; 
    return (L + R ) ;  
}
inline ll Get_forest_X(ll l_2 , ll r_2 , ll l_1 , ll r_1 , ll x1 , ll y1 , ll x2 , ll y2 , ll index_y1)
{
    if(x1 > r_2 || x2 < l_2) return 0LL ;
    if(x1 <= l_2 && x2 >= r_2)
    {
         return Get_forest_Y(l_1 , r_1 , y1 , y2, index_y1 , 0 ) ; 
    }
    ll mid  = (l_2 + r_2 ) >> 1; 
    ll L = Get_forest_X(l_2 , mid , l_1 , r_1 ,x1 , y1 , x2 , y2 , index_y1 << 1) ; 
    ll R = Get_forest_X(mid + 1 , r_2 , l_1 , r_1 , x1 , y1 , x2 , y2 , index_y1 << 1| 1) ; 
    return (L +  R) ; 
}
auto solve =[]() -> void
{
   cin >> n >> q ;
   build_X(1 , n , 1 , n , 0 ) ;
   while(q--)
   {
       ll t ;
       cin >> t ;
       if(t == 1)
       {
           ll x , y ;
           cin >> x >> y; 
           update_X(1 , n ,1 , n , x , y , 0 )  ; 
       }
       else 
       {
           ll x1 , y1 , x2 , y2  ;
           cin >> x1 >> y1 >> x2 >> y2 ; 
           cout << Get_forest_X(1 , n , 1 , n , x1 , y1 , x2 , y2 , 0  ) << "\n" ; 
       }
   }
};
int main()
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ;
    return solve() , 0 ; 
}