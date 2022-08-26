#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long, long> pll;
typedef pair<int, int> pii;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}

	int helper[n][2];
	for(int i = 0; i < n; i++){
		helper[i][0] = helper[i][1] = INT_MAX;
	}

	vector<int> visit[n];
	for(int i = 0; i < n; i++){
		if(i+input[i] < n){
			visit[i+input[i]].pb(i);
		}
		if(i-input[i] >= 0){
			visit[i-input[i]].pb(i);
		}
	}

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < visit[i].size(); j++){
	// 		cout << visit[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	bool visited[n][2];
	for(int i = 0; i < n; i++){
		visited[i][0] = visited[i][1] = false;
	}

	queue<pii> q;
	for(int i = 0; i < n; i++){
		if(input[i]%2 == 1){
			helper[i][1] = 0;
			q.push(mp(i, 1));
			visited[i][1] = true;
		}
		else{
			helper[i][0] = 0;
			q.push(mp(i, 0));
			visited[i][0] = true;
		}
	}

	while(!q.empty()){
		pii u = q.front();
		q.pop();
		int id = u.f;

		// cout << u.f << " " << u.s << ": ";

		for(int v : visit[id]){
			// cout << v << " ";
			if(u.s == 0 && !visited[v][0] && (input[v]%2 == 1)){
				helper[v][0] = helper[id][0]+1;
				visited[v][0] = true;
				q.push(mp(v, 0));
			}
			if(u.s == 1 && !visited[v][1] && (input[v]%2 == 0)){
				helper[v][1] = helper[id][1]+1;
				visited[v][1] = true;
				q.push(mp(v, 1));
			}
		}
		// cout << endl;
	}

	for(int i = 0; i < n; i++){
		if(input[i]%2){
			cout << (helper[i][0] < INT_MAX ? helper[i][0] : -1) << " ";
		}
		else{
			cout << (helper[i][1] < INT_MAX ? helper[i][1] : -1) << " ";
		}
	}
	cout << endl;
}