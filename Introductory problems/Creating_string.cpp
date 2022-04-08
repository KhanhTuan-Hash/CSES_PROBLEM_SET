#include <bits/stdc++.h>
using namespace std ;

int main()
{
    cin.tie(0)->sync_with_stdio(false) ;
    cerr.tie(0) ; 
    string s ;
    cin >> s ;
    sort(s.begin() , s.end()) ;
    vector  < string > ans ;
    do
    {
    ans.push_back(s)  ;
    } while (next_permutation(s.begin() , s.end()));
    cout << ans.size() << "\n" ; 
    for(string ch : ans)  cout << ch << "\n" ; 
    return  0 ;
}