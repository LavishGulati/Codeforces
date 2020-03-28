#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long, long> pll;

#define pb push_back
#define umap unordered_map
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}

	int end[n];
	end[0] = 1;
	for(int i = 1; i < n; i++){
		if(input[i] > input[i-1]){
			end[i] = end[i-1]+1;
		}
		else{
			end[i] = 1;
		}
	}

	int start[n];
	start[n-1] = 1;
	for(int i = n-2; i >= 0; i--){
		if(input[i] < input[i+1]){
			start[i] = start[i+1]+1;
		}
		else{
			start[i] = 1;
		}
	}

	int answer = 0;
	for(int i = 0; i < n; i++){
		answer = max(answer, end[i]);
	}

	for(int i = 1; i < n-1; i++){
		if(input[i+1] > input[i-1]){
			answer = max(answer, end[i-1]+start[i+1]);
		}
	}

	cout << answer << endl;
}