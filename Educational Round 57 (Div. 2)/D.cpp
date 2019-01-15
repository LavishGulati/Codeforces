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

#define MAX 100009

char hard[4] = {'h', 'a', 'r', 'd'};
ll memo[MAX][4];

ll findMaxScore(string &s, ll id, ll *input, ll x, ll n){
    if(x == 4) return INT_MIN;
    if(id == n) return 0;

    if(memo[id][x] != -1) return memo[id][x];

    ll a = findMaxScore(s, id+1, input, x, n);

    ll b = 0;

    if(s[id] == hard[x]) b = input[id]+findMaxScore(s, id+1, input, x+1, n);
    else b = input[id]+findMaxScore(s, id+1, input, x, n);

    memo[id][x] = max(a, b);
    return max(a, b);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(ll i = 0; i < MAX; i++){
        for(ll j = 0; j < 4; j++) memo[i][j] = -1;
    }

    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll total = 0;
    ll *input = new ll[n];
    for(ll i = 0; i < n; i++){
        cin >> input[i];
        total += input[i];
    }

    ll answer = findMaxScore(s, 0, input, 0, n);
    cout << total-answer << endl;
}
