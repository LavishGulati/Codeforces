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

    string a, b;
    cin >> a >> b;

    int n = a.length();
    int m = b.length();

    int answer = 0;
    int x = 0;
    int helper = 0;

    for(int i = 0; i < m-1; i++){
        if(b[i] != b[i+1]) helper ^= 1;
    }

    for(int i = 0; i < m; i++){
        if(a[i] != b[i]) x ^= 1;
    }
    if(!x) answer++;

    for(int i = m; i < n; i++){
        x ^= helper;
        if(a[i] != b[m-1]) x ^= 1;
        if(a[i-m] != b[0]) x ^= 1;
        if(!x) answer++;
    }

    cout << answer << endl;
}
