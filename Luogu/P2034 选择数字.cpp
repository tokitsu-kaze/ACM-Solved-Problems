#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Monotone_queue
{
	#define type ll
	type v[MAX][2];//0 is min, 1 is max
	int p[MAX][2];
	int l[2],r[2];
	void clear()
	{
		l[0]=r[0]=0;
		l[1]=r[1]=0;
	}
	void insert(type x,int pos)
	{
		while(r[0]-l[0]&&v[r[0]-1][0]>=x) r[0]--;
		v[r[0]][0]=x;
		p[r[0]++][0]=pos;
		while(r[1]-l[1]&&v[r[1]-1][1]<=x) r[1]--;
		v[r[1]][1]=x;
		p[r[1]++][1]=pos;
	}
	void erase(int pos)
	{
		while(r[0]-l[0]&&p[l[0]][0]<=pos) l[0]++;
		while(r[1]-l[1]&&p[l[1]][1]<=pos) l[1]++;
	}
	type get_min(){return v[l[0]][0];}
	type get_max(){return v[l[1]][1];}
	#undef type
}dq;
int main()
{
	int n,k,i,x;
	ll ans;
	scanf("%d%d",&n,&k);
	dq.clear();
	dq.insert(0,0);
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ans+=x;
		dq.insert(dq.get_min()+x,i);
		dq.erase(i-k-1);
	}
	printf("%lld\n",ans-dq.get_min());
	return 0;
}
