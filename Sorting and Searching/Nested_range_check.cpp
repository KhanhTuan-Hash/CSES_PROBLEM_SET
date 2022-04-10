/*#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std; 

typedef pair < int64_t , int64_t > pi64 ; 

#define FORAUTO(i , a) for(auto i : a) 
 
template <class T > using OS = tree < T , null_type , less< T > , rb_tree_tag ,
                                                        tree_order_statistics_node_update > ; 


 int32_t main(int32_t argc,char*argv[])
 {
     cin.tie(0)->sync_with_stdio(false) ;
     cerr.tie(0 ) ;
     int64_t N_test(1) ; 
      while(N_test-->0)
      {
          int64_t n ; 
          cin >> n ;
          vector < int64_t > A(n), B(n) ; 
          OS < pi64 > b , c; 
          vector < array   <int64_t , 3 > > a(n) ; 
          for(int64_t i = 0; i < n ; i++)
          {
              cin >> a[i][0] >> a[i][1]  ; 
              a[i][2] = i  ;
          }
          sort(a.begin() , a.end() , [&](const array < int64_t , 3 > x , const array < int64_t , 3 > y)
          {
              return ((x[0] < y[0]) or (x[0] == y[0] and x[1] > y[1])) ; 
          } ) ; 

      // FORAUTO(e , a)
       //{
         //  cerr << e[0] <<" " << e[1] << " "<< e[2] <<"\n" ;  
       //}

       for(int64_t i(0) , j(n - 1);  i < n ; i = i + 1 , j = j + 1)
       {
           A[a[j][2]] = c.order_of_key({a[j][1] + 1, -1}) ; 
           c.insert({a[j][1], i} ) ; 
       }
        for(int64_t i(0) ; i  < n ;  i = i + 1)
        {
            B[a[i][2]] = i - b.order_of_key({a[i][1] , -1}) ; 
            b.insert({a[i][1] , i}) ; 
        }
        for(int64_t i = 0 ; i < n ; i++)
        {
            cout << (A[i] >  0) << " " ; 
        }
        cout << "\n" ; 
        for(int64_t i = 0 ; i < n ; i++)
        {
            cout << (B[i] > 0) << " " ;
        }
        cout << "\n" ; 
      } 
     return  0 ; 
      }*/
      #include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl ("\n")
#define int long long
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define ar array
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
//oset<int>s:s.find_by_order(k):Kth element in "s",s.order_of_key(k):Number of item strictly lessthan k
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
 
 
int32_t main(){
    fastio
    //cout<<setprecision(20)<<fixed ;
    int t=1;
    // cin>>t;
    while(t--){
        int n;cin>>n;
        oset<pair<int, int>>b,c;
        vector<array<int,3>>a(n);
        vector<int>aa(n),bb(n) ;
        rep(i, n)cin>>a[i][0]>>a[i][1],a[i][2]=i;
    
        sort(a.begin(),a.end(),[&](const ar<int,3> i,const ar<int,3>j){
            return ((i[0]<j[0])||(i[0]==j[0]&&i[1]>j[1]));
        });
  
  
        // for(auto i:a){
        //     cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        // }
  
        for(int i=0,j=n-1;i<n;i++,j--){
            aa[a[j][2]]=c.order_of_key({a[j][1]+1,-1}) ;
            c.insert({a[j][1],i});
        }
        
        for(int i=0;i<n;i++){
            bb[a[i][2]]=i-b.order_of_key({a[i][1],-1});
            b.insert({a[i][1],i});
        }
 
        rep(i, n)cout<<(aa[i]>0)<<" ";cout<<endl;
        rep(i, n)cout<<(bb[i]>0)<<" ";cout<<endl;
    }
    return 0;
}