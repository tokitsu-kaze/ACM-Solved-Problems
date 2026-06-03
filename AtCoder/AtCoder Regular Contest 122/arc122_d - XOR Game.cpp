#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
struct Trie
{
	#define type int
	static const int LOG=30;
	static const int K=LOG+2;
	static const type inf=INF;
	int rt,root[MAX],tot,ch[MAX*K][2],cnt[MAX*K];
	Trie &operator[](const int _rt){this->rt=_rt;return *this;}
	int newnode()
	{
		tot++;
		memset(ch[tot],0,sizeof ch[tot]);
		cnt[tot]=0;
		return tot;
	}
	void init(int n=1)
	{
		ch[0][0]=ch[0][1]=cnt[0]=0;
		tot=1;
		for(int i=0;i<=n;i++) root[i]=0;
		rt=1;
	}
	void insert(type x)
	{
		int id,t,i;
		if(!root[rt]) root[rt]=newnode();
		id=root[rt];
		for(i=LOG;~i;i--)
		{
			cnt[id]++;
			t=(x>>i)&1;
			if(!ch[id][t]) ch[id][t]=newnode();
			id=ch[id][t];
		}
		cnt[id]++;
	}
	type ask_min(type x)
	{
		int id,i;
		type res,t;
		if(!root[rt]) return inf;
		id=root[rt];
		res=0;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(!ch[id][t]||!cnt[ch[id][t]]) t^=1;
			res|=(t<<i);
			id=ch[id][t];
		}
		return res^x;
	}
	#undef type
}tr;
int dfs(int s,vector<int> a)
{
	if(s==-1 || a.size()==0) return 0;
	vector<int> res[2];
	for(auto &it:a) res[(it>>s)&1].push_back(it);
	if(res[1].size()%2==0) return max(dfs(s-1,res[0]),dfs(s-1,res[1]));
	int ans=(1<<30);
	tr.init();
	for(auto &it:res[0]) tr.insert(it);
	for(auto &it:res[1]) ans=min(ans,tr.ask_min(it));
	return ans;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	n*=2;
	vector<int> a(n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	printf("%d\n",dfs(30,a));
	return 0;
}
/*
后手尽可能小，显然是找一个xor尽可能小的去匹配。
换句话说，如果钦定好一个匹配方案，先手选其中一个，后手一定能选另一个。
所以这是个假博弈。
从高位往低位考虑：
如果当前位为0，无事发生；
如果当前位为1：
如果是偶数，子树可以互相抵消；
如果是奇数，有一个一定无法抵消，这一位加入答案，
并且要从子树中选一个数跟另一个子树中的一个数匹配。
如何选？这时候直接遍历这些数，用01trie做即可。
然后由于要遍历数，所以上面步骤可以分治。
*/
