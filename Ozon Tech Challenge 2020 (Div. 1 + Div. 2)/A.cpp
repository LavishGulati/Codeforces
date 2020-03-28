#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t, n;
	cin >> t;

	while(t--){
		cin >> n;
		int *A = new int[n];
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}

		int *B = new int[n];
		for(int i = 0; i < n; i++){
			cin >> B[i];
		}

		sort(A, A+n);
		sort(B, B+n);
		for(int i = 0; i < n; i++){
			cout << A[i] << " ";
		}
		cout << "\n";
		for(int i = 0; i < n; i++){
			cout << B[i] << " ";
		}
		cout << "\n";
	}
}