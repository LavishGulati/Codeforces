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
#define MOD 998244353

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll si = 1;
    for(ll i = 1; i < n; i++){
        if(s[i] == s[i-1]) si++;
        else break;
    }
    ll ei = 1;
    for(ll i = n-2; i >= 0; i--){
        if(s[i] == s[i+1]) ei++;
        else break;
    }

    if(s[0] != s[n-1]){
        cout << (si+ei+1)%MOD << endl;
    }
    else if(si == n) cout << n*(n+1)/2 << endl;
    else{
        cout << ((si+1)*(ei+1))%MOD << endl;
    }
}
