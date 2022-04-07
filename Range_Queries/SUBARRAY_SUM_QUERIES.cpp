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
using ld = long double;

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define oo LLONG_MAX
#define xx LLONG_MIN
#define ooo INT_MAX
#define xxx INT_MIN

/// EDIT

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
#define po pop_back
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
const ll MAX = 200001;

// template
template <class T> void maximize(T &a, T b) {a = max(a,b);}
template <class T> void minimize(T &a, T b) {a = min(a,b);}
template<class T> using Tree_indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/// ================================ - BIGNUM - ================================

struct Node {
	ll gmax ,  left_max,right_max, sum;
	Node operator +(Node b) {
		return {
			max(max(gmax, b.gmax),right_max + b.left_max),
			max(left_max, sum + b.left_max),
			max(b.right_max, right_max + b.sum),
			sum + b.sum
		};
	}
};

ll n, a[MAX];
Node S_tree[4 * MAX];

void build(ll l = 1, ll r = n, ll node = 1) {
	if (l == r) S_tree[node] = {max(0ll, a[l]), max(0ll, a[l]), max(0ll, a[l]), a[l]};
	else {
		ll mid = (l + r) >> 1;
		build(l, mid, node << 1);
		build(mid + 1, r, (node << 1) + 1);
		S_tree[node] = S_tree[node << 1] + S_tree[(node << 1) + 1];
	}
}
void update(ll pos, ll val, ll l = 1, ll r = n, ll node = 1) {
	if (l == r) S_tree[node] = {max(0ll, val), max(0ll, val), max(0ll, val), val};
	else {
		ll mid = (l + r) >> 1;
		if (pos > mid) update(pos, val, mid + 1, r, (node << 1) + 1);
		else update(pos, val, l, mid, node << 1);
		S_tree[node] = S_tree[node << 1] + S_tree[(node << 1) + 1];
	}
}

int main(int argc,char*argv[]) {
	faster
	ll q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build();

	while (q--) {
	    pair<ll,ll> res; cin >> res.fi >> res.se;
		update(res.fi,res.se);
		cout << S_tree[1].gmax << '\n';
	}
	return 0;
}
