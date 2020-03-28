#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long, long> pll;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair

#define MAX 401

string s, t;
int n, m;
pair<char, int> dp[201][201][401];

int solve(int i, int j, int open){
	if(dp[i][j][open].s != INT_MAX){
		return dp[i][j][open].s;
	}

	if(i == n && j == m && open == 0){
		return 0;
	}

	if(i == n && j == m){
		int answer = 1+solve(i, j, open-1);
		dp[i][j][open] = mp(')', answer);
		return answer;
	}

	if(i == n){
		if(t[j] == '('){
			int answer = 1+solve(i, j+1, open+1);
			dp[i][j][open] = mp('(', answer);
			return answer;
		}
		else{
			if(open > 0){
				int answer = 1+solve(i, j+1, open-1);
				dp[i][j][open] = mp(')', answer);
				return answer;
			}
			else{
				int answer = 1+solve(i, j, open+1);
				dp[i][j][open] = mp('(', answer);
				return answer;
			}
		}
	}
	if(j == m){
		if(s[i] == '('){
			int answer = 1+solve(i+1, j, open+1);
			dp[i][j][open] = mp('(', answer);
			return answer;
		}
		else{
			if(open > 0){
				int answer = 1+solve(i+1, j, open-1);
				dp[i][j][open] = mp(')', answer);
				return answer;
			}
			else{
				int answer = 1+solve(i, j, open+1);
				dp[i][j][open] = mp('(', answer);
				return answer;
			}
		}
	}
	

	if(s[i] == t[j] && s[i] == '('){
		int answer = 1+solve(i+1, j+1, open+1);
		dp[i][j][open] = mp('(', answer);
		return answer;
	}
	else if(s[i] == t[j] && s[i] == ')'){
		if(open > 0){
			int answer = 1+solve(i+1, j+1, open-1);
			dp[i][j][open] = mp(')', answer);
			return answer;
		}
		else{
			int answer = 1+solve(i, j, open+1);
			dp[i][j][open] = mp('(', answer);
			return answer;
		}
	}
	else if(s[i] == '(' && t[j] == ')'){
		int a = 1+solve(i+1, j, open+1);
		int b = INT_MAX;
		if(open > 0){
			b = 1+solve(i, j+1, open-1);
		}

		if(a <= b){
			dp[i][j][open] = mp('(', a);
			return a;
		}
		else{
			dp[i][j][open] = mp(')', b);
			return b;
		}
	}
	else{
		int a = 1+solve(i, j+1, open+1);
		int b = INT_MAX;
		if(open > 0){
			b = 1+solve(i+1, j, open-1);
		}

		if(a <= b){
			dp[i][j][open] = mp('(', a);
			return a;
		}
		else{
			dp[i][j][open] = mp(')', b);
			return b;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> s >> t;

	n = s.length();
	m = t.length();

	for(int i = 0; i < 201; i++){
		for(int j = 0; j < 201; j++){
			for(int k = 0; k < MAX; k++){
				dp[i][j][k] = mp('.', INT_MAX);
			}
		}
	}

	int answer = solve(0, 0, 0);
	// cout << answer << endl;

	string output = "";
	int i = 0, j = 0, open = 0;
	while(i < n && j < m){
		output += dp[i][j][open].f;

		if(s[i] == t[j] && s[i] == '('){
			i++; j++; open++;
		}
		else if(s[i] == t[j] && s[i] == ')'){
			if(open > 0){
				i++; j++; open--;
			}
			else{
				open++;
			}
		}
		else if(s[i] == '(' && t[j] == ')'){
			if(dp[i][j][open].f == '('){
				i++; open++;
			}
			else{
				j++; open--;
			}
		}
		else{
			if(dp[i][j][open].f == '('){
				j++; open++;
			}
			else{
				i++; open--;
			}
		}
	}

	while(i < n){
		output += dp[i][j][open].f;
		if(s[i] == '('){
			i++; open++;
		}
		else{
			if(open > 0){
				i++; open--;
			}
			else{
				open++;
			}
		}
	}

	while(j < m){
		output += dp[i][j][open].f;
		if(t[j] == '('){
			j++; open++;
		}
		else{
			if(open > 0){
				j++; open--;
			}
			else{
				open++;
			}
		}
	}

	while(open > 0){
		output += ')';
		open--;
	}

	cout << output << endl;
}