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

    int n, k;
    cin >> n >> k;
    int *input = new int[k];
    for(int i = 0; i < k; i++) input[i] = 0;

    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        input[x-1]++;
    }

    int total = (n%2) == 0 ? n/2 : n/2 + 1;
    int answer = 0;
    for(int i = 0; i < k; i++){
        x = min(total, input[i]/2);
        total -= x;
        answer += 2*x;
        input[i] -= x*2;

        // cout << i << " " << x << " " << total << endl;
    }

    for(int i = 0; i < k; i++){
        if(total == 0) break;
        if(input[i] > 0){
            answer++;
            total--;
            input[i] = 0;
        }
    }

    cout << answer << endl;
}
