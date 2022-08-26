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

	ll *a = new ll[n];
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}

	if(n == 1){
		cout << "1 1\n0\n1 1\n0\n1 1\n" << -a[0] << endl;
		return 0;
	}

	cout << "1 " << n-1 << endl;
	for(ll i = 0; i < n-1; i++){
		cout << (n-1)*a[i] << " ";
		a[i] += (n-1)*a[i];
	}
	cout << endl;

	cout << "2 " << n << endl;
	for(ll i = 1; i < n-1; i++){
		cout << 0 << " ";
	}
	cout << (n-1)*a[n-1] << " ";
	a[n-1] += (n-1)*a[n-1];
	cout << endl;

	cout << "1 " << n << endl;
	for(ll i = 0; i < n; i++){
		cout << -a[i] << " ";
	}
	cout << endl;
}