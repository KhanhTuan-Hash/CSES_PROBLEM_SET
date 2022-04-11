
#include <bits/stdc++.h>

using namespace std ;  
 
template <class T , class V > inline bool maximize(T &a , V b)
{
    if(a >= b) return false ;
    a = b ;
    return true ; 
}
template <class T , class V > inline bool minimize(T &a , V b)
{
    if(a <= b) return false ;
    a = b ;
    return true ; 
}
 
const int64_t MAX_N = 1e5 ; 
#define oo LLONG_MAX
 
class Segment_tree
{
      int64_t N , Q ; 
      vector < int64_t > POS ; 
      public :
      Segment_tree(int64_t N)
      {
          this->N = N ; 
          this->POS.resize(4*N + 2) ; 
      }
      inline void build_tree(vector < int64_t > &A , int64_t index , int64_t L , int64_t R)
      {
          if(L == R)
          {
              POS[index] = A[L]  ; 
          }
          else 
          {
              int64_t MID = (L + R) >> 1; 
              build_tree(A , index << 1 , L , MID)  ;
              build_tree(A , index << 1 | 1 , MID + 1 , R) ; 
              POS[index]  = 0 ; 
           }
      }
      inline void update(int64_t index , int64_t L , int64_t R , int64_t U , int64_t V , int64_t VAL)
      {
          if(U > V) return ; 
          if(L == U and R == V)
          {
              POS[index] = POS[index] + VAL ; 
          }
          else 
          {
              int64_t MID = (L + R) >> 1; 
              update(index << 1 , L , MID , U , min(V , MID ) , VAL)  ;
              update(index << 1 | 1 , MID + 1 ,R , max(U , MID + 1 ) , V , VAL)  ;
          }
      }
      inline int64_t GET_VAL(int64_t index , int64_t L , int64_t R , int64_t K )
      {
          if(L == R)
          {
              return POS[index]  ;
          }
         int64_t MID = (L + R) >> 1; 
         if(K <= MID) return POS[index ] + GET_VAL(index << 1 ,L , MID , K) ;
         
          else return POS[index ] + GET_VAL(index << 1 | 1, MID + 1 , R , K) ; 
      }
} ; 
      inline void TEST_case()
      {
          int64_t N(0) , Q(0) ; 
          cin >> N >> Q ; 
          vector < int64_t> Arr(N)  ;
          for(int64_t &X : Arr) cin >> X ;
          Segment_tree St(N)  ; 
          St.build_tree(Arr , 1 , 0 , N - 1) ; 
          for(int64_t i = 0 ; i < Q ; i++)
          {
              int64_t T(0) ;
              cin >> T ; 
              if(T == 1)
              {
              int64_t a(0) , b(0) , u(0)  ;
              cin >> a >> b >> u ; 
              a-- , b-- ; 
              St.update(1 , 0 , N - 1, a, b, u) ; 
              }
              else
              {
                  int64_t k(0) ;
                  cin >>  k ; 
                  k--; 
                  cout << St.GET_VAL(1 , 0 , N - 1,k ) << "\n" ; 
              }
          }
      }
int main()
{
    cin.tie(0)->sync_with_stdio(false ) ;  
    cerr.tie(0)  ;
    return TEST_case() , 0 ; 
}