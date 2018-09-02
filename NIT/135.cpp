#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
	int a[51][51],i,j,k,m,n;
	while(cin>>n)
	{
		m=n*n/2+1;
		i=j=0;
		k=0;
		memset(a,0,sizeof(a));
 		while(k+1<m)
 		{
			for(;j<n&&k+1<m;j++)
			{
				if(a[j][i]&&j<=n) break;
				else a[n-1-j][n-1-i]=a[j][i]=++k;
	//			cout<<j<<" "<<i<<" "<<k<<endl;
			}
	//		cout<<endl;
			for(j--,i++;i<n&&k+1<m;i++)
			{
				if(a[j][i+1]&&i+1<=n) break;
				else a[n-1-j][n-1-i]=a[j][i]=++k;
	//			cout<<j<<" "<<i<<" "<<k<<endl;
			}
	//		cout<<endl;
			for(;j>=0&&k+1<m;j--)
			{
				if(a[j-1][i]&&j+1<=n) break;
				else a[n-1-j][n-1-i]=a[j][i]=++k;
	//			cout<<j<<" "<<i<<" "<<k<<endl;
			}
	//		cout<<endl;
			for(;i>=0&&k+1<m;i--)
			{
				if(a[j][i-1]&&i+1<=n) break;
				else a[n-1-j][n-1-i]=a[j][i]=++k;
	//			cout<<j<<" "<<i<<" "<<k<<endl;
			}
	//		cout<<endl;
		}
		if(n%2) a[n/2][n/2]=++k;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<a[i][j];
				if(j!=n-1) cout<<" ";
				else cout<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}