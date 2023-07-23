#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct LIS
{
	#define type int
	const type inf=INF;
	vector<int> work(vector<type> a,bool strict)
	{
		int i,pos,len,n;
		n=a.size();
		vector<type> b(n,inf);
		vector<int> tmp(n),res;
		for(i=0;i<n;i++)
		{
			//    strict: lower_bound
			//not strict: upper_bound
			if(strict) pos=lower_bound(b.begin(),b.end(),a[i])-b.begin();
			else pos=upper_bound(b.begin(),b.end(),a[i])-b.begin();
			b[pos]=a[i];
			tmp[i]=pos;
		}
		len=lower_bound(b.begin(),b.end(),inf)-b.begin();
		for(i=n-1;~i;i--)
		{
			if(!len) break;
			if(tmp[i]+1==len)
			{
				len--;
				res.push_back(i);
			}
		}
		return res;
	}
	#undef type
}lis;
int a[MAX],b[MAX],pos[MAX];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		b[i]=pos[b[i]];
	}
	printf("%d\n",lis.work(vector<int>(b+1,b+1+n),1).size());
	return 0;
}
