#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t, n;
	cin >> t;

	string output;

	while(t--){
		cin >> n;
		int *arr = new int[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		output = "";
		for(int i = 0; i < n; i++){
			output += '0';
		}

		output[0] = '1';
		output[n-1] = '1';

		int *index = new int[n+1];
		for(int i = 0; i < n; i++){
			index[arr[i]] = i;
		}

		bool *sweep = new bool[n+1];
		for(int i = 0; i <= n; i++){
			sweep[i] = false;
		}

		int l, r;
		l = r = index[1];
		sweep[1] = true;

		int count = 1, maxEl = 1;

		while(1){
			if(l == 0){
				r++;
			}
			else if(r == n-1){
				l--;
			}
			else{
				if(arr[r+1] < arr[l-1]) r++;
				else l--;
			}

			if(r-l == n) break;

			sweep[arr[l]] = true;
			sweep[arr[r]] = true;

			maxEl = max(maxEl, max(arr[l], arr[r]));

			// cout << l << " " << r << " " << maxEl << endl;

			if(maxEl-1 == r-l){
				output[r-l] = '1';
			}
		}

		cout << output << endl;
	}
}