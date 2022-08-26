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

	int n, m;
	cin >> n >> m;

	int *w = new int[n];
	for(int i = 0; i < n; i++){
		cin >> w[i];
	}

	pii *choice = new pii[m];
	for(int i = 0; i < m; i++){
		cin >> choice[i].f >> choice[i].s;
		choice[i].f--;
		choice[i].s--;
	}

	bool *done = new bool[n];
	for(int i = 0; i < n; i++){
		done[i] = false;
	}

	bool *taken = new bool[m];
	for(int i = 0; i < m; i++){
		taken[i] = false;
	}

	int *s = new int[n];
	for(int i = 0; i < n; i++){
		s[i] = 0;
	}

	vector<int> *like = new vector<int>[n];
	for(int i = 0; i < m; i++){
		like[choice[i].f].pb(i);
		like[choice[i].s].pb(i);
		s[choice[i].f]++;
		s[choice[i].s]++;
	}

	pq<pii> mypq;
	for(int i = 0; i < n; i++){
		mypq.push(mp(w[i]-s[i], i));
	}

	vector<int> output;
	while(!mypq.empty()){
		pii x = mypq.top();
		mypq.pop();
		if(x.f >= 0 && !done[x.s]){
			done[x.s] = true;
			for(int y : like[x.s]){
				if(!taken[y]){
					output.pb(y);
					taken[y] = true;

					s[choice[y].f]--;
					s[choice[y].s]--;
					mypq.push(mp(w[choice[y].f]-s[choice[y].f], choice[y].f));
					mypq.push(mp(w[choice[y].s]-s[choice[y].s], choice[y].s));
				}
			}
		}
	}

	if(output.size() < m){
		cout << "DEAD\n";
		return 0;
	}

	cout << "ALIVE\n";
	reverse(all(output));
	for(int i = 0; i < m; i++){
		cout << output[i]+1 << " ";
	}
	cout << "\n";
}