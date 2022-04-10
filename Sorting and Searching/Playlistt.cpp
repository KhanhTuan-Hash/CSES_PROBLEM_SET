#include <bits/stdc++.h>
using namespace std ;
int64_t n ; 
int64_t p[200005]= {} ; 
template <class T , class Y > inline bool maximize(T &a , Y b)
{
    if(a >= b) return false;
    a = b ;
    return true; 
}
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ;
    cin >>  n ;
    memset(p , -1,sizeof(p) ) ; 
    map < int64_t , int64_t > um ;
    for(int64_t i = 0 ; i < n ; i++)
    {
        cin >> p[i] ;
    }
 //   sort(p , p + n) ;
    int64_t ans(0) ;
    for(int64_t i = 0 , j = 0 ; i < n ; i++)
    {
        while(j < n and um[p[j]] < 1) 
        {
            ++um[p[j]] ; 
            ++j ; 
        }
        maximize(ans , j - i ) ;
        --um[p[i]] ; 
    }
    return cout << ans , 0 ; 
 }