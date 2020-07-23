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

	if(n == 1){
		cout << 15 << endl;
		cout << "0 0" << endl;
		cout << "0 1" << endl;
		cout << "0 2" << endl;
		cout << "-1 2" << endl;
		cout << "-2 2" << endl;
		cout << "-2 1" << endl;
		cout << "-2 0" << endl;
		cout << "-1 0" << endl;
		cout << "1 0" << endl;
		cout << "2 0" << endl;
		cout << "2 -1" << endl;
		cout << "2 -2" << endl;
		cout << "1 -2" << endl;
		cout << "0 -2" << endl;
		cout << "0 -1" << endl;
		return 0;
	}
	
	int cnt = 0;
	vector<pii> output;

	int i = 0, j = 0;
	while(cnt < n){
		output.pb(mp(i, j));
		if(cnt%2){
			j++;
		}
		else{
			i++;
		}
		cnt++;
	}

	int maxI = i;
	int maxJ = j;

	output.pb(mp(-1, 0));
	output.pb(mp(0, -1));
	output.pb(mp(0, 1));

	j = 0;
	i = 1;
	while(i < maxI){
		output.pb(mp(i, j-1));
		output.pb(mp(i, j+2));
		i++; j++;
	}

	if(n%2){
		output.pb(mp(maxI, maxJ));
		output.pb(mp(maxI, maxJ-1));
		output.pb(mp(-2, 0));
		for(int j = 1; j <= 1000; j++){
			output.pb(mp(-2, j));
		}
		for(int i = -1; i <= maxI-1; i++){
			output.pb(mp(i, 1000));
		}
		for(int j = 999; j > maxJ+1; j--){
			output.pb(mp(maxI-1, j));
		}
	}
	else{
		output.pb(mp(maxI, maxJ));
		output.pb(mp(maxI, maxJ-2));
		output.pb(mp(maxI+1, maxJ-1));
		output.pb(mp(-2, 0));
		output.pb(mp(maxI+2, maxJ-1));
		for(int j = 1; j <= 1000; j++){
			output.pb(mp(-2, j));
		}
		for(int i = -1; i <= maxI+2; i++){
			output.pb(mp(i, 1000));
		}
		for(int j = 999; j > maxJ-1; j--){
			output.pb(mp(maxI+2, j));
		}
	}

	cout << output.size() << endl;
	for(int i = 0; i < output.size(); i++){
		cout << output[i].f << " " << output[i].s << endl;
	}
}