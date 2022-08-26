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
typedef vector<int> vi;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 998244353
#define PI acos(-1)

bool compare(string a, string b){
    if(a.length() < b.length()) return true;
    else if(a.length() > b.length()) return false;
    else return a < b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    string *input = new string[n];

    ll m = 0;
    for(ll i = 0; i < n; i++){
        cin >> input[i];
        m = max(ll(input[i].length()), m);
    }

    ll freq[m+1];
    for(ll i = 0; i <= m; i++) freq[i] = 0;
    for(ll i = 0; i < n; i++){
        freq[input[i].length()]++;
    }

    ll power[2*m+1];
    power[0] = 1;
    for(ll i = 1; i <= 2*m; i++){
        power[i] = (10*power[i-1])%MOD;
    }

    ll total = 0, x, l;
    for(ll i = 0; i < n; i++){
        l = input[i].length();
        for(ll j = 0; j < l; j++){
            for(ll k = 1; k <= m; k++){
                x = input[i][j]-'0';
                x = (x*freq[k])%MOD;
                if(k >= l){
                    total = (total+((x*power[2*(l-j-1)])%MOD))%MOD;
                    total = (total+((x*power[2*(l-j-1)+1])%MOD))%MOD;
                }
                else if(l-j > k){
                    total = (total+((2*x*power[l-j+k-1])%MOD))%MOD;
                }
                else{
                    total = (total+((x*power[2*(l-j-1)])%MOD))%MOD;
                    total = (total+((x*power[2*(l-j-1)+1])%MOD))%MOD;
                }
            }
        }
    }

    cout << total << endl;
}
