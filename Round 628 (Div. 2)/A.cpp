#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t, x;
	cin >> t;
	while(t--){
		cin >> x;
		x--;

		ll a = 1;
		while(x%2 == 0){
			a *= 2;
			x /= 2;
		}

		cout << a << " " << x << endl;
	}
}