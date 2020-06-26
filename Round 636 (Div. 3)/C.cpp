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
		cin >> n;

		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		bool sign;
		if(a[0] > 0){
			sign = true;
		}
		else{
			sign = false;
		}

		int el = a[0];
		ll sum = 0;
		for(int i = 1; i < n; i++){
			if(a[i] > 0 && sign){
				el = max(el, a[i]);
			}
			else if(a[i] < 0 && sign){
				sign = false;
				sum += el;
				el = a[i];
			}
			else if(a[i] < 0 && !sign){
				el = max(el, a[i]);
			}
			else{
				sign = true;
				sum += el;
				el = a[i];
			}
		}

		sum += el;
		cout << sum << endl;
	}
}