#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        ll ans=1ll*sz(ideas)*(sz(ideas)-1)/2;
        int cnt[33];
        mem(cnt,0);
        unordered_map<string,int> mp;
        for(auto it:ideas)
        {
			cnt[it[0]-'a']++;
			mp[it]++;
		}
		int i,j,cnt2[33][33];
		mem(cnt2,0);
		for(auto it:ideas)
		{
			string tmp=it;
			tmp[0]='a';
			cnt[it[0]-'a']--;
			for(i=0;i<26;i++)
			{
				tmp[0]='a'+i;
				if(tmp[0]==it[0]) continue;
				if(mp.count(tmp))
				{
					ans-=cnt[tmp[0]-'a'];
					cnt2[it[0]-'a'][tmp[0]-'a']++;
				}
			}
			cnt[it[0]-'a']++;
		}
		for(i=0;i<26;i++)
		{
			ans-=1ll*cnt[i]*(cnt[i]-1)/2;
			for(j=i+1;j<26;j++)
			{
				ans+=1ll*cnt2[i][j]*cnt2[j][i];
			}
		}
		
        return ans*2;
    }
};

