#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e6+10;
const ll mod=1e6;
char ans[MAX],t[MAX];
int pre[MAX];
int main()
{
	int n,i,j,k,p,len,maxx;
	while(~scanf("%d",&n))
	{
		mem(pre,0);
		mem(ans,0);
		maxx=0;
		while(n--)
		{
			scanf("%s%d",t,&k);
			len=strlen(t);
			while(k--)
			{
				scanf("%d",&p);
				maxx=max(maxx,p+len-1);
				for(i=p,j=0;i<=p-1+len;)
				{
					int flag=0;
					while(pre[i])
					{
						int temp=pre[i];
						i=i+temp;
						pre[i-temp]=len-j;
						j=i-p;
						if(i>p-1+len)
						{
							flag=1;
							break;
						}
					}
					if(flag) break;
	//				cout<<i<<" "<<j<<endl;
					ans[i]=t[j];
					pre[i]=len-j;
					i++;
					j++;
				}
			}
		}
		for(i=1;i<=maxx;i++)
		{
			if(ans[i]==0) ans[i]='a';
		}
		ans[maxx+1]='\0';
		puts(ans+1);
	}
	return 0;
}
/*
5
abc 2 1 12
aba 2 4 6
bc 2 9 13
c 2 14 16
vcg 1 15

abcabababc  bcvcg
*/