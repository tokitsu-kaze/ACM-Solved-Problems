#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;

int root,last;
int tots;
int l;

int sv[maxn*2];
struct query
{
	int a;
	ll ans;
}qu[maxn];

struct sam_node
{
	int fa,son[26];
	int len;
	void init(int _len)
	{
		len = _len;
		fa = -1;
		memset(son,-1,sizeof(son));
	}
}t[maxn*2];

void sam_init()
{
	tots = 0;
	root = last = 0;
	t[tots].init(0);
}

void extend(int w)
{
	int p = last;
	int np = ++tots;
	t[tots].init(t[p].len+1);
	sv[l] = np;
	int q, nq;
	while(p != -1 && t[p].son[w] == -1)
	{
		t[p].son[w] = np;
		p = t[p].fa;
	}
	if(p == -1) t[np].fa = root;
	else
	{
		q = t[p].son[w];
		if (t[p].len+1 == t[q].len) t[np].fa=q;
		else
		{
			nq = ++tots;
			t[nq].init(0);
			t[nq] = t[q];
			t[nq].len = t[p].len+1;
			t[q].fa = nq;
			t[np].fa = nq;
			while(p!=-1&&t[p].son[w]==q)
			{
				t[p].son[w] = nq;
				p = t[p].fa;
			}
		}
	}
	last = np;
}

int w[maxn], r[maxn*2];

void topsort()
{
	for(int i = 0; i <= l; ++i) w[i] = 0;
	for(int i = 1; i <= tots; ++i) w[t[i].len]++;
	for(int i = 1; i <= l; ++i) w[i] += w[i-1];
	for(int i = tots; i >= 1; --i) r[w[t[i].len]--] = i;
	r[0] = 0;
}

int dp[maxn*2];
char s[maxn];


int main()
{
	int n, k, p;
	int _;

	while(scanf("%s",s)!=EOF)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int tl = strlen(s);
		l = 0;
		sam_init();
		for(int i = 0; i < tl; ++i)
		{
			++l;
			extend(s[i]-'A');
		}
		for(int i = 0; i <= tots; ++i) dp[i] = 0;
		topsort();
		p = root;
		for(int i = 0; i < l; ++i)
		{
			p = t[p].son[s[i]-'A'];
			dp[p]++;
		}
		for(int i = tots; i >= 1; --i)
		{
			p = r[i];
			if(t[p].fa != -1) dp[t[p].fa] += dp[p];
		}
		ll ans1 = 0, ans2 = 0;
		for(int i = 1; i <= tots; ++i)
			if(dp[i] >= a)
				ans1 += t[i].len-t[t[i].fa].len;
		for(int i = 1; i <= tots; ++i)
			if(dp[i] >= b+1)
				ans2 += t[i].len-t[t[i].fa].len;
		printf("%lld\n", ans1-ans2);
	}
	return 0;
}