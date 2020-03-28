#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	ll total = 0;
	if(e > f){
		ll x = min(a, d);
		total += x*e;
		a -= x;
		d -= x;
		x = min(b, min(c, d));
		total += f*x;
	}
	else{
		ll x = min(b, min(c, d));
		total += x*f;
		b -= x;
		c -= x;
		d -= x;
		x = min(a, d);
		total += x*e;
	}

	cout << total << endl;
}