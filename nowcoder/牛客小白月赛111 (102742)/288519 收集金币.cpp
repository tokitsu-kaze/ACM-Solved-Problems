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
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var m=tmp_line[1]
	var mp=Array(n+2){IntArray(m+2)}
	var tag=Array(n+2){IntArray(m+2){INF}}
	for(i in 1..n)
	{
		tmp_line=readline_int()
		require(tmp_line.size==m)
		for(j in 1..m)
		{
			mp[i][j]=tmp_line[j-1]
			require(mp[i][j]>=1 && mp[i][j]<=100)
		}
	}
	var k=readint()
	require(k>=1 && k<=n*m)
	for(i in 1..k)
	{
		tmp_line=readline_int()
		require(tmp_line.size==3)
		var x=tmp_line[0]
		var y=tmp_line[1]
		var v=tmp_line[2]
		require(x>=1 && x<=n)
		require(y>=1 && y<=m)
		require(v>=1 && v<=n*m)
		require(tag[x][y]==INF)
		tag[x][y]=v
	}
	tag[1][1]=INF
	var dp=Array(n+2){IntArray(m+2){0}}
	var ans=0
	for(i in 1..n)
	{
		for(j in 1..m)
		{
			if(tag[i][j]<=i+j-2) continue
			if(!(i==1 && j==1) && dp[i-1][j]==0 && dp[i][j-1]==0) continue
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+mp[i][j]
			ans=max(ans,dp[i][j])
//			println("${i} ${j} ${dp[i][j]}")
		}
	}
	println("${ans}")
}

