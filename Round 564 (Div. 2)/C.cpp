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

    int *hand = new int[n+1];
    for(int i = 1; i <= n; i++) cin >> hand[i];
    sort(hand, hand+n);

    int *pile = new int[n+1];
    for(int i = 1; i <= n; i++) cin >> pile[i];

    int *id = new int[n+1];
    for(int i = 1; i <= n; i++) id[i] = 0;
    for(int i = 1; i <= n; i++){
        if(pile[i] != 0){
            id[pile[i]] = i;
        }
    }

    if(id[1]){
        int i, j;
        for(i = 2; id[i] == id[1]+i-1; i++);
        if(id[i-1] == n){
            for(j = i; j <= n && id[j] <= j-i; j++);
            if(j > n){
                cout << n-i+1 << endl;
                return 0;
            }
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; i++){
        answer = max(answer, id[i]-i+1);
    }
    cout << answer+n << endl;
}
