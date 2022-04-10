#include<bits/stdc++.h>
using namespace std ;
int64_t n ; 
int32_t main(int argc,char const *argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ;
    cin >> n ;
    vector < int64_t > a;
    for(int64_t i = 0 ;  i < n ; i++)
    {
        int64_t x ;
        cin >> x;
        int64_t iter = upper_bound (a.begin() , a.end() , x) - a.begin() ;
        if(iter < a.size())
        {
            a[iter] = x; 
        }
        else
        {
            a.push_back(x); 
        }
    }
    return cout << a.size()<< "\n",  0 ; 
    }