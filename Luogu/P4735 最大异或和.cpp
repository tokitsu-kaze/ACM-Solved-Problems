#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=6e5+10;
struct Persistent_01Trie
{
	#define type int
	static const int LOG=30;
	static const int K=LOG+2;
	int root[MAX],tot,nex[MAX*K][2],cnt[MAX*K];
	void init()
	{
		root[0]=0;
		nex[0][0]=nex[0][1]=cnt[0]=tot=0;
	}
	int newnode()
	{
		tot++;
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		return tot;
	}
	void update(type x,int &rt,int pre)
	{
		int id,t,i;
		if(!rt) rt=newnode();
		id=rt;
		for(i=LOG;~i;i--)
		{
			cnt[id]=cnt[pre]+1;
			t=(x>>i)&1;
			nex[id][t^1]=nex[pre][t^1];
			nex[id][t]=newnode();
			id=nex[id][t];
			pre=nex[pre][t];
		}
		cnt[id]=cnt[pre]+1;
	}
	type query_max(type x,int rt,int pre)
	{
		int id,t,i;
		type res;
		id=rt;
		res=0;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(cnt[nex[id][t^1]]-cnt[nex[pre][t^1]]>0) t^=1;
			res|=(t<<i);
			id=nex[id][t];
			pre=nex[pre][t];
		}
		return res^x;
	}
	void copy_ver(int now_ver,int pre_ver)
	{
		root[now_ver]=root[pre_ver];
	}
	void create_ver(int now_ver,int pre_ver,type x)
	{
		root[now_ver]=0;
		update(x,root[now_ver],root[pre_ver]);
	}
	type ask_max(int pre_ver,int now_ver,type x)
	{
		assert(pre_ver>0);
		return query_max(x,root[now_ver],root[pre_ver-1]);
	}
	#undef type
}tr;
/*
tr.init();
tr.create_ver(now_ver,pre_ver,v);
tr.copy_ver(now_ver,pre_ver);
tr.ask_max(l,r,v);
*/
int bit[MAX];
int main()
{
	int n,m,i,l,r,x;
	char op[2];
	scanf("%d%d",&n,&m);
	n++;
	tr.init();
	bit[1]=0;
	tr.create_ver(1,0,bit[1]);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&x);
		bit[i]=bit[i-1]^x;
		tr.create_ver(i,i-1,bit[i]);
	}
	while(m--)
	{
		scanf("%s",op);
		if(op[0]=='A')
		{
			scanf("%d",&x);
			n++;
			bit[n]=bit[n-1]^x;
			tr.create_ver(n,n-1,bit[n]);
		}
		else
		{
			scanf("%d%d%d",&l,&r,&x);
			printf("%d\n",tr.ask_max(l,r,x^bit[n]));
		}
	}
	return 0;
}
/*
1 1
1
Q 1 1 3
*/
