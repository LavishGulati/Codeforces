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

	ll q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;

		ll help = 3, x = 1;
		while(x < n){
			x += help;
			help *= 3;
		}

		while(help > 0){
			if(x - help >= n){
				x -= help;
			}
			help /= 3;
		}
		cout << x << endl;
	}
}