#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char s[10];
		int a[2111];
		scanf("%s",s);
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(strcmp(s,"Faster")==0)
		{
			int min=2009;
			for(int i=1;i<=n;i++)
			{
				if(a[i]<min)
					min=a[i];
			}
			cout<<min<<endl;
		}
		if(strcmp(s,"Higher")==0)
		{
			int max=-1;
			for(int i=1;i<=n;i++)
			{
				if(a[i]>max)
					max=a[i];
			}
			cout<<max<<endl;
		}
		if(strcmp(s,"Stronger")==0)
		{
			int max=-1;
			for(int i=1;i<=n;i++)
			{
				if(a[i]>max)
					max=a[i];
			}
			cout<<max<<endl;
		}
	}
}