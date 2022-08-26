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

	int n, m, k;
	cin >> n >> m >> k;

	pii *start = new pii[k];
	for(int i = 0; i < k; i++){
		cin >> start[i].f >> start[i].s;
	}

	pii *finish = new pii[k];
	for(int i = 0; i < k; i++){
		cin >> finish[i].f >> finish[i].s;
	}

	string output = "";

	for(int i = 0; i < n-1; i++){
		output += 'U';
	}

	for(int i = 0; i < m-1; i++){
		output += 'L';
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m-1; j++){
			if(i%2){
				output += 'L';
			}
			else{
				output += 'R';
			}
		}
		if(i != n-1){
			output += 'D';
		}
	}

	cout << output.length() << endl;
	cout << output << endl;
}