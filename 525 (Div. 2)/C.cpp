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
#define f first
#define s second
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int *input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    stack<pii> st;

    int x;
    for(int i = n-1; i >= 0; i--){
        if(input[i]%n == i) continue;

        x = i-input[i];
        if(x < 0) x += (abs(x/n) + 1)*n;

        if(x != 0){
            st.push(mp(i, x));
            for(int j = 0; j <= i; j++) input[j] += x;
        }
    }

    cout << st.size()+1 << endl;
    while(!st.empty()){
        cout << 1 << " " << st.top().f + 1 << " " << st.top().s << endl;
        st.pop();
    }
    cout << 2 << " " << n << " " << n << endl;
}
