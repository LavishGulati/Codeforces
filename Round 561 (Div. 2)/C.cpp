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

int BinarySearch(int *input, int si, int ei, int x){
    int answer = ei+1, mid;
    while(si <= ei){
        mid = (si+ei)/2;
        if(input[mid] < double(x)/2){
            si = mid+1;
        }
        else{
            answer = mid;
            ei = mid-1;
        }
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    for(int i = 0; i < n; i++) input[i] = abs(input[i]);
    sort(input, input+n);

    ll total = 0;
    for(int i = 0; i < n; i++){
        total += i-BinarySearch(input, 0, i-1, input[i]);
    }
    cout << total << endl;
}
