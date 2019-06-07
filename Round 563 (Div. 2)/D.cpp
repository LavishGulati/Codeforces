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

    ll n, x;
    cin >> n >> x;

    set<ll> st;
    vector<ll> helper;
    ll limit = (1<<n);
    for(ll i = 1; i < limit; i++){
        if(st.find(x^i) != st.end()) continue;
        if(i == x) continue;
        helper.pb(i);
        st.insert(i);
    }

    cout << helper.size() << endl;
    if(helper.size() > 0) cout << helper[0] << " ";
    for(ll i = 1; i < helper.size(); i++){
        cout << (helper[i]^helper[i-1]) << " ";
    }
    if(helper.size() > 0) cout << endl;
}
