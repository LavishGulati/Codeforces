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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	bool poss;

	while(t--){
		int n, x, y;
		cin >> n >> x >> y;

		int *b = new int[n];
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}

		if(y < x){
			cout << "NO" << endl;
			continue;
		}
		y -= x;

		queue<int> *freq = new queue<int>[n+2];
		for(int i = 0; i < n; i++){
			freq[b[i]].push(i);
		}

		int notPres = 0;
		for(int i = 1; i <= n+1; i++){
			if(freq[i].empty()){
				notPres = i;
				break;
			}
		}

		int *output = new int[n];
		for(int i = 0; i < n; i++){
			output[i] = -1;
		}

		priority_queue<pii> pq;
		for(int i = 1; i <= n+1; i++){
			if(freq[i].size() > 0){
				pq.push(mp(freq[i].size(), i));
			}
		}

		while(x > 0){
			pii p = pq.top();
			pq.pop();
			int id = freq[p.s].front();
			freq[p.s].pop();
			output[id] = b[id];
			if(p.f > 1){
				pq.push(mp(p.f-1, p.s));
			}
			x--;
		}

		for(int i = 0; i < n; i++){
			cout << output[i] << " ";
		}
		cout << endl;

		poss = true;
		while(y > 0){
			pii p = pq.top();
			pq.pop();
			if(pq.empty()){
				if(p.s > 2){
					poss = false;
					break;
				}
				else{
					
				}
			}
			pii p2 = pq.top();
			pq.pop();

			cout << p.s << " " << p2.s << endl;

			int id = freq[p.s].front();
			freq[p.s].pop();
			output[id] = p2.s;
			if(p.f > 1){
				pq.push(mp(p.f-1, p.s));
				pq.push(p2);
			}
			y--;
		}

		for(int i = 0; i < n; i++){
			if(output[i] == -1){
				output[i] = notPres;
			}
		}
		if(poss){
			cout << "YES" << endl;
			for(int i = 0; i < n; i++){
				cout << output[i] << " ";
			}
			cout << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}