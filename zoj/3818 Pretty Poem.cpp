#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char tmp[55],s[55];
bool same(char *s,int l1,int r1,int l2,int r2)
{
	if(r1-l1!=r2-l2) return 0;
	for(int i=l1,j=l2;i<=r1;i++,j++)
	if(s[i]!=s[j]) return 0;
	return 1;
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",tmp);
		n=0;
		for(int i=0;i<strlen(tmp);i++)
		{
			if(isalpha(tmp[i]))
			s[++n]=tmp[i];
		}
		int ok=0;
		for(int k=1;k<=n/2;k++) //ABABA
		{
			if(n-k+1>k && same(s,1,k,n-k+1,n)) // 前缀A == 后缀A
			{
				int m=n-k; 
				if((m&1)==0 && m/2>=k+1 && !same(s,1,k,k+1,m/2) && same(s,1,m/2,m/2+1,m)) //A!=B && AB==AB
				{
					ok=1;
					break;
				}
			}
		}
		for(int k=2;k<=n/2;k++) //ABABCAB
		{
			if(same(s,1,k,n-k+1,n) && n-k+1>k && n>k*3) //前AB==后AB
			{
				for(int i=1;i<=k-1;i++)
				{
					if(!same(s,1,i,i+1,k) && same(s,1,k,k+1,2*k)) //A!=B  && AB==AB
					{
						if(2*k+1>i && !same(s,1,i,2*k+1,n-k) && !same(s,i+1,k,2*k+1,n-k)) // A!=C && B!=C
						{
							ok=1;
							break;
						}
					}
				}
			}
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}

