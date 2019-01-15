#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pi 2*acos(0.0)
#define Mk make_pair
#define Pb push_back 
#define sp " "
#define fst first
#define snd second
#define FAST ios_base::sync_with_stdio(false)
//int fr[]={0,0,1,-1,-1,1,-1,1};
//int fc[]={-1,1,0,0,1,1,-1,-1};
//int arr[16];
//bool vis[16];
/* int power(int x, unsigned int y) 
{ 
	if (y == 0) return 1; 
	else if (y%2 == 0) return power(x, y/2)*power(x, y/2); 
    else return x*power(x, y/2)*power(x, y/2); 
} */

int main()
{
	FAST;
	ll lnth;
	int arr[5];
	memset(arr,0,sizeof(arr));
	cin>>lnth;
	string s;
	cin>>s;
	for(int i=0 ; i<lnth ; i++)
	{
		arr[s[i]-'0']++;
	}
	//cout<<arr[0]<<sp<<arr[1]<<sp<<arr[2]<<endl;
	if(arr[0] > lnth/3 ) //replacing zeros
	{
		int i=lnth-1;
		while(arr[0] > lnth/3 && arr[2] < lnth/3 && i>=0)
		{
			if(s[i] == '0')
			{
				s[i] = '2';
				arr[0]--,arr[2]++;
			}
			i--;
		}

		while(arr[0] > lnth/3 && arr[1] < lnth/3 && i>=0)
		{
			if(s[i] == '0')
			{
				s[i] = '1';
				arr[0]--,arr[1]++;
			}
			i--;
		}
	}
	if(arr[1] > lnth/3 )  //replacing ones
	{
		int i=lnth-1;
		while(arr[1] > lnth/3 && arr[2] < lnth/3 && i>=0)
		{
			if(s[i] == '1')
			{
				s[i] = '2';
				arr[1]--,arr[2]++;
				//cout<<"ok"<<endl;
			}
			i--;
		}
		i = 0;
		while(arr[1] > lnth/3 && arr[0] < lnth/3 && i< lnth )
		{
			if(s[i] == '1')
			{
				s[i] = '0';
				arr[1]--,arr[0]++;
			}
			i++;
		}
	}

	if(arr[2] > lnth/3) //replacing twos
	{
		int i= 0 ;
		while(arr[2] > lnth/3 && arr[0] < lnth/3 && i< lnth )
		{
			if(s[i] == '2')
			{
				s[i] = '0';
				arr[2]--,arr[0]++;
			}
			i++;
		}

		while(arr[2] > lnth/3 && arr[1] < lnth/3 && i< lnth )
		{
			if(s[i] == '2')
			{
				s[i] = '1';
				arr[2]--,arr[1]++;
			}
			i++;
		}
	}
	cout<<s<<endl;
	return 0;
}