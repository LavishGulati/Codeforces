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

#define MAX 500005
#define MOD 1000000007

int a[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, x;
	cin >> n >> x;

	for (int i = 0; i < MAX; i++) {
		a[i] = 0;
	}

	int y;
	for (int i = 0; i < n; i++) {
		cin >> y;
		a[y]++;
	}

	bool poss = true;
	for (int i = 1; i <= x-1; i++) {
		if (a[i]%(i+1) != 0) {
			poss = false;
			break;
		}

		a[i] /= i+1;
		a[i+1] += a[i];
	}

	if (poss && a[x] > 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}