#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long, long> pll;

#define pb push_back
#define umap unordered_map
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll q, a, b, c;
	cin >> q;
	while(q--){
		cin >> a >> b >> c;
		ll answer = LLONG_MAX;
		for(ll i = -1; i <= 1; i++){
			for(ll j = -1; j <= 1; j++){
				for(ll k = -1; k <= 1; k++){
					ll _a = a+i;
					ll _b = b+j;
					ll _c = c+k;
					answer = min(answer, abs(_a-_b)+abs(_b-_c)+abs(_a-_c));
				}
			}
		}

		cout << answer << endl;
	}
}