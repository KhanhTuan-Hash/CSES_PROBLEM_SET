#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;
int64_t n ,  k ; 
auto solve = [](int64_t n , int64_t k , set < int64_t > &S) -> void
{
     int64_t ans = 0 ;
     set < int64_t >::iterator iter ;
     while(S.size()> 0 )
     {
         ans  = (ans + k ) % (S.size()) ;  ; 
         iter = S.begin() ;
         advance(iter , ans)  ;
          cout << *iter << " " ;
         S.erase(iter) ;
     }
} ; 

template < class T > using ORDERED_SET = tree < T , null_type , less < T > , rb_tree_tag , tree_order_statistics_node_update > ; 
auto sub_2 = []() -> void
{
    cin >> n >>  k; 
    ORDERED_SET <int64_t > os ;
  
    for(int64_t i = 1; i <= n; i++) 
    {
        os.insert(i) ; 
    }
    
      int64_t ans = k % n ; 
    
    while(!os.empty())
    {
        int64_t node =  *os.find_by_order(ans ) ;
         
        os.erase(node) ; 
        cout << node << " " ; 
        if(!os.empty())
        {
            ans = (ans + k ) % (os.size()) ; 
        }
    }
} ; 
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false);  
    cerr.tie(0) ; 
    auto sub_1 = [&]() -> void
    { 
    int64_t n , k ; 
    set < int64_t > S ; 
    cin >> n >> k ;
    for(int64_t  i = 0 ; i < n ; i++)
    {
        S.insert(i + 1) ; 
    }
   solve( n , k , S) ; 
    } ; 
    /*if( n <= 7 )
    {
        sub_1() ;
    }
    else
    {
        sub_2() ; 
    }*/
    sub_2() ; 
     return  0 ; 
}