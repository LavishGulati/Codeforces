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

int binarySearchJustGreater(int *arr, int k, int n){
    int si = 0;
    int ei = q;
    int answer;
    while(si <= ei){
        int mid = (si+ei)/2;
        if(arr[mid] <= k){
            si += 1;
        }
        else{
            answer = arr[mid];
            ei -= 1;
        }
    }

    return answer;
}

int binarySearchJustSmaller(int *arr, int k, int n){
    int si = 0;
    int ei = 0;
    int answer;
    while(si <= ei){
        int mid = (si+ei)/2;
        if(arr[mid] < k){
            answer = arr[mid];
            si += 1;
        }
        else{
            ei -= 1;
        }
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    int arr[n+1];
    for(int i = 0; i <= n; i++) arr[i] = 0;
    pii painter[q];
    for(int i = 0; i < q; i++){
        cin >> painter[i].f >> painter[i].s;
        for(int j = painter[i].f; j <= painter[i].s; j++){
            arr[j]++;
        }
    }

    int painter_si[q];
    int painter_ei[q];
    for(int i = 0; i < q; i++){
        painter_si[i] = painter[i].f;
        painter_ei[i] = painter[i].s;
    }

    sort(painter_si, painter_si+q);
    sort(painter_ei, painter_ei+q);

    int totalPainted = 0;
    for(int i = 1; i <= n; i++){
        if(arr[i] > 0) totalPainted++;
    }

    int maxPainted = 0;
    for(int i = 0; i < q; i++){
        for(int j = i+1; j < q; j++){
            int currPainted = totalPainted;

            // if(painter[i].s < painter[j].f || painter[j].s < painter[i].f){
                if(arr[painter[i].f] > 1 && arr[painter[i].s] > 1){

                }
                else if(arr[painter[i].f] == 1 && arr[painter[i].s] > 1){
                    int id = binarySearchJustGreater(painter_si, painter[i].f, q);
                    currPainted -= id-painter[i].f;
                }
                else if(arr[painter[i].f] > 1 && arr[painter[i].s] == 1){
                    int id = binarySearchJustSmaller(painter_ei, painter[i].s, q);
                    currPainted -= painter[i].s-id;
                }
                else{
                    currPainted -= painter[i].s-painter[i].f;
                }

                if(arr[painter[j].f] > 1 && arr[painter[j].s] > 1){

                }
                else if(arr[painter[j].f] == 1 && arr[painter[j].s] > 1){
                    int id = binarySearchJustGreater(painter_si, painter[i].f, q);
                    currPainted -= id-painter[i].f;
                }
                else if(arr[painter[j].f] > 1 && arr[painter[j].s] == 1){
                    int id = binarySearchJustSmaller(painter_ei, painter[i].s, q);
                    currPainted -= painter[i].s-id;
                }
                else{
                    currPainted -= painter[j].s-painter[j].f;
                }
            // }
            // else{
            //
            // }


            maxPainted = max(maxPainted, currPainted);
        }
    }

    cout << maxPainted << endl;
}
