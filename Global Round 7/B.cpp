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

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int *b = new int[n];
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}

	int *a = new int[n];
	a[0] = b[0];
	int maxel = max(0, a[0]);
	for(int i = 1; i < n; i++){
		a[i] = maxel+b[i];
		maxel = max(maxel, a[i]);
	}

	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}