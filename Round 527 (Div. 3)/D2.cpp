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

    int n, maxElement = 0;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
        maxElement = max(maxElement, input[i]);
    }

    stack<int> st;
    for(int i = 0; i < n; i++){
        if(input[i] == maxElement){
            if(!st.empty()){
                cout << "NO" << endl;
                return 0;
            }
        }
        else if(st.empty()) st.push(input[i]);
        else if(st.top() == input[i]) st.pop();
        else if(st.top() >= input[i]) st.push(input[i]);
        else{
            cout << "NO" << endl;
            return 0;
        }
    }

    if(st.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
}
