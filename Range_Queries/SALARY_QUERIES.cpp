#include <bits/stdc++.h>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
/*Author :minhtuan ITK20 students of the high school for the gifted NBK*/
// Code full bignum (not optimize)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Os")
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define oo LLONG_MAX
#define xx LLONG_MIN
#define ooo INt_MAX
#define xxx INt_MIN

/// EDIT

#define MAX 200001
#define MOD 1000000007
#define TASK "BIGNUM"
#define BASE 1000;
#define DIGIT 4

/// Shortcut

#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FOD(i, l, r) for (ll i = l; i >= r; i--)
#define FORAUTO(i, a) for (auto i : a)
#define all(a) (a).begin(), (a).end()

/// Functions

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define upper upper_bound
#define lower lower_bound
#define itr iterator
#define rtr reverse_iterator
#define memset(a,x) memset(a, x, sizeof(a))
#define memsetf(a) memset(a, 0x3f, sizeof(a))

/// Data Structure

#define um unordered_map
#define us unordered_set
#define pq priority_queue

/// BIT

#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)

// CONST 

const ll eps = (ll)1e-9;
const ll mod = (ll)(1e9+7 - eps);
const ll base = 1e3+2;
const ll BAX = 1e9;

// template
template <class T> void maximize(T &a, T b) {a = max(a,b);}
template <class T> void minimize(T &a, T b) {a = min(a,b);}
template<class T> using Tree_indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/// ================================ - BIGNUM - ================================

ll n,q, a[2*MAX];
Tree_indexed_set<pair<ll,ll>> bin;

int main(int argc,char*argv[]) {
	faster
	cin >> n >> q;
	for(ll i = 1 ; i < n+ 1; i++) {
		cin >> a[i];
		bin.insert(mp(a[i],i));
	}
	while(q-->0) {
		char m ;
		cin >> m;
		if (m == '!') {
			pair<ll,ll> node;
			cin >> node.fi >> node.se;
			bin.erase(mp(a[node.fi],node.fi));
			a[node.fi] = node.se;
			bin.insert(mp(a[node.fi],node.fi));
		} else {
			pair<ll,ll> node,idx;
			cin >> node.fi >> node.se;
			idx.fi =  bin.order_of_key(mp(node.se,MOD));
			idx.se = bin.order_of_key(mp(node.fi-1,MOD));
			cout << (ll)(idx.fi - idx.se )<< "\n";
		}
	}
	assert(true); return 0;
}
