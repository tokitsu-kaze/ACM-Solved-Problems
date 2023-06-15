#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1505;
vector<ll> good_hash_prime={50331653,100663319,201326611,402653189,805306457,1610612741};
vector<ll> get_hash_prime(int cnt=2)
{
	assert(cnt<=good_hash_prime.size());
	srand(time(0));
	random_shuffle(good_hash_prime.begin(),good_hash_prime.end());
	return vector<ll>(good_hash_prime.begin(),good_hash_prime.begin()+cnt);
}
mt19937_64 rd(time(0));
struct hash_table
{
	ll seed,p;
	ll Hash[MAX],tmp[MAX];
	void set(ll _p)
	{
		seed=rd()%_p;
		p=_p;
	}
	void work(char *s,int n)
	{
		tmp[0]=1;
		Hash[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=tmp[i-1]*seed%p;
			Hash[i]=(Hash[i-1]*seed+s[i])%p;//may need change
		}
	}
	ll get(int l,int r)
	{
		return ((Hash[r]-Hash[l-1]*tmp[r-l+1])%p+p)%p;
	}
}ha;
char s[MAX];
int main()
{
	int m,i,n;
	set<ll> res;
	ha.set(get_hash_prime(1)[0]);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		ha.work(s,n);
		res.insert(ha.get(1,n));
	}
	printf("%d\n",res.size());
	return 0;
}
