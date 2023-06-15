#include <bits/stdc++.h>
using namespace std;
const int MAX=2e6+10;
struct Monotone_queue
{
	#define type int
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
int a[MAX];
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	vector<int> mn;
	dq.clear();
	for(i=1;i<m;i++) dq.insert(a[i],i);
	for(i=m;i<=n;i++)
	{
		dq.insert(a[i],i);
		mn.push_back(dq.get_min());
		dq.erase(i-m+1);
	}
	for(i=0;i<mn.size();i++) printf("%d\n",mn[i]);
	return 0;
}
