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

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		int *b = new int[n];
		for(int i = 0; i < n; i++){
			b[i] = a[i];
		}

		sort(b, b+n);

		bool poss = true;
		int gcd = b[0];
		for(int i = 0; i < n; i++){
			if(a[i] != b[i] && (a[i]%gcd)){
				poss =  false;
				break;
			}
		}
		if(poss){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}