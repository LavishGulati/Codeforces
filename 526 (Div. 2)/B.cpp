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

#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

#define MAX 1000000000000

int main(){
    ll n, s;
    cin >> n >> s;

    ll *input = new ll[n];
    ll totalVol = 0;
    for(ll i = 0; i < n; i++){
        cin >> input[i];
        totalVol += input[i];
    }

    if(s > totalVol){
        cout << -1 << endl;
        return 0;
    }

    sort(input, input+n);

    ll answer;

    ll si = 0;
    ll ei = input[n-1];
    while(si <= ei){
        ll mid = (si+ei)/2;
        ll total = 0;
        for(ll i = n-1; i >= 0; i--){
            total += input[i]-mid;
            if(input[i] <= mid) break;
        }

        if(total < s) ei = mid-1;
        else{
            answer = min(mid, input[0]);
            si = mid+1;
        }
    }

    cout << answer << endl;
}
