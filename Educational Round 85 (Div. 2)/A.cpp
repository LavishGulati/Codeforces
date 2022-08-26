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

	bool ans;
	while(t--){
		int n;
		cin >> n;

		ans = true;
		pii *a = new pii[n];
		for(int i = 0; i < n; i++){
			cin >> a[i].f >> a[i].s;
		}
		if(a[0].s > a[0].f){
			cout << "NO" << endl;
			continue;
		}

		for(int i = 1; i < n; i++){
			if(a[i].f < a[i-1].f){
				ans = false;
				break;
			}
			if(a[i].s < a[i-1].s){
				ans = false;
				break;
			}
			if(a[i].s-a[i-1].s > a[i].f-a[i-1].f){
				ans = false;
				break;
			}
		}

		if(!ans){
			cout << "NO" << endl;
			continue;
		}
		else{
			cout << "YES" << endl;
		}

	}
}