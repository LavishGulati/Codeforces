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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    ll *output = new ll[n];

    ll x;
    cin >> x;
    output[0] = 0;
    output[n-1] = x;
    for(ll i = 1; i < n/2; i++){
        cin >> x;
        if(x-output[i-1] <= output[n-i]){
            output[i] = output[i-1];
            output[n-i-1] = x-output[i-1];
        }
        else{
            output[n-i-1] = output[n-i];
            output[i] = x-output[n-i];
        }
    }

    for(ll i = 0; i < n; i++) cout << output[i] << " ";
    cout << endl;
}
