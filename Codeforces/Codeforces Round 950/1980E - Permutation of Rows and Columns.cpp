#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> a[MAX],b[MAX];
int aidx[MAX],aidy[MAX],bidx[MAX],bidy[MAX];
int main()
{
	int T,n,m,i,j,ok,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			a[i].resize(m);
			f=0;
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]==1) f=1;
			}
			if(f && i!=0) swap(a[i],a[0]);
		}
		for(i=0;i<n;i++)
		{
			b[i].resize(m);
			f=0;
			for(j=0;j<m;j++)
			{
				scanf("%d",&b[i][j]);
				if(b[i][j]==1) f=1;
			}
			if(f && i!=0) swap(b[i],b[0]);
		}
		
		for(i=0;i<m;i++) aidy[i]=bidy[i]=i;
		sort(aidy,aidy+m,[](int x,int y){
			return a[0][x]<a[0][y];
		});
		sort(bidy,bidy+m,[](int x,int y){
			return b[0][x]<b[0][y];
		});
		
		for(i=0;i<n;i++) aidx[i]=bidx[i]=i;
		sort(aidx,aidx+n,[](int x,int y){
			return a[x][aidy[0]]<a[y][aidy[0]];
		});
		sort(bidx,bidx+n,[](int x,int y){
			return b[x][bidy[0]]<b[y][bidy[0]];
		});
		
		ok=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[aidx[i]][aidy[j]]!=b[bidx[i]][bidy[j]]) ok=0;
			}
		}
		if(ok) puts("YES");
		else puts("NO");
		
/*		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				printf("%d ",a[aidx[i]][aidy[j]]);
			}
			puts("");
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				printf("%d ",b[bidx[i]][bidy[j]]);
			}
			puts("");
		}*/
	}
	return 0;
}
