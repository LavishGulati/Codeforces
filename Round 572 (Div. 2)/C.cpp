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
#define MOD 1000000007
#define PI acos(-1)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    ll *input = new ll[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    ll cum[n];
    cum[0] = input[0];
    for(ll i = 1; i < n; i++){
        cum[i] = cum[i-1]+input[i];
    }

    ll q, l, r;
    cin >> q;
    while(q--){
        cin >> l >> r;
        if(l == 1){
            cout << cum[r-1]/10 << endl;
        }
        else{
            cout << (cum[r-1]-cum[l-2])/10 << endl;
        }
    }
}
