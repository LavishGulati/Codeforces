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

    ll t, n;
    cin >> t;
    ll *input;
    set<ll> st;
    bool IsValid;
    while(t--){
        cin >> n;
        input = new ll[n];
        for(ll i = 0; i < n; i++) cin >> input[i];
        sort(input, input+n);

        IsValid = true;
        ll x = input[0]*input[n-1];
        for(ll i = 0; i <= n/2; i++){
            if(input[i]*input[n-1-i] != x){
                IsValid = false;
                break;
            }
        }

        if(!IsValid){
            cout << -1 << endl;
            continue;
        }

        st.clear();
        for(int i = 0; i < n; i++) st.insert(input[i]);
        for(ll i = 2; i <= sqrt(x); i++){
            if(x%i == 0){
                if(st.find(i) == st.end()){
                    IsValid = false;
                    break;
                }
                if(st.find(x/i) == st.end()){
                    IsValid = false;
                    break;
                }
            }
        }

        if(IsValid) cout << x << endl;
        else cout << -1 << endl;
    }
}
