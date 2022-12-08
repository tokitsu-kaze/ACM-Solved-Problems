#define sz(x) ((int)x.size())
const int MAX=50000+10;
int d[MAX];
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int i;
        for(i=1;i<=n;i++)
        {
            d[i]=0;
        }
        for(auto it:roads)
        {
            d[it[0]+1]++;
            d[it[1]+1]++;
        }
        long long ans=0;
        sort(d+1,d+1+n);
        for(i=n;i;i--)
        {
            ans+=1ll*i*d[i];
        }
        return ans;
    }
};
