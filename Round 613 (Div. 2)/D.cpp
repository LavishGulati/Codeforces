#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

class node{
public:
	char c;
	node *left, *right;

	node(char c){
		this->c = c;
		left = NULL;
		right = NULL;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	ll *input = new ll[n];
	for(ll i = 0; i < n; i++){
		cin >> input[i];
	}

	string *helper = new string[n];
	string s;
	ll maxLength = 0;
	for(ll i = 0; i < n; i++){
		s = "";
		while(input[i] > 0){
			if(input[i]%2){
				s += '1';
			}
			else{
				s += '0';
			}
			input[i] /= 2;
		}
		reverse(all(s));
		helper[i] = s;
		// reverse(all(helper[i]));
		maxLength = max(maxLength, ll(s.length()));
	}

	for(ll i = 0; i < n; i++){
		s = "";
		ll num = helper[i].length();
		while(num < maxLength){
			s += '0';
			num++;
		}
		helper[i] = s+helper[i];
		// cout << helper[i] << endl;
	}

	node *root = new node('.');
	node *head, *newNode;
	for(ll i = 0; i < n; i++){
		head = root;
		for(ll j = 0; j < maxLength; j++){
			if(helper[i][j] == '0'){
				if(head->left == NULL){
					newNode = new node('0');
					head->left = newNode;
				}
				head = head->left;
			}
			else{
				if(head->right == NULL){
					newNode = new node('1');
					head->right = newNode;
				}
				head = head->right;
			}
		}
	}

	queue<node *> q;
	q.push(root);
	ll ans = 0;
	vector<node *> v;
	ll h = 0;
	while(!q.empty()){
		v.clear();
		while(!q.empty()){
			v.pb(q.front());
			q.pop();
		}

		bool possible = false;
		for(ll i = 0; i < v.size(); i++){
			if(v[i]->left != NULL && v[i]->right != NULL){
				// do nothing
			}
			else if(v[i]->left == NULL && v[i]->right == NULL){

			}
			else{
				possible = true;
			}
		}

		if(possible){
			for(ll i = 0; i < v.size(); i++){
				if(v[i]->left != NULL && v[i]->right != NULL){
					// do nothing
				}
				else if(v[i]->left == NULL && v[i]->right == NULL){

				}
				else if(v[i]->left != NULL){
					q.push(v[i]->left);
				}
				else{
					q.push(v[i]->right);
				}
			}
		}
		else{
			ans += pow(2, maxLength-h-1);
			for(ll i = 0; i < v.size(); i++){
				if(v[i]->left != NULL && v[i]->right != NULL){
					q.push(v[i]->left);
					q.push(v[i]->right);
				}
				else if(v[i]->left == NULL && v[i]->right == NULL){

				}
				else{

				}
			}
		}

		h++;
	}

	cout << ans << endl;
}