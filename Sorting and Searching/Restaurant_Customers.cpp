#include <bits/stdc++.h>
using namespace std ;

// A != B 

template <class T , class Y > inline bool maximize(T &a , Y b)
{
    if(a >= b) return false;
    a = b ; 
    return true ; 
}

int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false); 
    cerr.tie(0 ); 
    int64_t N_test ; 
    cin >> N_test ; 
    set < array < int64_t , 2 > > Sa ;
    for(int64_t i = 0 ; i < N_test ; i++)
    {
        int64_t A ,B ; 
        cin >> A >>  B; 
        Sa.insert({A << 1 , 1}) ; 
        Sa.insert({ B << 1 | 1 , -1}) ; 
    }
    pair < int64_t ,int64_t > ans { 0 , 0 } ;
    for(array< int64_t , 2 > C : Sa)
    {
        ans.first = ans.first + C[1] ; 
        maximize(ans.second , ans.first ) ; 
    }
    return cout << ans.second , 0 ; 
}