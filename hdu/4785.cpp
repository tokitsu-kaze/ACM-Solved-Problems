////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-03 20:34:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4785
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1940KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
using namespace std;

#define eps 1e-8
#define LL long long
#define MP make_pair
#define mod 1000000007
#define mxn 25

int dcmp( double x ) {
    return (x > eps) - (x < -eps);
}

struct point {
    double x, y;
    point(){}
    point(double x, double y):x(x), y(y) {}
    point operator + (const point &b) const {
        return point(x + b.x, y + b.y);
    }
    point operator - (const point &b) const {
        return point(x - b.x, y - b.y);
    }
    point operator * (const double &b) const {
        return point(x * b, y * b);
    }
    bool operator < (const point &b) const {
        return x < b.x || x == b.x && y < b.y;
    }
    void input() {
        scanf( "%lf%lf", &x, &y );
    }
}P[mxn * mxn], BL, TR, pnt[mxn * mxn], res[mxn * mxn];

struct line { //直线是点加方向向量表示
    point p, v;
	double ang;
	line(){}
	line( point p, point v ) :p(p), v(v) { ang = atan2(v.y, v.x); }
	bool operator < ( const line &b ) const {
		return ang < b.ang;
	}
    bool operator == (const line &b) const {
        return dcmp(ang - b.ang) == 0;
    }
}L[mxn * mxn], Q[mxn * mxn];

struct polygon {
    point p[mxn * mxn];
    int sz;
    void input() {
        scanf( "%d", &sz );
        for( int i = 0; i < sz; ++i )
            p[i].input();
        p[sz] = p[0];
    }
}R, F[mxn], g[mxn];

pair<double, int> C[mxn * mxn];

double dot( point a, point b ) {
    return a.x * b.x + a.y * b.y;
}

double cross( point a, point b ) {
    return a.x * b.y - a.y * b.x;
}

int andrew( int n ) {
	sort( pnt, pnt + n );
	int m = 0;
	for( int i = 0; i < n; ++i ) {
		while( m > 1 && dcmp(cross( res[m-1] - res[m-2], pnt[i] - res[m-1] )) <= 0 )
			--m;
		res[m++] = pnt[i];
	}
	int k = m;
	for( int i = n - 2; i >= 0; --i ) {
		while( m > k && dcmp(cross( res[m-1] - res[m-2], pnt[i] - res[m-1] )) <= 0 )
			--m;
		res[m++] = pnt[i];
	}
	if( n > 1 ) --m;
	return m;
}

//半平面交

bool onleft( line l, point p ) {
	return cross( l.v, p - l.p ) > 0;
}

point lineinter( line a, line b ) {
	point u = a.p - b.p;
	double t = cross( b.v, u ) / cross( a.v, b.v );
	return a.p + a.v * t;
}

int halfplane( int n, int k ) {
	sort( L, L + n);
	int head = 0, tail = 0;
	Q[tail] = L[0];
	for( int i = 1; i < n; ++i ) {
		while( head < tail && !onleft( L[i], P[tail-1] ) ) --tail;
		while( head < tail && !onleft( L[i], P[head] ) ) ++head;
		Q[++tail] = L[i];
		if( dcmp( cross( Q[tail].v, Q[tail-1].v ) ) == 0 ) {
			--tail;
			if( onleft( Q[tail], L[i].p ) ) Q[tail] = L[i];
		}
		if( head < tail )
			P[tail-1] = lineinter( Q[tail-1], Q[tail] );
	}
	while( head < tail && !onleft( Q[head], P[tail-1] ) ) --tail;
	if( tail - head <= 1 ) return g[k].sz = 0;
	P[tail] = lineinter( Q[tail], Q[head] );
	int m = 0;
    for( int i = head; i <= tail; ++i ) g[k].p[m++] = P[i];
    g[k].p[m] = P[0];
	return g[k].sz = m;
}

//多边形面积并

double segP( point a, point b, point c ) {
	if( dcmp(b.x - c.x) )
		return (a.x - b.x) / (c.x - b.x);
	return (a.y - b.y) / (c.y - b.y);
}

