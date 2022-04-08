#include <bits/stdc++.h>
using namespace std ; 

// so buoc nho nhat di chuyen dc duoc la : 2^n - 1

int64_t n ;

inline void solve(int64_t n , int64_t col_1 , int64_t col_2 , int64_t col_3)
{
    if( n == 0) 
    {
        return ;  
    }
    solve(n - 1, col_1 , col_3 , col_2) ;
    cout << col_1 << " " << col_3 << "\n" ;
    solve( n - 1 , col_2 , col_1 , col_3) ; 
}

int main(int argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0)  ;
    cin >> n ;
    cout << (1 << n) - 1 << "\n"  ;
    solve(n , 1 , 2 , 3) , 0 ;
    return 0 ; 
}