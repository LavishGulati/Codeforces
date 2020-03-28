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
	string s;
	cin >> s;

	int numWhite = 0, numBlack = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'B'){
			numBlack++;
		}
		else{
			numWhite++;
		}
	}

	if((numWhite%2 == 1) && (numBlack%2 == 1)){
		cout << -1 << endl;
		return 0;
	}

	int answer = 0;
	vector<int> output;

	if(numBlack%2 == 0){
		int black = 0;
		int i;
		for(i = 0; i < n; i++){
			if(s[i] == 'B'){
				black++;
			}
			else{
				for(int j = i-black; j < i; j += 2){
					if(j+1 < n && s[j] == 'B' && s[j+1] == 'B'){
						answer++;
						output.pb(j);
						s[j] = 'W';
						s[j+1] = 'W';
					}
				}
				black = 0;
			}
		}

		int prevId = -1;
		for(i = 0; i < n; i++){
			if(s[i] == 'B' && prevId == -1){
				prevId = i;
			}
			else if(s[i] == 'B'){
				for(int j = prevId; j < i-1; j++){
					answer++;
					output.pb(j);
					s[j] = 'W';
				}
				s[i-1] = 'W';
				s[i] = 'W';
				answer++;
				output.pb(i-1);
				prevId = -1;
			}
		}
	}
	else{
		int white = 0;
		int i;
		for(i = 0; i < n; i++){
			if(s[i] == 'W'){
				white++;
			}
			else{
				for(int j = i-white; j < i; j += 2){
					if(j+1 < n && s[j] == 'W' && s[j+1] == 'W'){
						answer++;
						output.pb(j);
						s[j] = 'B';
						s[j+1] = 'B';
					}
				}
				white = 0;
			}
		}

		int prevId = -1;
		for(i = 0; i < n; i++){
			if(s[i] == 'W' && prevId == -1){
				prevId = i;
			}
			else if(s[i] == 'W'){
				for(int j = prevId; j < i-1; j++){
					answer++;
					output.pb(j);
					s[j] = 'B';
				}
				s[i-1] = 'B';
				s[i] = 'B';
				answer++;
				output.pb(i-1);
				prevId = -1;
			}
		}
	}

	cout << answer << endl;
	if(answer == 0){
		return 0;
	}

	int m = output.size();
	for(int i = 0; i < m; i++){
		cout << output[i]+1 << " ";
	}
	cout << endl;
}