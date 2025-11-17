#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int a[MAX],pre[MAX];
vector<int> op[MAX];
int main()
{
	int T,m,n,i,k,f,pos,ok,p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&n);
		for(i=1;i<=n;i++) a[i]=pre[i]=0;
		ok=1;
		for(i=1;i<=m;i++)
		{
			scanf("%d",&k);
			op[i].resize(k);
			for(auto &it:op[i])
			{
				scanf("%d",&it);
				if(i==m) ok&=(a[it]==0);
				a[it]=i;
			}
		}
		if(m==1)
		{
			puts("No");
			continue;
		}
		if(ok)
		{
			puts("Yes");
			vector<int> res;
			res.push_back(m);
			for(i=1;i<m;i++) res.push_back(i);
			for(i=0;i<m;i++) printf("%d%c",res[i]," \n"[i==m-1]);
			continue;
		}
		pos=0;
		for(i=1;i<m;i++)
		{
			f=1;
			for(auto &it:op[i]) f&=(a[it]==i);
			if(f)
			{
				pos=i;
				break;
			}
		}
		if(pos)
		{
			puts("Yes");
			vector<int> res;
			for(i=1;i<pos;i++) res.push_back(i);
			for(i=pos+1;i<=m;i++) res.push_back(i);
			res.push_back(pos);
			for(i=0;i<m;i++) printf("%d%c",res[i]," \n"[i==m-1]);
			continue;
		}
		pos=0;
		for(i=1;i<m;i++)
		{
			f=1;
			for(auto &it:op[i]) f&=(a[it]==a[op[i][0]] && a[it]!=i);
			if(f)
			{
				if(i==1 && a[op[i][0]]==2) continue;
				pos=i;
				break;
			}
		}
		if(pos)
		{
			puts("Yes");
			vector<int> res;
			if(pos!=1)
			{
				res.push_back(pos);
				for(i=1;i<pos;i++) res.push_back(i);
				for(i=pos+1;i<=m;i++) res.push_back(i);
			}
			else
			{
				for(i=1;i<pos;i++) res.push_back(i);
				for(i=pos+1;i<a[op[pos][0]];i++) res.push_back(i);
				res.push_back(pos);
				for(i=a[op[pos][0]];i<=m;i++) res.push_back(i);
			}
			for(i=0;i<m;i++) printf("%d%c",res[i]," \n"[i==m-1]);
			continue;
		}
		pos=0;
		for(i=1;i<=m;i++)
		{
			p=0;
			for(auto &it:op[i])
			{
				if(a[it]==i) p=max(pre[it],p);
			}
			if(p!=i-1)
			{
				pos=i;
				break;
			}
			for(auto &it:op[i]) pre[it]=i;
		}
		if(pos)
		{
			puts("Yes");
			vector<int> res;
			for(i=1;i<=p;i++) res.push_back(i);
			res.push_back(pos);
			for(i=p+1;i<pos;i++) res.push_back(i);
			for(i=pos+1;i<=m;i++) res.push_back(i);
			for(i=0;i<m;i++) printf("%d%c",res[i]," \n"[i==m-1]);
			continue;
		}
		puts("No");
	}
	return 0;
}
/*
4
3 3
3 1 2 3
3 1 2 3
3 1 2 3
2 3
1 1
2 2 3
3 5
2 1 2
2 2 3
2 4 5
5 5
3 2 4 5
2 1 4
3 2 3 5
2 1 2
2 1 3

*/
