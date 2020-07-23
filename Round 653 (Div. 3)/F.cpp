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

	auto make = [](vector<int> &a, int pos){
		swap(a[pos+1], a[pos+2]);
		swap(a[pos], a[pos+1]);
	};

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		vector<pii> res(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			res[i] = mp(a[i], i);
		}

		sort(all(res));
		for(int i = 0; i < n; i++){
			a[res[i].s] = i;
		}

		int cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				cnt += a[j] < a[i];
			}
		}

		if(cnt&1){
			for(int i = 0; i < n-1; i++){
				if(res[i].f == res[i+1].f){
					swap(a[res[i].s], a[res[i+1].s]);
					break;
				}
			}
		}

		vector<int> ans;
		for(int i = 0; i < n-2; i++){
			int pos = min_element(a.begin()+i, a.end())-a.begin();
			while(pos > i+1){
				make(a, pos-2);
				ans.pb(pos-2);
				pos -= 2;
			}
			if(pos != i){
				make(a, i);
				make(a, i);
				ans.pb(i);
				ans.pb(i);
				pos = i;
			}
		}

		for(int i = 0; i < 3; i++){
			if(is_sorted(a.begin(), a.end())){
				break;
			}
			make(a, n-3);
			ans.pb(n-3);
		}

		if(!is_sorted(all(a))){
			cout << -1 << endl;
		}
		else{
			cout << ans.size() << endl;
			for(int i : ans){
				cout << i+1 << " ";
			}
			cout << endl;
		}
	}
}