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

#define LN 30

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll power[LN];
	power[0] = 3;
	for(ll i = 1; i < LN; i++){
		power[i] = (power[i-1]*4);
	}
	for(ll i = 1; i < LN; i++){
		power[i] += power[i-1];
		// cout << power[i] << " ";
	}
	// cout << endl;

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		if(n <= 3){
			cout << n << endl;
			continue;
		}

		ll i = 0;
		while(n-power[i] > 0){
			i++;
		}
		i--;

		n -= power[i];
		ll x = pow(4, i+1);
		// cout << n << " " << x << endl;

		if(n%3 == 1){
			cout << x + ((n-1)/3) << endl;
			continue;
		}

		ll a = x + (n-1)/3;
		x = a;
		ll b = 0;
		ll help = 1;
		while(x > 0){
			if(x%4 == 0){
				b += help*0;
			}
			else if(x%4 == 1){
				b += help*2;
			}
			else if(x%4 == 2){
				b += help*3;
			}
			else{
				b += help*1;
			}
			help *= 4;
			x /= 4;
		}

		ll c = (a^b);
		// cout << a << " " << b << " " << c << endl;
		if(n%3 == 2){
			cout << b << endl;
		}
		else{
			cout << c << endl;
		}
	}
}