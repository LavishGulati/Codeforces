#include <bits/stdc++.h>
using namespace std;

#define pb push_back

map<int, int> mp;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t, n;
	cin >> t;

	while(t--){
		cin >> n;
		int *arr = new int[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		if(n < 5){
			cout << "0 0 0" << endl;
			continue;
		}

		vector<int> v;
		v.pb(1);
		int id = 0;
		for(int i = 1; i < n; i++){
			if(arr[i] != arr[i-1]){
				v.pb(1);
				id++;
			}
			else{
				v[id]++;
			}
		}

		int m = v.size();
		
		for(int i = 1; i < m; i++){
			v[i] += v[i-1];
			// cout << v[i] << " ";
		}
		// cout << endl;

		int answer = 0;
		int ans[3] = {0, 0, 0};

		for(int i = 0; i < m; i++){
			int g = v[i], s = 0, b = 0;

			if(g > n/2){
				continue;
			}

			// Find si
			int start = i+1;
			int end = m-1;
			int si;
			while(start <= end){
				int mid = (start+end)/2;
				if(v[mid]-g <= g){
					start = mid+1;
				}
				else{
					end = mid-1;
					si = mid-1;
					s = v[mid];
				}
			}

			if(s > n/2){
				continue;
			}

			start = si+1;
			end = m-1;
			while(start <= end){
				int mid = (start+end)/2;
				if(v[mid] <= n/2){
					b = v[mid];
					start = mid+1;
				}
				else{
					end = mid-1;
				}
			}

			if(answer < b && b-s > g){
				answer = b;
				ans[0] = g;
				ans[1] = s-g;
				ans[2] = b-s;
			}
		}

		cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
	}
}