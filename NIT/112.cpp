#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	int n,a[501],i,sum,o,e;
	while(cin>>n)
	{
		o=e=sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			if(a[i]%2) o++;
			else e++;
		}
		sort(a,a+n);
		if(sum<=0)
		{
			cout<<a[n-1];
			for(i=n-2;i>=0;i--)
			{
				if(a[i]!=a[i+1]) cout<<" "<<a[i];
			}
		}
		else if(sum%2)
		{
			for(i=n-1;i>=0;i--)
			{
				if(a[i]%2)
				{
					cout<<a[i];
					o--;
					if(o!=0) cout<<" ";
				}
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(a[i]%2==0)
				{
					cout<<a[i];
					e--;
					if(e!=0) cout<<" ";
				}
			}
		}
		cout<<endl; 
	}
	return 0;
}