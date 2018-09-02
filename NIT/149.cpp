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
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int main()
{
	int i,j,k,m,n,t,s,flag;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>m>>n;
			if(m==2&&n==2)
			{
				printf("0\n1 1\n1 2\n2 2\n2 1\n1 1\n");
				continue;
			}
			else if(m==1&&n==2)
			{
				printf("0\n1 1\n1 2\n1 1\n");
				continue;
			}
			else if(m==2&&n==1)
			{
				printf("0\n1 1\n2 1\n1 1\n");
				continue;
			}
			else if(m==1)
			{
				puts("1");
				printf("%d %d 1 1\n",m,n);
				for(i=1;i<=n;i++)
				{
					printf("1 %d\n",i);
				}
				puts("1 1");
				continue;
			}
			else if(n==1)
			{
				puts("1");
				printf("%d %d 1 1\n",m,n);
				for(i=1;i<=m;i++)
				{
					printf("%d 1\n",i);
				}
				puts("1 1");
				continue;
			}
			else if(m==2&&n==1)
			{
				printf("0\n1 1\n2 1\n1 1\n");
				continue;
			}
			flag=0;
			if(m%2==0)
			{
				cout<<0<<endl;
				flag=1;
			}
			else if(n%2==0)
			{
				cout<<0<<endl;
				flag=2;
			}
			else
			{
				cout<<1<<endl;
				cout<<m<<" "<<n<<" 1 1"<<endl;
			}
			k=0;
			s=m*n;
			for(i=1,j=1;j<=n;++j)
			{
				printf("%d %d\n",i,j);
				k++;
			}
			if(flag==0)
			{
				while(k<s)
				{
					for(i++,j--;j>=1;--j)
					{
						printf("%d %d\n",i,j);
						k++;
					}
					if(k==s) break;
					for(i++,j++;j<=n;++j)
					{
						printf("%d %d\n",i,j);
						k++;
					}
					if(k==s) break;
				}
				cout<<"1 1"<<endl;
			}
			else if(flag==1)
			{
				while(k<=s-m)
				{
					for(i++,j--;i<=m&&j>1;--j)
					{
						printf("%d %d\n",i,j);
						k++;
					}
					if(k-1==s-m) break;
					for(i++,j++;i<=m&&j<=n;++j)
					{
						printf("%d %d\n",i,j);
						k++;
					}
					if(k-1==s-m) break;
				}
				for(;i>=1;i--)
				{
					printf("%d %d\n",i,j);
				}
			}
			else if(flag==2)
			{
				while(k<=s-m)
				{
					for(i++,j--;i<=m&&j>1;++i)
					{
						printf("%d %d\n",i,j);
						k++;
					}
					if(k-1==s-m) break;
					for(i--,j--;i>1;--i)
					{
						printf("%d %d\n",i,j);
						k++;
					}
					if(k-1==s-m) break;
				}
				for(i--,j--;i>=1;i--)
				{
					printf("%d %d\n",i,j);
				}
			}
		}
	}
	return 0;
}