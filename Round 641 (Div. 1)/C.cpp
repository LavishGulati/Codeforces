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

int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, -1, 1};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, t;
	cin >> n >> m >> t;

	string *grid = new string[n];
	for(int i = 0; i < n; i++){
		cin >> grid[i];
	}

	int **alter = new int *[n];
	for(int i = 0; i < n; i++){
		alter[i] = new int[m];
		for(int j = 0; j < m; j++){
			alter[i][j] = -1;
		}
	}

	int u, v;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < 4; k++){
				u = i+moveX[k];
				v = j+moveY[k];
				if(u >= 0 && u < n && v >= 0 && v < m && grid[i][j] == grid[u][v]){
					alter[i][j] = 0;
				}
			}
		}
	}

	queue<pii> q[2];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(alter[i][j] == 0){
				for(int k = 0; k < 4; k++){
					u = i+moveX[k];
					v = j+moveY[k];
					if(u >= 0 && u < n && v >= 0 && v < m && alter[u][v] == -1){
						alter[u][v] = 1;
						q[0].push(mp(u, v));
					}
				}
			}
		}
	}

	pii x;
	int help = 2, id = 0;
	while(!q[id].empty()){
		while(!q[id].empty()){
			x = q[id].front();
			q[id].pop();
			for(int k = 0; k < 4; k++){
				u = x.f+moveX[k];
				v = x.s+moveY[k];
				if(u >= 0 && u < n && v >= 0 && v < m && alter[u][v] == -1){
					alter[u][v] = help;
					q[id^1].push(mp(u, v));
				}
			}
		}
		help++;
		id ^= 1;
	}

	ll p;
	while(t--){
		cin >> u >> v >> p;
		u--; v--;
		if(alter[u][v] == -1 || p < alter[u][v]){
			cout << grid[u][v] << endl;
		}
		else if((p-alter[u][v])%2){
			cout << (grid[u][v] == '0' ? '1' : '0') << endl;
		}
		else{
			cout << grid[u][v] << endl;
		}
	}
}