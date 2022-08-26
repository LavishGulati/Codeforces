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

	ll x;
	cin >> x;

	vector<ll> primes;

	ll y = 1;
	while(x%2 == 0){
		y *= 2;
		x /= 2;
	}

	if(y != 1){
		primes.pb(y);
	}

	for(ll i = 3; i <= sqrt(x)+2; i += 2){
		y = 1;
		while(x%i == 0){
			y *= i;
			x /= i;
		}
		if(y != 1){
			primes.pb(y);
		}
	}

	if(x > 2){
		primes.pb(x);
	}

	sort(all(primes));

	for(ll i = 0; i < primes.size(); i++){
		cout << primes[i] << " ";
	}
	cout << endl;

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	pq.push(1);
	pq.push(1);

	for(ll i = primes.size()-1; i >= 0; i--){
		y = pq.top();
		pq.pop();
		y *= primes[i];
		pq.push(y);
	}

	cout << pq.top() << " ";
	pq.pop();
	cout << pq.top() << endl;
}