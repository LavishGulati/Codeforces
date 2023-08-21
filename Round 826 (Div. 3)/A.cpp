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

#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;

		int n = a.length();
		int m = b.length();

		if (a == b) {
			cout << '=' << endl;
		} else if (a[0] == 'M') {
			if (b[m-1] == 'S') {
				cout << '>' << endl;
			} else {
				cout << '<' << endl;
			}
		} else if (b[0] == 'M') {
			if (a[n-1] == 'S') {
				cout << '<' << endl;
			} else {
				cout << '>' << endl;
			}
		} else if (a[n-1] == 'S' && b[m-1] == 'L') {
			cout << '<' << endl;
		} else if (a[n-1] == 'L' && b[m-1] == 'S') {
			cout << '>' << endl;
		} else if (a[n-1] == 'S') {
			if (n < m) {
				cout << '>' << endl;
			} else {
				cout << '<' << endl;
			}
		} else {
			if (n < m) {
				cout << '<' << endl;
			} else {
				cout << '>' << endl;
			}
		}
	}
}