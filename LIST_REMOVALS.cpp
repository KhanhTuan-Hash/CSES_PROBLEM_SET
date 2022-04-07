#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*Author :minhtuan ITK20 students of the high school for the gifted NBK*/
// Code full bignum (not optimize)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Os")
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#include <assert.h>

using namespace std;
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

// template
template <class T> void maximize(T &a, T b) {a = max(a,b);}
template <class T> void minimize(T &a, T b) {a = min(a,b);}
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/// ================================ - BIGNUM - ================================
//use the indexed set

int main (int argc,char*argv) {
    faster
	int n;
	cin >> n;
	Tree<int> ist;
	vector<int> Remo(n);
	for (int i = 0; i < n; i++) {
		ist.insert(i);
		cin >> Remo[i];
	}
	for (int i = 0; i < n; i++) {
		int ind;
		cin >> ind;
		ind--;
		int pos = *ist.find_by_order(ind);
		ist.erase(pos);
		cout << Remo[pos] << (i == n - 1 ? '\n' : ' ');
	}
	assert(true);
	return 0;
}
