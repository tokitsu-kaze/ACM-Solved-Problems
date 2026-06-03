import java.util.*
import kotlin.math.*
import kotlin.random.Random

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
const val MAX=1e7.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(1<=T && T<=2e4)
	var sumnm=0
	var res=mutableListOf<String>()
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==3)
		var n=tmp_line[0]
		var m=tmp_line[1]
		var k=tmp_line[2]
		require(1<=n && n<=1e3)
		require(1<=m && m<=1e3)
		require(0<=k && k<=n*m)
		sumnm+=n*m
		require(sumnm<=1e6)
		var ans=Array(n){IntArray(m){0}}
		var i=1
		var j=1
		while(i<n)
		{
			j=1
			while(j<m)
			{
				ans[i][j]=1
				j+=3
			}
			i+=3
		}
		if(n%3!=0)
		{
			j=1
			while(j<m)
			{
				ans[n-1][j]=1
				j+=3
			}
		}
		if(m%3!=0)
		{
			i=1
			while(i<n)
			{
				ans[i][m-1]=1
				i+=3
			}
		}
		if(n%3!=0 && m%3!=0) ans[n-1][m-1]=1
		var cnt=n*m
		for(i in 0..n-1)
		{
			for(j in 0..m-1)
			{
				cnt-=ans[i][j]
			}
		}
		if(cnt<k)
		{
			res.add("-1")
			continue
		}
		cnt-=k
		for(i in 0..n-1)
		{
			for(j in 0..m-1)
			{
				if(ans[i][j]==1) continue
				if(cnt>0)
				{
					cnt--
					ans[i][j]=1
				}
			}
			res.add(ans[i].joinToString(""))
		}
	}
	println(res.joinToString("\n"))
}

