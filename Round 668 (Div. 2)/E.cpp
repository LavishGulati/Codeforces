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

	int n, q;
	cin >> n >> q;
	int *a = new int[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int *b = new int[n];
	for(int i = 0; i < n; i++){
		b[i] = i+1-a[i];
	}

	int *c = new int[n];
	for(int i = 0; i < n; i++){
		c[i] = 0;
	}

	int id = -1, last = -1;
	for(int i = 0; i < n; i++){
		if(b[i] == 0){
			id = i;
			last = b[i];
			c[i] = 1;
		}
		else if(id >= 0 && b[i] >= 0 && b[i] <= last+1){
			c[i] = c[id]+1;
			id = i;
			last = max(last, b[i]);
		}
	}

	for(int i = 0; i < n; i++){
		cout << c[i] << " ";
	}
	cout << endl;
}