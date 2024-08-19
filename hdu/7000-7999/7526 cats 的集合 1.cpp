#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
struct Trie
{
	#define type int
	static const int LOG=30;
	static const int K=LOG+2;
	int root,tot,nex[MAX*K][2],cnt[MAX*K];
	type ortag[MAX*K],andtag[MAX*K],xortag[MAX*K],qv,res;
	int newnode()
	{
		tot++;
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=ortag[tot]=andtag[tot]=xortag[tot]=0;
		return tot;
	}
	void init()
	{
		nex[0][0]=nex[0][1]=cnt[0]=tot=0;
		ortag[0]=andtag[0]=xortag[0]=0;
		root=newnode();
	}
	void maintain(int id,int s,type orx,type andx,type xorx)
	{
		if(!id) return;
		if(s==-1) return;
		if(ortag[id]==0 && andtag[id]==0 && xortag[id]==0)
		{
			ortag[id]=orx;
			andtag[id]=andx;
			xortag[id]=xorx;
			return;
		}
	/*	for(int i=s;i>=0;i--)
		{
			if((orx>>i)&1)
			{
				ortag[id]|=(1<<i);
				if((andtag[id]>>i)&1) andtag[id]^=(1<<i);
				if((xortag[id]>>i)&1) xortag[id]^=(1<<i);
			}
			else if((andx>>i)&1)
			{
				andtag[id]|=(1<<i);
				if((ortag[id]>>i)&1) ortag[id]^=(1<<i);
				if((xortag[id]>>i)&1) xortag[id]^=(1<<i);
			}
			else if((xorx>>i)&1)
			{
				if(((andtag[id]>>i)&1)||((ortag[id]>>i)&1))
				{
					andtag[id]^=(1<<i);
					ortag[id]^=(1<<i);
				}
				else xortag[id]^=(1<<i);
			}
		}*/
		
		andtag[id]^=(andtag[id]&orx);
		xortag[id]^=(xortag[id]&orx);
		ortag[id]|=orx;
		
		ortag[id]^=(ortag[id]&andx);
		xortag[id]^=(xortag[id]&andx);
		andtag[id]|=andx;
		
		int tmp=(andtag[id]|ortag[id])&xorx;
		andtag[id]^=tmp;
		ortag[id]^=tmp;
		xortag[id]^=(xorx^tmp);
	}
	void pushup(int id)
	{
		if(!id) return;
		cnt[id]=cnt[nex[id][0]]+cnt[nex[id][1]];
	}
	void pushdown(int id,int s)
	{
		if(!id) return;
		if(s==-1) return;
		assert(((ortag[id]>>s)&1)+((andtag[id]>>s)&1)+((xortag[id]>>s)&1)<=1);
		if((ortag[id]>>s)&1)
		{
			nex[id][1]=merge(s-1,nex[id][1],nex[id][0]);
			nex[id][0]=0;
		}
		else if((andtag[id]>>s)&1)
		{
			nex[id][0]=merge(s-1,nex[id][0],nex[id][1]);
			nex[id][1]=0;
		}
		else if((xortag[id]>>s)&1) swap(nex[id][0],nex[id][1]);
		maintain(nex[id][0],s-1,ortag[id],andtag[id],xortag[id]);
		maintain(nex[id][1],s-1,ortag[id],andtag[id],xortag[id]);
		ortag[id]=andtag[id]=xortag[id]=0;
	}
	void insert(int &id,int s)
	{
		if(!id) id=newnode();
		if(s==-1)
		{
			cnt[id]++;
			return;
		}
		pushdown(id,s);
		int t;
		t=(qv>>s)&1;
		insert(nex[id][t],s-1);
		pushup(id);
	}
	int merge(int s,int x,int y)
	{
		if(!x||!y) return x+y;
		if(s==-1)
		{
			cnt[x]+=cnt[y];
			cnt[y]=0;
			return x;
		}
		pushdown(x,s);
		pushdown(y,s);
		nex[x][0]=merge(s-1,nex[x][0],nex[y][0]);
		nex[x][1]=merge(s-1,nex[x][1],nex[y][1]);
		pushup(x);
		return x;
	}
	void ask(int id,int s)
	{
		if(s==-1) return;
		assert(id);
		pushdown(id,s);
		int t;
		t=(qv>>s)&1;
		if(nex[id][t^1]&&cnt[nex[id][t^1]]) t^=1;
		res|=(t<<s);
		ask(nex[id][t],s-1);
		pushup(id);
//		cout<<id<<" "<<cnt[id]<<endl;
	}
	type ask_max(type x)
	{
		res=0;
		qv=x;
		ask(root,LOG);
		return res^x;
	}
	void upd(int op,type x)
	{
		if(op==2) maintain(root,LOG,x,0,0);
		else if(op==3) maintain(root,LOG,0,((1LL<<31)-1)^x,0);
		else if(op==4) maintain(root,LOG,0,0,x);
	}
	void insert(type x)
	{
		qv=x;
		insert(root,LOG);
	}
	#undef type
}tr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n,m,i,op,x;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		tr.init();
		for(i=1;i<=n;i++)
		{
			cin>>x;
			tr.insert(x);
		}
		while(m--)
		{
			cin>>op>>x;
			if(op==1) tr.insert(x);
			else if(op>=2 && op<=4) tr.upd(op,x);
			else if(op==5) cout<<tr.ask_max(x)<<"\n";
		}
	}
	return 0;
}
/*
3
5 10
1 2 3 4 5
5 1
1 10
5 2
2 3
5 3
3 12
5 4
4 7
5 5
5 13
5 30
0 5 9 4 15
2 8
3 11
2 15
4 11
2 13
1 1
2 10
1 11
1 13
5 5
5 15
1 1
4 15
4 10
1 8
4 4
4 0
3 8
3 3
3 0
5 0
1 14
1 1
4 1
5 1
2 10
5 9
1 12
4 11
4 3
5 30
4 13 6 15 8
1 7
4 11
5 11
4 11
5 15
2 13
1 11
5 15
4 3
1 14
2 8
3 9
5 4
1 6
3 6
5 3
4 10
3 15
2 13
1 10
4 0
1 10
5 10
2 15
4 3
3 10
5 14
4 9
2 7
3 6

5
8
8
12
10
14
14
4
0
14
6
15
11
4
12
5
7
6
*/
