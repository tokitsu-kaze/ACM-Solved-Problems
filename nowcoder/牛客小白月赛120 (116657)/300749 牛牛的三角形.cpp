import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_char()=readLine()!!.toCharArray()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var fi:Long,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun qpow(aa:Long,bb:Int,p:Int):Long
{
	var res=1L
	var a=aa
	var b=bb
	while(b>0)
	{
		if((b and 1)==1) res=res*a%p
		a=a*a%p
		b=b shr 1
	}
	return res
}
fun inv(x:Long):Long
{
	return qpow(x,mod-2,mod)
}
var comb=Array(1501){IntArray(1501)}
fun init_comb(n:Int,m:Int)
{
	comb[0][0]=1;
	for(i in 1..n)
	{
		comb[i][0]=1;
		for(j in 1..m)
		{
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
			if(comb[i][j]>=mod) comb[i][j]-=mod;
		}
	}
}
fun C(n:Int,m:Int):Int
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}
const val K=17
fun go()
{
	init_comb(1500,1500)
	var ans=Array(1501){IntArray(K+1){0}}
	var sumdp=Array(1501){Array(1501){IntArray(K+1){0}}}
	sumdp[0][0][0]=1
	for(i in 1..1500)
	{
		sumdp[i][0][1]=1
		for(j in 1..i-1)
		{
			for(k in 1..min(i,K))
			{
				sumdp[i][j][k]=sumdp[j][min(i-j,j-1)][k-1]
			}
		}
		for(j in 0..i)
		{
			for(k in 0..K)
			{
				ans[i][k]+=sumdp[i][j][k]
				if(ans[i][k]>=mod) ans[i][k]-=mod
				if(j>0) sumdp[i][j][k]+=sumdp[i][j-1][k]
				if(sumdp[i][j][k]>=mod) sumdp[i][j][k]-=mod
			}
		}
	}
	
	for(i in 1..1500)
	{
		for(k in 1..K)
		{
			ans[i][k]+=ans[i-1][k]
			if(ans[i][k]>=mod) ans[i][k]-=mod
		}
	}
	var T=readint()
	require(1<=T && T<=3e5)
	var sumn=0
	var res=mutableListOf<Long>()
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var m=tmp_line[1]
		require(1<=n && n<=1500)
		require(1<=m && m<=n)
		if(n<=2)
		{
			res.add(0L)
			continue
		}
		if(m>K)
		{
			res.add(1L)
			continue
		}
		var tot=C(n,m).toLong()
		res.add((tot-ans[n][m]+mod)*inv(tot)%mod)
	}
	println(res.joinToString("\n"))
}
/*
总的-没有三角形的
发现没有三角形是斐波那契数列，个数不多，考虑dp
dp[i][j][k]表示前i个，上一个选j，已经选了k个
*/
