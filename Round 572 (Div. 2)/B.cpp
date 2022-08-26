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

    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    sort(input, input+n);
    if(input[n-1] >= input[n-2]+input[n-3]){
        cout << "NO" << endl;
        return 0;
    }

    int output[n];
    int id = 0;
    for(int i = n-1; i >= 0; i -= 2){
        output[id] = input[i];
        id++;
    }
    id = n-1;
    for(int i = n-2; i >= 0; i -= 2){
        output[id] = input[i];
        id--;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << output[i] << " ";
    cout << endl;
}
