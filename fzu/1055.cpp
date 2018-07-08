#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;
int main()
{
	int n,a[30],i,count,flag;
	char c[4];
	while(cin>>n)
	{
		if(n==-1) break;
		memset(a,0,sizeof(a));
		a[0]=1;
		flag=0;
		while(n--)
		{
			scanf("%s",c);
			a[c[0]-'a']=a[c[2]-'a'];
		}
		for(i=0,count=0;i<26;i++)
		{
			if(a[i]) count++;
		}
		for(i=0;i<26;i++)
		{
			if(a[i])
			{
				printf("%c",i+'a');
				count--;
				flag=1;
				if(count) cout<<" ";
			}
		}
		if(flag==0) cout<<"none";
		cout<<endl;
	}
	return 0;
}