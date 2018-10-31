#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long  ll;
const int N = 4;
ll k, mod=(long long)(1e9+7);
////fn = fn - 1 + fn - 3 + fn - 4  2469
struct Mat {
	ll mat[N][N];
	Mat operator*(const Mat a)const
	{
		Mat b; memset(b.mat, 0, sizeof(b.mat));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					b.mat[i][j] = (b.mat[i][j] + (mat[i][k]) *(a.mat[k][j])) % mod;
		return b;
	}
};
Mat Pow(Mat m, ll k) {
	Mat ans;
	memset(ans.mat, 0, sizeof(ans.mat));
	for (int i = 0; i < N; i++)
		ans.mat[i][i] = 1;
	while (k) {
		if (k & 1) ans = ans*m;
		k >>= 1;
		m = m*m;
	}
	return ans;
}
void init(Mat &m) {
	memset(m.mat, 0, sizeof(m.mat));
	//m.mat[0][0] = m.mat[0][2] = m.mat[1][0] = m.mat[2][1]=m.mat[0][3]=m.mat[3][2] = 1;
	m.mat[0][0]=2;
	m.mat[0][1]=-1;
	m.mat[0][2]=3;
	m.mat[0][3]=2;
	m.mat[1][0]=1;
	m.mat[2][1]=1;
	m.mat[3][2]=1;
}
int main() {
	Mat m;
	int t;
	cin>>t;
	while (t--) {
		scanf("%lld",&k);

		if(k==1)
		{
			cout<<"3"<<endl;
			continue;
		}
		if(k==2)
		{
			cout<<"9"<<endl;
			continue;
		}
		k-=2;

		init(m);
		if (k == 1)
		{
			printf("%lld\n",20%mod);
			continue;
		}
		if (k == 2)
		{
			printf("%lld\n", 46 % mod);
			continue;
		}
		if (k == 3)
		{
			printf("%lld\n",106 % mod);
			continue;
		}
		if (k == 4)
		{
			printf("%lld\n", 244 % mod);
			continue;
		}
		Mat f;
		memset(f.mat, 0, sizeof(f.mat));
		f.mat[0][0] = 244;
		f.mat[1][0] = 106;
		f.mat[2][0] = 46;
		f.mat[3][0] = 20;
		m = Pow(m, k-4)*f;
		printf("%lld\n", m.mat[0][0]);
	}
	return 0;
}