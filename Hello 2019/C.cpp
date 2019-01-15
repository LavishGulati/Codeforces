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
// #define s second
#define MOD 1000000007

int degree(string s){
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') st.push('(');
        else if(s[i] == ')'){
            if(!st.empty() && st.top() == '(') st.pop();
            else st.push(')');
        }
    }

    int answer = st.size();

    if(answer == 0) return 0;

    char c = st.top();
    st.pop();
    while(!st.empty()){
        if(st.top() != c) return INT_MAX;
        st.pop();
    }

    if(c == '(') return answer;
    else return -answer;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string *input = new string[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    map<int, int> m;
    for(int i = 0; i < n; i++){
        int x = degree(input[i]);
        // cout << x << endl;
        if(x < INT_MAX){
            if(m.find(x) == m.end()) m[x] = 1;
            else m[x]++;
        }
    }

    int total = 0;
    for(auto i = m.begin(); i != m.end(); i++){
        int x = i->first;
        if(m.find(-x) != m.end()){
            total += min(i->second, m[-x]);
        }
    }

    cout << total/2 << endl;
}
