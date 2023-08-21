#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair< int, pair<int, int> > tii;
typedef pair< long long, pair<long long, long long> > tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MAX 270000
#define MOD 1000000007

int a[MAX];

struct Node {
	int val;
	int low;
	int high;

	Node (int v, int l, int h) {
		val = v;
		low = l;
		high = h;
	}
};

Node solve(int l, int r) {
	if (r == l+1) {
		if (a[l] < a[r]) {
			return Node(0, a[l], a[r]);
		} else {
			return Node(1, a[r], a[l]);
		}
	}

	Node left = solve(l, l+(r-l)/2);
	Node right = solve(l+(r-l)/2+1, r);
	if (left.val == -1 || right.val == -1) {
		return Node(-1, INT_MAX, INT_MIN);
	}

	if (left.high < right.low) {
		return Node(left.val+right.val, min(left.low, right.low), max(left.high, right.high));
	}
	swap(left, right);
	if (left.high < right.low) {
		return Node(1+left.val+right.val, min(left.low, right.low), max(left.high, right.high));
	} else {
		return Node(-1, INT_MAX, INT_MIN);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		if (n == 1) {
			cout << 0 << endl;
			continue;
		}

		cout << solve(0, n-1).val << endl;
	}
}