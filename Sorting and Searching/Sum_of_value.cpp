#include <bits/stdc++.h>
using namespace std ;
const int64_t N = 1e5 ;
int64_t n , x ;
// Way_1 : two_pointer
/*int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ;
    vector  < pair < int64_t , int64_t > > Sp;
     cin >> n >> x ;
     for(int64_t i = 0 ; i < n ; i++)
     {
         int64_t val ; 
         cin >> val ; 
         Sp.push_back(make_pair(val , i + 1)) ; 
     }
     sort(Sp.begin() , Sp.end()) ; 
     int64_t  l(0) , r(n - 1) ;
     if(l > r) return 0 ;
     int64_t ans(0) ;   
     while(l < r)
     {
         int64_t sum = Sp[l].first + Sp[r].first  ;
         if(sum > x) --r ;
         if(sum < x) ++l;
         if(sum == x) 
         {
             cout << Sp[r].second  <<" "<< Sp[l].second <<"\n" ;
             return 0 ;  
         }
     }
     return cout << "IMPOSSIBLE"<<"\n" , 0 ; 
}*/
//Way2 : van dung ctdl co san map
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false);
    cerr.tie(0) ;
    cin >> n >> x;  
    map < int64_t , int64_t > m ; 
    for(int64_t i = 0 ; i < n ; i++)
    {
        int64_t val ;
        cin >> val ;
        int64_t diff = (x - val ) ;
        if(m.find(diff) != m.end())
        {
            cout << m[diff] + 1 << " " << i + 1 <<"\n" ;
            return 0 ; 
        }
        m[val] = i ; 
    }
    return cout << "IMPOSSIBLE\n" , 0 ; 
}