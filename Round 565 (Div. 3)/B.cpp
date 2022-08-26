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

    int t, n, x;
    cin >> t;
    int helper[3];
    while(t--){
        for(int i = 0; i < 3; i++) helper[i] = 0;

        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x;
            helper[x%3]++;
        }

        x = min(helper[1], helper[2]);
        helper[1] -= x;
        helper[2] -= x;
        helper[0] += x;

        x = helper[1];
        helper[1] -= (x/3)*3;
        helper[0] += x/3;

        x = helper[2];
        helper[2] -= (x/3)*3;
        helper[0] += x/3;

        cout << helper[0] << endl;
    }
}
