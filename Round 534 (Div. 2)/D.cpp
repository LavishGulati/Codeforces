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

    ll power[35];
    power[0] = 1;
    for(ll i = 1; i < 35; i++) power[i] = 2*power[i-1];

    string s;
    char c;

    while(1){
        cin >> s;
        if(s == "end") break;

        ll answer = 0;
        for(ll i = 30; i >= 0; i--){
            cout << "? " << power[i+1]-1 << " " << power[i]-1 << endl;
            cin >> c;
            if(c == 'y') answer += power[i];
            else{
                cout << "? " << power[i]-1 << " " << power[i+1]-1 << endl;
                cin >> c;
                if(c == 'x') answer += 
                else{

                }
            }
        }
    }

}