double polyUnion( int n ) {
	double sum = 0;
	for( int i = 0; i < n; ++i ) 
	for( int ii = 0; ii < g[i].sz; ++ii ) {
		int tot = 0;
		C[tot++] = MP(0, 0);
		C[tot++] = MP(1, 0);
		for( int j = 0; j < n; ++j ) if( i != j ) 
		for( int jj = 0; jj < g[j].sz; ++jj ) {
			int d1 = dcmp(cross(g[i].p[ii+1] - g[i].p[ii], g[j].p[jj] - g[i].p[ii]));
			int d2 = dcmp(cross(g[i].p[ii+1] - g[i].p[ii], g[j].p[jj+1] - g[i].p[ii]));
			if( !d1 && !d2 ) {
				point t1 = g[j].p[jj+1] - g[j].p[jj];
				point t2 = g[i].p[ii+1] - g[i].p[ii];
				if( dcmp( dot(t1, t2) ) > 0 && j < i ) {
				    C[tot++] = MP(segP(g[j].p[jj], g[i].p[ii], g[i].p[ii+1]), 1);
				    C[tot++] = MP(segP(g[j].p[jj+1], g[i].p[ii], g[i].p[ii+1]), -1);
				}
			}
			else if( d1 >= 0 && d2 < 0 || d1 < 0 && d2 >= 0 ) {
				double d3 = cross(g[j].p[jj+1] - g[j].p[jj], g[i].p[ii] - g[j].p[jj]);
				double d4 = cross(g[j].p[jj+1] - g[j].p[jj], g[i].p[ii+1] - g[j].p[jj]);
				if( d2 < 0 )
					C[tot++] = MP(d3 / (d3 - d4), 1);
				else C[tot++] = MP(d3 / (d3 - d4), -1);
		    }
		}
		sort(C, C + tot);
		double cur = min(max(C[0].first, 0.0), 1.0);
		int sgn = C[0].second;
		double s = 0;
		for( int j = 1; j < tot; ++j ) {
			double nxt = min(max(C[j].first, 0.0), 1.0);
			if( !sgn ) s += nxt - cur;
			sgn += C[j].second;
			cur = nxt;
		}
		sum += cross(g[i].p[ii], g[i].p[ii+1]) * s;
	}
	return fabs(sum) / 2;
}

//根据Robot的形状缩小房间大小，并把房间左下角移动到(0, 0)

void Relax( int n ){
    double dlt;
    dlt = 0;
    for( int i = 0; i < R.sz; ++i ) dlt = max(dlt, R.p[0].x - R.p[i].x);
    BL.x += dlt;
    dlt = 0;
    for( int i = 0; i < R.sz; ++i ) dlt = max(dlt, R.p[i].x - R.p[0].x);
    TR.x -= dlt;
    dlt = 0;
    for( int i = 0; i < R.sz; ++i ) dlt = max(dlt, R.p[0].y - R.p[i].y);
    BL.y += dlt;
    dlt = 0;
    for( int i = 0; i < R.sz; ++i ) dlt = max(dlt, R.p[i].y - R.p[0].y);
    TR.y -= dlt;
    for( int i = 0; i < n; ++i )
        for( int j = 0; j <= F[i].sz; ++j )
            F[i].p[j] = F[i].p[j] - BL;
    for( int i = 0; i <= R.sz; ++i )
        R.p[i] = R.p[i] - BL;
    TR = TR - BL;
    BL = point(0, 0);
}

double solve( int n ) {
    for( int i = 0; i < n; ++i ) {
        polygon &t = F[i];
        int m = 0;
        L[m++] = line(point(0, 0), point(1, 0));
        L[m++] = line(point(TR.x, 0), point(0, 1));
        L[m++] = line(TR, point(-1, 0));
        L[m++] = line(point(0, TR.y), point(0, -1));
        //枚举家具的边和Robot的点
        for( int j = 0; j < t.sz; ++j ) {
            for( int k = 0; k < R.sz; ++k ) {
                bool ok = true;
                for( int l = 0; l < R.sz; ++l )
                    ok &= dcmp(cross(t.p[j+1] - t.p[j], R.p[l] - R.p[k])) <= 0;
                if( ok )
                    L[m++] = line(point(t.p[j] + R.p[0] - R.p[k]), t.p[j+1] - t.p[j]);
            }
        }
        //枚举Robot的边和家具的点
        for( int k = 1; k <= R.sz; ++k ) {
            for( int j = 0; j < t.sz; ++j ) {
                bool ok = true;
                for( int l = 0; l < t.sz; ++l )
                    ok &= dcmp(cross(R.p[k-1] - R.p[k], t.p[l] - t.p[j])) >= 0;
                if( ok )
                    L[m++] = line(t.p[j] + R.p[0] - R.p[k], R.p[k-1] - R.p[k]);
            }
        }
        halfplane(m, i);
        //半平面交得到的多边形理论上是凸的,貌似是精度问题,凸的不严格
        //不求一下凸包的话,多边形面积并的时候会有问题,卡了我一下午
        for( int j = 0; j < g[i].sz; ++j ) pnt[j] = g[i].p[j];
        g[i].sz = andrew(g[i].sz);
        for( int j = 0; j < g[i].sz; ++j ) g[i].p[j] = res[j];
        g[i].p[g[i].sz] = g[i].p[0];
    }
    return polyUnion(n);
}
int main()
{
    int T, cas = 0, n;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i )
            F[i].input();
        R.input();
        BL.input(); TR.input();
        Relax(n);
        double ans = TR.x * TR.y - solve(n);
        printf( "Case #%d: %.3lf\n", ++cas, ans );
    }
    return 0;
}
// http://blog.csdn.net/accelerator_916852/article/details/16808495