// HASHING 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std ;

const int64_t MOD[] = {(int64_t)(1e9+7) , (int64_t)(1e9+9)} ; 
const int64_t lim_hash[] = {29 , 31} ; 
const int64_t N = 1e6 ; 
int64_t A[2][N + 2] , HASH_first[2][N + 2] , HASH_second[2][N + 2] ; 

inline void ADD_self(int64_t &X , int64_t Y , int64_t MOD)
{
    X = X + Y ; 
    if(X >= MOD)
    {
        X = X - MOD ; 
    }
}
inline int64_t ADD_start(int64_t X , int64_t Y , int64_t MOD )
{
    ADD_self(X , Y , MOD) ; 
    return X;  
}
inline void ADD_multseft(int64_t &X , int64_t Y , int64_t MOD)
{
    X = (int64_t ) X*Y % MOD ; 
}
inline int64_t ADD_end(int64_t X , int64_t Y , int64_t MOD)
{
    ADD_multseft(X , Y , MOD) ;
    return X ; 
}
inline void ADD_maxself(int64_t &X , int64_t Y)
{
    if(X < Y)
    {
        X = Y ; 
    }
}
inline void ADD_minself(int64_t &X , int64_t Y)
{
    if(X > Y)
    {
        X = Y ; 
    }
}
void PRE_COMPUTE() 
{
  for(int64_t j = 0 ; j < 2 ; j++)
    {
        A[j][0] = 1 ;
        for(int64_t i = 1 ; i <= N; i++)
        {
            A[j][i] = ADD_end(A[j][i - 1] , lim_hash[j] , MOD[j]) ; 
        }
    }
}
pair<int64_t, int64_t> getHash1(int64_t l, int64_t r) {
  int64_t res[2];
  for (int64_t i = 0; i < 2; ++i) {
    res[i] = ADD_start(HASH_first[i][r], MOD[i] - ADD_end(HASH_first[i][l - 1], A[i][r - l + 1], MOD[i]), MOD[i]);
  }
  return {res[0], res[1]};
}
 

 pair<int64_t, int64_t> getHash2(int64_t l, int64_t r) {
  int64_t res[2];
  for (int64_t i = 0; i < 2; ++i) {
    res[i] = ADD_start(HASH_second[i][r], MOD[i] - ADD_end(HASH_second[i][l - 1], A[i][r - l + 1], MOD[i]), MOD[i]);
  }
  return {res[0], res[1]};
}
 
inline bool Is_Palindrome(int n, int l, int r) {
  if (l == 0) {
    return false;
  }
  return getHash1(l, r) == getHash2(n - r + 1, n - l + 1);
}
inline void CASE()
{
    string s ;
     cin >> s; 
     string str  = s ;
     pair < int64_t , int64_t > __size ; 
     __size.first = s.size() ;
    __size.second = str.size() ; 
    reverse(str.begin() , str.end()) ; 
    s = '!' + s ;
    str = '#' + str ; 
    for(int64_t i = 1; i <= __size.first ; i++)
    {
        for(int64_t j = 0; j < 2 ; j++)
        {
            HASH_first[j][i] = ADD_start(ADD_end(HASH_first[j][i - 1] , lim_hash[j] , MOD[j]) , s[i] - 'a' + 1 , MOD[j]) ;  
            HASH_second[j][i] = ADD_start(ADD_end(HASH_second[j][ i- 1] , lim_hash[j] , MOD[j]) , s[i] - 'a' + 1 , MOD[j]) ; 
        }
    }
    int64_t result(0) , temp(1) ;
    pair < int64_t ,int64_t  > rem ; 
    for(int64_t mask = 1 ; mask <=  __size.first ; mask++)
    {
        temp = temp - 1 ;
        while(!Is_Palindrome(__size.first , temp , mask))
        {
            temp = temp + 1 ; 
        }
        ADD_maxself(result , mask - temp + 1) ; 
        if(result == mask - temp + 1)
        {
            rem = {temp , mask} ; 
        }
    }
    for(int64_t i = rem.first ; i <= rem.second ;i++)
    {
        cout << s[i] ; 
    }
    cout << "\n" ; 
}
int32_t main(int32_t argc,char*argv[])
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ; 
    PRE_COMPUTE() ; 
    int64_t n_test(1) ;
    for(cin >> n_test ; n_test--; )
    {
        CASE() ; 
    }
    assert(true) ;
    return 0 ; 
}
/*
#include <bits/stdc++.h>
 
using namespace std;
 
const int mod[] = {(int)1e9 + 7, (int)1e9 + 9};
const int base[] = {29, 31};
const int kN = 1e6;
int p[2][1 + kN], h1[2][1 + kN], h2[2][1 + kN];
 
void addSelf(int &x, int y, int mod) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
}
 
int add(int x, int y, int mod) {
  addSelf(x, y, mod);
  return x;
}
 
void multSelf(int &x, int y, int mod) {
  x = (int64_t)x * y % mod;
}
 
int mult(int x, int y, int mod) {
  multSelf(x, y, mod);
  return x;
}
 
void maxSelf(int &x, int y) {
  if (x < y) {
    x = y;
  }
}
 
void precalc() {
  for (int j = 0; j < 2; ++j) {
    p[j][0] = 1;
    for (int i = 1; i <= kN; ++i) {
      p[j][i] = mult(p[j][i - 1], base[j], mod[j]);
    }
  }
}
 
pair<int, int> getHash1(int l, int r) {
  int res[2];
  for (int i = 0; i < 2; ++i) {
    res[i] = add(h1[i][r], mod[i] - mult(h1[i][l - 1], p[i][r - l + 1], mod[i]), mod[i]);
  }
  return {res[0], res[1]};
}
 
pair<int, int> getHash2(int l, int r) {
  int res[2];
  for (int i = 0; i < 2; ++i) {
    res[i] = add(h2[i][r], mod[i] - mult(h2[i][l - 1], p[i][r - l + 1], mod[i]), mod[i]);
  }
  return {res[0], res[1]};
}
 
 
bool isPal(int n, int l, int r) {
  if (l == 0) {
    return false;
  }
  return getHash1(l, r) == getHash2(n - r + 1, n - l + 1);
}
 
void testCase() {
  string s;
  cin >> s;
  string t = s;
  reverse(t.begin(), t.end());
  int n = s.size();
  s = '$' + s;
  t = '$' + t;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      h1[j][i] = add(mult(h1[j][i - 1], base[j], mod[j]), s[i] - 'a' + 1, mod[j]);
      h2[j][i] = add(mult(h2[j][i - 1], base[j], mod[j]), t[i] - 'a' + 1, mod[j]);
    }
  }
  int ans = 0, l = 1;
  pair<int, int> ret;
  for (int r = 1; r <= n; ++r) {
    l -= 1;
    while (!isPal(n, l, r)) {
      l += 1;
    }
    maxSelf(ans, r - l + 1);
    if (ans == r - l + 1) {
      ret = {l, r};
    }
  }
  for (int i = ret.first; i <= ret.second; ++i) {
    cout << s[i];
  }
  cout << '\n';
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  precalc();
  int tests = 1;
  for (int tc = 0; tc < tests; ++tc) {
    testCase();
  }
  return 0;
}
*/