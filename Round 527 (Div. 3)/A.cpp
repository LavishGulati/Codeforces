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

    int t, n, k, i;
    char c;
    cin >> t;
    while(t--){
        cin >> n >> k;
        string s = "";
        for(i = 0; i < k-1; i++){
            for(int j = 0; j < n/k; j++){
                c = 'a'+i;
                s += c;
            }
        }
        while(s.length() != n){
            c = 'a'+i;
            s += c;
        }

        cout << s << endl;
    }
}
