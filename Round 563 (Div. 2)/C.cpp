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

    ll n;
    cin >> n;
    ll output[n+1];
    for(ll i = 0; i <= n; i++) output[i] = -1;

    ll num = 1;
    for(ll i = 2; i <= n; i++){
        if(output[i] == -1){
            output[i] = num;
            for(ll j = i*i; j <= n; j += i){
                if(output[j] == -1) output[j] = num;
            }
            num++;
        }
    }

    for(ll i = 2; i <= n; i++){
        cout << output[i] << " ";
    }
    cout << endl;
}
