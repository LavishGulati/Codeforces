#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
typedef pair<long long, pair<long long, long long>> tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	ll *a = new ll[n], help = 0;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		help += abs(a[i]-1);
	}
	sort(a, a+n);

	ll ans = LLONG_MAX, sum = 0, x;
	for(ll i = 1; pow(i, n-1) <= a[n-1]+help; i++){
		x = 1;
		sum = 0;
		for(ll j = 0; j < n; j++){
			sum += abs(a[j]-x);
			x *= i;
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
}