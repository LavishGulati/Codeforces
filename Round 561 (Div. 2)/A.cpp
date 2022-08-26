#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
#define PI acos(-1)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int helper[26];
    for(int i = 0; i < 26; i++) helper[i] = 0;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        helper[s[0]-'a']++;
    }

    int answer = 0, x, y;
    for(int i = 0; i < 26; i++){
        x = helper[i]/2;
        y = helper[i]-x;
        answer += (x*(x-1))/2;
        answer += (y*(y-1))/2;
    }
    cout << answer << endl;
}
