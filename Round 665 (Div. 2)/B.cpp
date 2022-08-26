#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pq priority_queue

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll a[3];
		cin >> a[0] >> a[1] >> a[2];

		ll b[3];
		cin >> b[0] >> b[1] >> b[2];

		ll temp = min(a[2], b[1]);
		ll ans = temp*2;
		a[2] -= temp;
		b[1] -= temp;

		temp = min(a[1], b[1]);
		a[1] -= temp;
		b[1] -= temp;

		temp = min(a[2], b[2]);
		a[2] -= temp;
		b[2] -= temp;

		temp = min(a[1], b[0]);
		a[1] -= temp;
		b[0] -= temp;

		temp = min(a[0], b[2]);
		a[0] -= temp;
		b[2] -= temp;

		temp = min(a[1], b[2]);
		ans -= temp*2;
		a[1] -= temp;
		b[2] -= temp;

		cout << ans << endl;
	}
}