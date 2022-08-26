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

#define MAX 1005

bool present[MAX];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	bool ans;
	while(t--){
		ans = false;

		int n, m;
		cin >> n >> m;

		for(int i = 0; i < MAX; i++){
			present[i] = false;
		}

		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			present[a[i]] = true;
		}

		int x, val;
		for(int i = 0; i < m; i++){
			cin >> x;
			if(present[x]){
				ans = true;
				val = x;
			}
		}

		if(ans){
			cout << "YES" << endl;
			cout << "1 " << val << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}