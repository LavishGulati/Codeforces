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

	int n;
	cin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	bool poss = true;
	for(int i = 1; i < n; i++){
		if(a[i] < a[i-1]){
			poss = false;
			break;
		}
	}
	for(int i = 0; i < n; i++){
		if(a[i] > i+1){
			poss = false;
			break;
		}
	}

	if(!poss){
		cout << -1 << endl;
		return 0;
	}

	bool *taken = new bool[n+5];
	for(int i = 0; i < n+5; i++){
		taken[i] = false;
	}

	int *b = new int[n];
	for(int i = 0; i < n; i++){
		b[i] = -1;
	}

	for(int i = 1; i < n; i++){
		if(a[i] != a[i-1]){
			b[i] = a[i-1];
			taken[a[i-1]] = true;
		}
	}
	taken[a[n-1]] = true;

	int id = 0;
	for(int i = 0; i < n; i++){
		if(b[i] == -1){
			while(taken[id]){
				id++;
			}
			b[i] = id;
			id++;
		}
	}

	for(int i = 0; i < n; i++){
		cout << b[i] << " ";
	}
	cout << endl;
}