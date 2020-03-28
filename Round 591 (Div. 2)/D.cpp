#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair
#define pb push_back

int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
    if (v.size() == 0)
        return 0;

    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {

        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];

        // v[i] extends largest subsequence
        else if (v[i] >= tail[length - 1])
            tail[length++] = v[i];

        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming grater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }

    // int n = v.size();
    // for(int i = 0; i < n; i++){
    //     cout << tail[i] << " ";
    // }
    // cout << endl;
    // cout << tail[length-1] << endl;
    return length;
}

bool compare(pii a, pii b){
    return a.s < b.s;
}

int main(){
    int q, n;
    cin >> q;
    while(q--){
        cin >> n;
        // vector<int> v;
        // int x;
        int *input = new int[n];
        for(int i = 0; i < n; i++){
            cin >> input[i];
            // cin >> x;
            // v.pb(x);
        }

        vector<pii> prev;
        for(int i = 0; i <= n; i++){
            prev.push_back(mp(-1, INT_MAX));
        }
        for(int i = 0; i < n; i++){
            prev[input[i]] = mp(input[i], i);
        }
        sort(prev.begin(), prev.end(), compare);

        vector<int> v;
        for(int i = 0; i <= n; i++){
            if(prev[i].s != INT_MAX){
                v.push_back(prev[i].f);
            }
            else{
                break;
            }
        }

        // for(int i = 0; i < v.size(); i++){
        //     cout << v[i] << " ";
        // }
        // cout << endl;

        cout << v.size()-LongestIncreasingSubsequenceLength(v) << endl;
    }
}
