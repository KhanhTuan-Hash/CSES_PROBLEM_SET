#include <bits/stdc++.h>
using namespace std ;

const char FREE = '.' ; 
const char RESERVED = '*' ; 
const char POS_QUEEN  = 'Q' ; 

map < int64_t  , int64_t > LOCK , DIAG , OPEN ; 
char res[8][8] ;
int64_t cnt(0) ; 

inline void Try(int64_t N , int64_t row)
{
    if(N == 0)
    {
        cnt = cnt + 1 ;
        return ; 
    }
    for(int64_t col = 0 ; col  < 8 ; col++)
    {
        if(DIAG[col] == 1) continue ; 
        bool flag_1 = res[row][col] == FREE ; 
        bool flag_2 = LOCK[row + col] == 0  ; 
        bool flag_3 = OPEN[row - col] == 0   ;
        if(flag_1 == true && flag_2 == true && flag_3 == true)
        {
            res[row][col] = POS_QUEEN; 
            DIAG[col] = LOCK[row + col] = OPEN[row - col] = 1 ;
            Try(N - 1 , row + 1)  ;
            res[row][col] = FREE ; 
            DIAG[col] = LOCK[row+col] = OPEN[row - col] = 0 ; 
        }
    }
}


int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ; 
    for(int64_t i = 0 ; i < 8 ;i++)
    {
        for(int64_t j = 0 ; j < 8; j++)
        {
            cin >> res[i][j]  ;
        }
    }
    Try(8 , 0)  ;
    return cout << cnt , 0  ;
}