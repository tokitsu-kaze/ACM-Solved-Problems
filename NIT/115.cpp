#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	int t,n,i,j,temp1,count[4];
	char a[101];
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			memset(count,0,sizeof(count));
			temp1=0;
			for(i=0;i<n;i++)
			{
				scanf("%s",a);
				if(a[0]!='-')
				{
					for(j=0;j<strlen(a);j++)
					{
						temp1+=a[j]-'0';
					}
				}
				else
				{
					for(j=1;j<strlen(a);j++)
					{
						temp1-=a[j]-'0';
					}
				}
				temp1%=3;
				count[abs(temp1)]++;
				temp1=0;
				//cout<<" "<<temp2<<endl;
			}
			cout<<min(count[1],count[2])+count[0]/2<<endl;
		}
	}
	return 0;
}