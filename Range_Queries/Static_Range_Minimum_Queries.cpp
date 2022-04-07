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

// Algorithm : Sparse  Table  for RMQ ;
// goi F[i][j]  : min num start from i  in the range has the length 2^ j [i... i + 1<<(j - 1)] ; 
// [i -- || --- j ] :subchia thanh 2 ranges  , range left = range right = 2^j - 1 
// vi vay theo chiu cua j thi chi co 2^19 =)) , log2
const int64_t LOG = 19 ;
const  int64_t N = 1e5; 
int64_t F[N << 1][LOG] ; 
int64_t LOG_G[N<< 1 | 1] ; 
int64_t n , query ; 
inline int64_t sol(int64_t l , int64_t r)
{
    return r - l + 1 ; 
}
inline void solve()
{
    cin >> n >> query ; 
    for(int64_t i = 0 ; i < n ; i++)
    {
        cin >> F[i][0] ; 
    }
    for(int64_t i = 1; i < LOG ; i++)
    {
        int64_t diff = n - (1 << i  )  + 1;  // r - l +1 -[l , r] == n - (1 << i) + 1 [1<<i - > n] ; 
         for(int64_t k = 0 ; k <= diff;  k++)
        {
            // i .. i + 2^j - 1
            F[k][i] = min(F[k][i - 1] , F[k + (1 << (i - 1))][i - 1]) ; 
        }
        // 8 - 1<<(1 - 1) = 7 ; 
    }
    // debug : 
   /* for(int64_t i = 1;  i <= N ; i++)
    {
        for(int64_t k = 0 ; (1 << k) <= N ; k++)
        {
            cout << i << " " << k <<" " << F[k][i] ; 
        }
    }*/

    for(int64_t i = 0 ; i < query ; i++)
    {
        int64_t A , B ;
        cin >> A >> B ;
       A-- , B--; 
       int64_t Range = sol(A , B) ;  
       int64_t Sqrtx = log2(Range) ;  
       int64_t res = min (F[A][Sqrtx] , F[B - ((1 << Sqrtx)) + 1][Sqrtx]) ; 
       cout << res << "\n" ; 
    }
}


// segment _tree
int64_t SEGMENT_TREE[200005*4]  ; 
inline void build_tree(int64_t pos[] , int64_t index , int64_t L , int64_t R )
{
    if(L == R)
    {
        SEGMENT_TREE[index] = pos[L] ; 
        return ; 
    }
    int64_t MID = (L + R )>> 1 ; 
    pair < int64_t , int64_t > node ;
    node.first = index << 1 | 1; 
    node.second = (index << 1) + 2 ;  
    build_tree(pos , node.first, L , MID  ) ;
    build_tree(pos , node.second ,  MID + 1, R) ; 
    SEGMENT_TREE[index] = min (SEGMENT_TREE[node.first ]  ,  SEGMENT_TREE[node.second]) ; 
} 

inline int64_t GET_MIN(int64_t query_L , int64_t query_R , int64_t L , int64_t R , int64_t index)
{
    if(query_L > R || query_R < L) return LLONG_MAX ; 
    if(query_L <= L && query_R >= R)
    {
        return SEGMENT_TREE[index]  ;
    }
    tuple < int64_t , int64_t  , int64_t > cur ;
    get<0>(cur) = (L+R) >> 1 ;
    get<1>(cur) = index << 1 | 1 ; 
     get<2>(cur) = (index << 1 )+ 2 ;  
    pair < int64_t , int64_t > node; 
    node.first = GET_MIN(query_L , query_R , L , get<0>(cur) , get<1>(cur)) ; 
    node.second = GET_MIN(query_L , query_R , get<0>(cur) + 1 , R ,  get<2>(cur)) ; 
    return min(node.first , node.second)  ; 
}
inline void Solve()
{
    int64_t T , Q ; 
    cin >>T >> Q ; 
    int64_t pos[T] ; 
    for(int64_t i = 0;  i <  T; i++) cin >>pos[i] ; 
    build_tree(pos , 0 , 0 , T - 1)  ; 
    for(int64_t i = 0 ; i < Q ; i++)
    {
        pair < int64_t , int64_t > side ;
        cin >> side.first >> side.second ;
         cout << GET_MIN(side.first - 1 , side.second - 1 , 0 , T - 1 , 0 )  << "\n" ; 
    } 
}

int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false); 
    //solve() ; 
   Solve() ; 
    assert(true) ; 
    return 0 ; 
}