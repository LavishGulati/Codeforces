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

int binary_search1(int *a, int n, int x){
	int ans = n/2, si = 0, ei = n/2-1;
	while(si <= ei){
		int mid = (si+ei)/2;
		if(a[mid] < x){
			si = mid+1;
		}
		else{
			ans = mid;
			ei = mid-1;
		}
	}
	return ans;
}

int binary_search2(int *a, int n, int x){
	int ans = n/2-1, si = n/2, ei = n-1;
	while(si <= ei){
		int mid = (si+ei)/2;
		if(a[mid] <= x){
			ans = mid;
			si = mid+1;
		}
		else{
			ei = mid-1;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;

		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		int *help = new int[2*k+1];
		for(int i = 0; i <= 2*k; i++){
			help[i] = 0;
		}

		for(int i = 0; i < n/2; i++){
			help[a[i]+a[n-i-1]]++;
			if(a[i] > a[n-i-1]){
				int temp = a[i];
				a[i] = a[n-i-1];
				a[n-i-1] = temp;
			}
		}

		sort(a, a+n/2);
		sort(a+n/2, a+n);

		int ans = INT_MAX;
		for(int i = 2; i <= k; i++){
			int id = binary_search1(a, n, i);
			// cout << i << " " << id << " " << (n/2-id)*2 + id - help[i] << endl;
			ans = min(ans, (n/2-id)*2 + id - help[i]);
		}

		for(int i = k+1; i <= 2*k; i++){
			int id = binary_search2(a, n, i-k-1);
			// cout << i << " " << id << " " << (id+1-n/2)*2 + n-id - help[i] << endl;
			ans = min(ans, (id+1-n/2)*2 + n-1-id - help[i]);
		}

		cout << ans << endl;
	}
}