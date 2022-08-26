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

	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;

		int *t = new int[n], allEqual = 1;
		for(int i = 0; i < n; i++){
			cin >> t[i];
			if(i > 0 && t[i] != t[i-1]){
				allEqual = 0;
			}
		}

		if(allEqual){
			cout << 1 << endl;
			for(int i = 0; i < n; i++){
				cout << "1 ";
			}
			cout << endl;
			continue;
		}

		int *color = new int[n];
		int x = 0, maxColor = 0;
		color[0] = 1;

		for(int i = 1; i < n; i++){
			if(n%2 && t[i] == t[i-1] && !x){
				color[i] = color[i-1];
				x++;
			}
			else{
				color[i] = (!((i+x)%2) ? 1 : 2);
			}
			maxColor = max(maxColor, color[i]);
		}

		if(n%2 && t[n-1] == t[0] && !x){
			color[n-1] = color[0];
			x++;
		}

		if(n%2 && !x){
			color[n-1] = 3;
			maxColor = max(maxColor, color[n-1]);
		}

		cout << maxColor << endl;
		for(int i = 0; i < n; i++){
			cout << color[i] << " ";
		}
		cout << endl;
	}
}