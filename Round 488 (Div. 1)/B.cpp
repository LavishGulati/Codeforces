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

	int n, m;
	cin >> n >> m;

	pii *a = new pii[n];
	int u, v;
	for(int i = 0; i < n; i++){
		cin >> u >> v;
		a[i].f = min(u, v);
		a[i].s = max(u, v);
	}

	pii *b = new pii[m];
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		b[i].f = min(u, v);
		b[i].s = max(u, v);
	}

	int ans = -1, cnt1, cnt2;
	bool poss = true;
	for(int i = 0; i < n; i++){
		cnt1 = 0; cnt2 = 0;
		for(int j = 0; j < m; j++){
			if(a[i].f == b[j].f && a[i].s == b[j].s){
				// do nothing
			}
			else if(a[i].f == b[j].f || a[i].f == b[j].s){
				cnt1++;
			}
			else if(a[i].s == b[j].f || a[i].s == b[j].s){
				cnt2++;
			}
		}

		if(cnt1 > 0 && cnt2 > 0){
			poss = false;
			break;
		}
		else if(cnt1 > 0){
			if(ans == -1 || ans == a[i].f){
				ans = a[i].f;	
			}
			else{
				ans = 0;
				break;
			}
		}
		else if(cnt2 > 0){
			if(ans == -1 || ans == a[i].s){
				ans = a[i].s;	
			}
			else{
				ans = 0;
				break;
			}
		}
	}

	for(int j = 0; j < m; j++){
		cnt1 = 0; cnt2 = 0;
		for(int i = 0; i < n; i++){
			if(a[i].f == b[j].f && a[i].s == b[j].s){
				// do nothing
			}
			else if(a[i].f == b[j].f || a[i].s == b[j].f){
				cnt1++;
			}
			else if(a[i].f == b[j].s || a[i].s == b[j].s){
				cnt2++;
			}
		}

		if(cnt1 > 0 && cnt2 > 0){
			poss = false;
			break;
		}
		else if(cnt1 > 0){
			if(ans == -1 || ans == b[j].f){
				ans = b[j].f;	
			}
			else if(ans != b[j].f){
				
			}
			else{
				ans = 0;
				break;
			}
		}
		else if(cnt2 > 0){
			if(ans == -1 || ans == b[j].s){
				ans = b[j].s;	
			}
			else{
				ans = 0;
				break;
			}
		}
	}

	if(!poss){
		cout << -1 << endl;
		return 0;
	}

	cout << ans << endl;
}