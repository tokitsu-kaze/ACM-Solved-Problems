#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int p[MAX],res[MAX];
char s[MAX];
int main()
{
	int T,n,i,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&p[i]);
		l=1;
		r=n;
		for(i=1;i<=n;i++)
		{
			if(i&1)
			{
				if(p[l]<p[r])
				{
					s[i]='L';
					res[i]=p[l];
					l++;
				}
				else
				{
					s[i]='R';
					res[i]=p[r];
					r--;
				}
			}
			else
			{
				if(p[l]>p[r])
				{
					s[i]='L';
					res[i]=p[l];
					l++;
				}
				else
				{
					s[i]='R';
					res[i]=p[r];
					r--;
				}
			}
		}
//		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
		s[n+1]='\0';
		puts(s+1);
	}
	return 0;
}
