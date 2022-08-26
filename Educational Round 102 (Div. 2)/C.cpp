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

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int *a = new int[k];
		int help = 0;
		for(int i = 2*k-n-1; i < k; i++){
			a[i] = k-help;
			help++;
		}
		for(int i = 0; i < 2*k-n-1; i++){
			a[i] = i+1;
		}
		for(int i = 0; i < k; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
}