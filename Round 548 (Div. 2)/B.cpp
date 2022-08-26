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
    ll input[n];
    for(ll i = 0; i < n; i++){
        cin >> input[i];
    }

    ll total = 0;
    ll maxValue = INT_MAX;
    for(ll i = n-1; i >= 0; i--){
        if(maxValue == 0) break;

        if(input[i] <= maxValue){
            maxValue = input[i]-1;
            total += input[i];
        }
        else{
            total += maxValue;
            maxValue--;
        }

        // cout << total << endl;
    }

    cout << total << endl;
}
