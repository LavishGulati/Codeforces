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

    int n;
    cin >> n;
    int *input = new int[2*n];
    for(int i = 0; i < 2*n; i++) cin >> input[i];

    bool IsSame = true;
    for(int i = 1; i < 2*n; i++){
        if(input[i] != input[i-1]){
            IsSame = false;
            break;
        }
    }

    if(IsSame){
        cout << -1 << endl;
        return 0;
    }

    sort(input, input+2*n);
    for(int i = 0; i < 2*n; i++) cout << input[i] << " ";
    cout << endl;
}
