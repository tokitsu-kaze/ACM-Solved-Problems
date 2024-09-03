#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
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
int a[MAX],b[MAX],id[MAX];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		id[i]=i;
	}
	sort(id+1,id+1+n,[](int x,int y){
		return a[x]<a[y];
	});
	vector<int> tmp(n);
	for(i=1;i<=n;i++) tmp[i-1]=b[id[i]];
	printf("%d\n",lis.work(tmp,true).size());
	return 0;
}
