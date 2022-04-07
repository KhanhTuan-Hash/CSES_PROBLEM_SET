#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <assert.h> 

using namespace std ;

template <class T , class Y > inline bool maximize(T &a , Y b)
{
    if(a >= b) return false ;
    a = b ;
    return true ; 
}
template <class T , class Y > inline bool minimize(T &a , Y b)
{
    if(a <= b) return false ;
    a = b ;
    return true ; 
}
const int64_t N = 2e5 ; 
vector < int64_t > SEGMENT_TREE(4*N)  ; 

inline void BUILD_TREE(vector < int64_t > &a , int64_t index , int64_t L , int64_t R)
{
    if(L == R)
    {
        SEGMENT_TREE[index] = a[L] ; 
        return  ; 
    }
    int64_t MID = (L+R ) >> 1 ;
    pair < int64_t , int64_t > node ;
     node.first = index << 1 | 1 ; 
     node.second = (index << 1 ) + 2 ; 
    BUILD_TREE(a , node.first , L , MID) ;
    BUILD_TREE(a , node.second , MID + 1 , R) ; 
    SEGMENT_TREE[index] = (SEGMENT_TREE[node.first] + SEGMENT_TREE[node.second] ); 
}

inline int64_t GET_SUM(int64_t index , int64_t U , int64_t V , int64_t L , int64_t R)
{
    if(R < U || L > V) return LLONG_MAX ;
    if(L >= U && R <= V) 
    {
        return SEGMENT_TREE[index] ; 
    }
    int64_t MID = (L+R) >> 1 ;
    pair < int64_t , int64_t > node ; 
    node.first  = index << 1 | 1  ; 
      node.second = (index << 1) + 2 ; 
     pair < int64_t , int64_t > res ;
    res.first = GET_SUM(node.first , U , V , L , MID) ;
    res.second = GET_SUM(node.second , U , V , MID + 1 , R) ; 
    return min(res.first ,res.second) ; 
}


inline int64_t UPDATE(int64_t index , int64_t L , int64_t R , int64_t LIM , int64_t VAL)
{
    if(LIM < L || LIM > R) 
    {
        return SEGMENT_TREE[index]; 
    }
    if(L == R) 
    {
        if(L == LIM) SEGMENT_TREE[index] = VAL ;  
        return SEGMENT_TREE[index] ; 
    }
      int64_t MID = (L+R) >> 1 ;
    pair < int64_t , int64_t > node ; 
    node.first = index << 1 | 1 ;  
    node.second = (index << 1) + 2 ; 
    pair < int64_t , int64_t > res ;
    res.first = UPDATE(node.first , L , MID , LIM , VAL) ;
    res.second = UPDATE(node.second , MID + 1 , R , LIM , VAL) ; 
    return SEGMENT_TREE[index] = min(res.first ,  res.second ); 
}
// o truy van thu hai tim min trong doan get_min giong bai min_in_range_queries 

inline void solve()
{
    int64_t n , q ;
    cin >> n >> q ; 
    vector < int64_t > a(n) ; 
    for(int64_t i = 0; i < n ; i++) 
    {
        cin >> a[i] ; 
        UPDATE( 0 , 0 , n - 1 , i , a[i]) ; 
    }
  //  BUILD_TREE(a , 0 , 0, n - 1 ) ; 
   while(q-->0)
   {
       int64_t x ; 
       cin >> x ;
       int64_t l ,r ;
       cin >> l >> r ;
       if(x == 1)
       {
           UPDATE(0, 0 , n-1 , l - 1 , r) ; 
       } 
       else
       {
            cout << GET_SUM(0 , l -1 , r - 1, 0 , n - 1) << "\n" ; 
       }
   }
}

int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ; 
    solve() ;
    assert(true) ; 
    return 0; 
}
