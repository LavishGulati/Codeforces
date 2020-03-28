#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
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

	int sx, sy;
	cin >> sx >> sy;

	int up = 0, left = 0, right = 0, down = 0;
	int u, v;
	for(int i = 0; i < n; i++){
		cin >> u >> v;
		if(u > sx){
			right++;
		}
		else if(u < sx){
			left++;
		}

		if(v > sy){
			up++;
		}
		else if(v < sy){
			down++;
		}
	}

	int answer = max(down, max(up, max(left, right)));
	cout << answer << endl;
	if(answer == left){
		cout << sx-1 << " " << sy << endl;
	}
	else if(answer == right){
		cout << sx+1 << " " << sy << endl;
	}
	else if(answer == up){
		cout << sx << " " << sy+1 << endl;
	}
	else{
		cout << sx << " " << sy-1 << endl;
	}
}