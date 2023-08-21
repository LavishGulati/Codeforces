#import<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long d, n, t, x, y, z0[5004][5004], z1[5004][5004];
string a, b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(cin >> t; t--;)
	{
		cin >> n >> x >> y >> a >> b;
		d = 0;
		for(int i = 0; i < n; i++)
		{
			a[i] ^= b[i];
			d += a[i];
		}
		if(d % 2)
		{
			cout << -1 << endl;
			continue;
		}
		if(d == 2)
		{
			int l, r;
			for(l = 0; !a[l]; )l++;
			for(r = n - 1; !a[r]; )r--;
			if(l + 1 == r)cout << min(x, 2 * y) << endl;
			else cout << min((r - l) * x, y) << endl;
			continue;
		}
		if(!d || x >= y)
		{
			cout << d / 2 * y << endl;
			continue;
		}
		for(int i = 0; i < n; i++)
		{
			fill(z0[i], z0[i] + n + 1, 1LL << 60);
			fill(z1[i], z1[i] + n + 1, 1LL << 60);
		}
		if(a[0] == 0)z0[0][0] = 0;
		if(a[0] == 1)z1[0][1] = 0;
		for(int i = 1; i < n; i++)
		{
			if(a[i])
			{
				for(int j = i + 1; j >= 0; j--)
				{
					if(j <= i)z0[i][j] = min(z0[i - 1][j + 1] + y, z1[i - 1][j + 1] + x);
					if(j)
					{
						z0[i][j] = min({z0[i][j], z0[i - 1][j - 1] + x, z1[i - 1][j - 1] + y});
						z1[i][j] = min(z0[i - 1][j - 1], z1[i - 1][j - 1]);
					}
				}
			}
			else
			{
				for(int j = i + 1; j >= 0; j--)
				{
					z0[i][j] = min(z0[i - 1][j], z1[i - 1][j]);
					z1[i][j] = min(z0[i - 1][j] + y, z1[i - 1][j] + x);
					if(j > 1)z1[i][j] = min({z1[i][j], z0[i - 1][j - 2] + x, z1[i - 1][j - 2] + y});
				}
			}
		}
		cout << z0[n - 1][0] << endl;
	}
}