#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, i;
	cin >> n;
	string s;
	cin >> s;

	int num0, num1, num2;
	num0 = num1 = num2 = 0;
	for(i = 0; i < n; i++){
		if(s[i] == '0') num0++;
		else if(s[i] == '1') num1++;
		else num2++;
	}

	i = 0;
	while(num0 < n/3){
		if(num1 > n/3 && num2 > n/3){
			if(s[i] == '1'){
				num1--;
				s[i] = '0';
				num0++;
			}
			else if(s[i] == '2'){
				num2--;
				s[i] = '0';
				num0++;
			}
		}
		else if(num1 > n/3 && s[i] == '1'){
			num1--;
			s[i] = '0';
			num0++;
		}
		else if(num2 > n/3 && s[i] == '2'){
			num2--;
			s[i] = '0';
			num0++;
		}

		i++;
	}

	int seen0 = 0;
	i = 0;
	while(num1 < n/3){
		if(s[i] == '0' && seen0 < n/3){
			i++;
			seen0++;
			continue;
		}

		if(num0 > n/3 && num2 > n/3){
			if(s[i] == '0'){
				num0--;
				s[i] = '1';
				num1++;
			}
			else if(s[i] == '2'){
				num2--;
				s[i] = '1';
				num1++;
			}
		}
		else if(num0 > n/3 && s[i] == '0'){
			num0--;
			s[i] = '1';
			num1++;
		}
		else if(num2 > n/3 && s[i] == '2'){
			num2--;
			s[i] = '1';
			num1++;
		}

		i++;
	}

	i = 0;
	seen0 = 0;
	int seen1 = 0;
	while(num2 < n/3){
		if(s[i] == '0' && seen0 < n/3){
			i++;
			seen0++;
			continue;
		}

		if(s[i] == '1' && seen1 < n/3){
			i++;
			seen1++;
			continue;
		}

		if(num0 > n/3 && num1 > n/3){
			if(s[i] == '0'){
				num0--;
				s[i] = '2';
				num2++;
			}
			else if(s[i] == '1'){
				num1--;
				s[i] = '2';
				num2++;
			}
		}
		else if(num0 > n/3 && s[i] == '0'){
			num0--;
			s[i] = '2';
			num2++;
		}
		else if(num1 > n/3 && s[i] == '1'){
			num1--;
			s[i] = '2';
			num2++;
		}

		i++;
	}

	cout << s << endl;
}