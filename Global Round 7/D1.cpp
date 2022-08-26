#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pq priority_queue

#define MOD 1000000007

string findLongestPalindromicString(string &s){ 
    int n = s.length(); 
    if(n == 0){
    	return "";
    }

    n = 2*n + 1; //Position count 
    int lps[n]; //LPS Length Array 
    lps[0] = 0; 
    lps[1] = 1;

    int c = 1; //centerPosition  
    int r = 2; //centerRightPosition 
    int i = 0; //currentRightPosition 
    int iMirror; //currentLeftPosition 
    int expand = -1; 
    int diff = -1; 
    int maxLPSLength = 0; 
    int maxLPSCenterPosition = 0; 
    int start = -1; 
    int end = -1; 
      
    //Uncomment it to print LPS Length array 
    //printf("%d %d ", L[0], L[1]); 
    for (i = 2; i < n; i++){ 
        //get currentLeftPosition iMirror for currentRightPosition i 
        iMirror  = 2*c-i; 
        //Reset expand - means no expansion required 
        expand = 0; 
        diff = r - i; 
        //If currentRightPosition i is within centerRightPosition R 
        if(diff > 0)  
        { 
            if(lps[iMirror] < diff) // Case 1 
                lps[i] = lps[iMirror]; 
            else if(lps[iMirror] == diff && i == n-1) // Case 2 
                lps[i] = lps[iMirror]; 
            else if(lps[iMirror] == diff && i < n-1)  // Case 3 
            { 
                    lps[i] = lps[iMirror]; 
                    expand = 1;  // expansion required 
            } 
            else if(lps[iMirror] > diff)  // Case 4 
            { 
                lps[i] = diff; 
                expand = 1;  // expansion required 
            } 
        } 
        else
        { 
            lps[i] = 0; 
            expand = 1;  // expansion required 
        } 
          
        if (expand == 1) 
        { 
            //Attempt to expand palindrome centered at currentRightPosition i 
            //Here for odd positions, we compare characters and  
            //if match then increment LPS Length by ONE 
            //If even position, we just increment LPS by ONE without  
            //any character comparison 
            while (((i + lps[i]) < n && (i - lps[i]) > 0) &&  
                ( ((i + lps[i] + 1) % 2 == 0) ||  
                (s[(i + lps[i] + 1)/2] == s[(i-lps[i]-1)/2] ))) 
            { 
                lps[i]++; 
            } 
        } 
  
        if(lps[i] > maxLPSLength)  // Track maxLPSLength 
        { 
            maxLPSLength = lps[i]; 
            maxLPSCenterPosition = i; 
        } 
  
        // If palindrome centered at currentRightPosition i  
        // expand beyond centerRightPosition R, 
        // adjust centerPosition C based on expanded palindrome. 
        if (i + lps[i] > r)  
        { 
            c = i; 
            r = i + lps[i]; 
        } 
        //Uncomment it to print LPS Length array 
        //printf("%d ", L[i]); 
    } 
    
    int maxLen = 0;
    int si = -1, sj = -1;
    for(int i = 0; i < n; i++){
    	if(i-lps[i] == 0 && lps[i] > maxLen){
    		si = (i-lps[i])/2;
    		sj = (i+lps[i])/2 - 1;
    		maxLen = lps[i];
    	}
    	if(i+lps[i] == n-1 && lps[i] > maxLen){
    		si = (i-lps[i])/2;
    		sj = (i+lps[i])/2 - 1;
    		maxLen = lps[i];
    	}
    }

    return s.substr(si, sj-si+1);
} 

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;

		int n = s.length();

		int k = 0;
		while(k <= n-k-1 && s[k] == s[n-k-1]){
			k++;
		}

		if(k > n-k-1){
			cout << s << endl;
		}
		else{
			string sa = s.substr(k, n-2*k);

			string mid = findLongestPalindromicString(sa);
			cout << s.substr(0, k) + mid + s.substr(n-k) << endl;
			// string mid2 = lps(sa);
			// if(mid.length() >= mid2){
			// 	cout << s.substr(0, k) + mid + s.substr(n-k);
			// }
			// else{
			// 	cout << s.substr(0, k) + mid2 + s.substr(n-k);
			// }
		}
	}
}