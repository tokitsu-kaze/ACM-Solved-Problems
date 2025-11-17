#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
char s[MAX];
int now[MAX];
int main()
{
	int T,n,i,tot,f,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		tot=f=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(tot==0)
			{
				s[i]='1';
				now[++tot]=x;
			}
			else
			{
				s[i]='0';
				if(now[tot]>x)
				{
					if(f==0 && x<=now[1])
					{
						s[i]='1';
						now[++tot]=x;
						f=1;
					}
				}
				else
				{
					if(f==1)
					{
						if(x>now[1]) continue;
					}
					s[i]='1';
					now[++tot]=x;
				}
			}
		}
		s[n+1]='\0';
		puts(s+1);
	}
	return 0;
}
