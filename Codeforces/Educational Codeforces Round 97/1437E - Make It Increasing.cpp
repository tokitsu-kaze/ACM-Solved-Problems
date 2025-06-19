#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct LIS
{
	#define type int
	const type inf=INF;
	int work(vector<type> a,bool strict,bool head,bool tail)
	{
		int i,pos,len,n,tmp;
		n=a.size();
		vector<type> b(n,inf);
		for(i=0;i<n;i++)
		{
			//    strict: lower_bound
			//not strict: upper_bound
			if(strict) pos=lower_bound(b.begin(),b.end(),a[i])-b.begin();
			else pos=upper_bound(b.begin(),b.end(),a[i])-b.begin();
			if(pos==0 && head && b[pos]!=INF)
			{
				if(i==n-1 && tail) return -1;
				continue;
			}
			if(i==n-1 && tail)
			{
				b[pos]=a[i];
				pos++;
				while(pos<n && b[pos]!=INF)
				{
					b[pos]=INF;
					pos++;
				}
				continue;
			}
			b[pos]=a[i];
		}
		len=lower_bound(b.begin(),b.end(),inf)-b.begin();
		tmp=0;
		if(head) tmp++;
		if(tail) tmp++;
		if(tmp>len) return -1;
		return n-len;
	}
	#undef type
}lis;
int a[MAX],tag[MAX];
int main()
{
	int n,k,i,x,pre,res,ans,ok;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		tag[i]=0;
		scanf("%d",&a[i]);
		a[i]-=i;
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d",&x);
		tag[x]=1;
	}
	vector<int> tmp;
	pre=0;
	ans=0;
	ok=1;
	for(i=1;i<=n;i++)
	{
		tmp.push_back(a[i]);
		if(tag[i]||i==n)
		{
			res=lis.work(tmp,false,(pre==0?false:true),(tag[i]?true:false));
			if(res<0)
			{
				ok=0;
				break;
			}
			ans+=res;
			tmp.clear();
			tmp.push_back(a[i]);
			pre=i;
//			cout<<i<<" "<<res<<endl;
		}
	}
	if(ok) printf("%d\n",ans);
	else puts("-1");
	return 0;
}
