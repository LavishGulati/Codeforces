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

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		ll si = 0, ei = 2023, mid, row, ans = n*n;
		while (si <= ei) {
			mid = (si + ei)/2;
			if (n > (mid*mid + 3*mid)/2 + 1) {
				si = mid+1;
			} else if (n < (mid*mid + mid)/2 + 1) {
				ei = mid-1;
			} else {
				row = mid;
				break;
			}
		}

		si = n; ei = n;
		while (row > 0) {
			si = si - (row+1);
			ei = ei - row;
			row--;
			ei = min(ei, (row*row + 3*row)/2 + 1);
			si = max(si, (row*row + row)/2 + 1);
			ans += (ei*(ei+1)*(2*ei+1))/6 - ((si-1)*si*(2*si-1))/6;
		}
		cout << ans << endl;
	}
}