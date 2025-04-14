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
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
data class node(var v:Int,var w:Int)
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==3)
	var n=tmp_line[0]
	var x=tmp_line[1]
	var y=tmp_line[2]
	require(n>=1 && n<=100)
	require(x>=1 && x<=1e6)
	require(y>=1 && y<=100)
	var res=Array(n){mutableListOf<node>()}
	for(i in 0..n-1)
	{
		var c=readint()
		require(c>=1 && c<=10)
		var a=readline_int()
		require(a.size==c)
		var b=readline_int()
		require(b.size==c)
		for(j in 0..c-1)
		{
			require(a[j]>=1 && a[j]<=1e6)
			require(b[j]>=1 && b[j]<=100)
			res[i].add(node(a[j],b[j]))
		}
	}
	var predp=Array(n+1){LongArray(n+1){-LLINF}}
	predp[0][0]=0L
	var dp=Array(n+1){LongArray(n+1){-LLINF}}
	for(i in 0..n-1)
	{
		dp=Array(n+1){LongArray(n+1){-LLINF}}
		for(j in 0..n)
		{
			for(k in 0..n)
			{
				dp[j][k]=predp[j][k]
				for(it in res[i])
				{
					if(k>=it.w) dp[j][k]=max(dp[j][k],predp[j][k-it.w]+it.v)
				}
				if(k>=y) dp[j][k]=max(dp[j][k],predp[j][k-y]+x)
				if(j-1>=0) dp[j][k]=max(dp[j][k],predp[j-1][k])
			}
		}
		predp=dp
/*		for(j in 0..n)
		{
			for(k in 0..n)
			{
				println("${j} ${k} ${dp[j][k]}")
			}
		}*/
	}
	var ans=0L
	for(i in 0..n)
	{
		for(j in 0..i)
		{
			ans=max(ans,dp[i][j])
		}
	}
	println("${ans}")
}

