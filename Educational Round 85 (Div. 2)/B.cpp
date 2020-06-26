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

	int t;
	cin >> t;
	while(t--){
		int n;
		double x;
		cin >> n >> x;

		double *a = new double[n];
		double sum = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
		}

		sort(a, a+n);

		if(a[n-1] < x){
			cout << 0 << endl;
			continue;
		}

		for(ll i = 0; i < n; i++){
			if(sum/(n-i) >= x){
				cout << (n-i) << endl;
				break;
			}
			sum -= a[i];
		}
	}
}