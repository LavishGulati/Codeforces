#include <bits/stdc++.h>
using namespace std;

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
		ll n;
		cin >> n;

		n /= 2;

		if(n%2){
			cout << "NO" << endl;
			continue;
		}

		cout << "YES" << endl;
		for(ll i = 0; i < n; i++){
			cout << ll((i+1)*2) << " ";
		}

		ll sum = n*(n+1);
		for(ll i = 0; i < n-1; i++){
			cout << ll(2*i+1) << " ";
			sum -= 2*i+1;
		}
		cout << sum << endl;
	}
}