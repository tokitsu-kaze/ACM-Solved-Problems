#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
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
	void insert(int pos,type x)
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
int a[MAX],b[MAX];
ll sumb[MAX];
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	for(i=n+1;i<=2*n;i++)
	{
		a[i]=a[i-n];
		b[i]=b[i-n];
	}
	sumb[0]=0;
	for(i=1;i<=2*n;i++) sumb[i]=sumb[i-1]+b[i];
	dq.clear();
	for(i=1;i<n;i++) dq.insert(i,a[i]-sumb[i-1]);
	ans=LLINF;
	for(i=n;i<2*n;i++)
	{
		dq.insert(i,a[i]-sumb[i-1]);
		ans=min(ans,dq.get_max()+sumb[i-n]);
		dq.erase(i-n+1);
	}
	printf("%lld\n",ans);
	return 0;
}
