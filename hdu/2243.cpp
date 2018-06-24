////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-11-17 20:09:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2243
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1720KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=30+10;
const ll mod=1e9+7;
struct Matrix
{
	ull c[32][32],n;
	Matrix(){}
	Matrix(ull a,ull v=0)
	{
		int i,j;
		n=a;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				c[i][j]=v;
			}
		}
	}
	Matrix operator *(const Matrix &b)const
	{
		int i,j,k;
		Matrix res(n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					res.c[i][j]=(res.c[i][j]+c[i][k]*b.c[k][j]);
				}
			}
		}
		return res;
	}
};
Matrix matpow2(Matrix a,ull b)
{
	Matrix res(a.n);
	for(int i=0;i<a.n;i++)
	{
		res.c[i][i]=1;
	}
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
struct ACM
{
	int next[MAX][26],fail[MAX],cnt[MAX];
	int root,tot;
	int newnode()
	{
		int i;
		mem(next[tot],0);
		fail[tot]=0;
		cnt[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	void insert(char *s)
	{
		int len,now,i;
		len=strlen(s);
		now=root;
		for(i=0;i<len;i++)
		{
			int t=s[i]-'a';
			if(!next[now][t]) next[now][t]=newnode();
			now=next[now][t];
		}
		cnt[now]++;
	}
	void setfail()
	{
		int i,now;
		queue<int>q;
		for(i=0;i<26;i++)
		{
			if(next[root][i]) q.push(next[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			cnt[now]+=cnt[fail[now]];
			for(i=0;i<26;i++)
			{
				if(next[now][i])
				{
					fail[next[now][i]]=next[fail[now]][i];
					q.push(next[now][i]);
				}
				else next[now][i]=next[fail[now]][i];
			}
		}
	}
	ull solve(ull k)
	{
		Matrix res(tot+1);
		int i,j;
		for(i=0;i<tot;i++)
		{
			for(j=0;j<26;j++)
			{
				if(!cnt[next[i][j]]) res.c[i][next[i][j]]++;
			}
		}
		for(i=0;i<=tot;i++) res.c[i][tot]=1;
		res=matpow2(res,k);
		ull ans=0;
		for(i=0;i<=tot;i++)
		{
			ans+=res.c[0][i];
		}
		return ans;
	}
}acm;
int main()
{
	int n,i;
	ull k;
	char s[11];
	while(~scanf("%d%llu",&n,&k))
	{
		acm.init();
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			acm.insert(s);
		}
		acm.setfail();
		ull ans=acm.solve(k);
		Matrix temp(2);
		temp.c[0][0]=26;
		temp.c[1][1]=temp.c[1][0]=1;
		temp=matpow2(temp,k);
		printf("%llu\n",temp.c[0][0]+temp.c[1][0]-ans);
	}
	return 0;
}
