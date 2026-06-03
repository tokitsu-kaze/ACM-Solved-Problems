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
	var tmp_line=readline_int()
	require(tmp_line.size==3)
	var n=tmp_line[0]
	var m=tmp_line[1]
	var k=tmp_line[2]
	require(1<=n && n<=500)
	require(1<=m && m<=500)
	require(1<=k && k<=m)
	var a=readline_int()
	require(a.size==k)
	var tag=IntArray(m+1){0}
	for(i in 0..k-1)
	{
		require(1<=a[i] && a[i]<=m)
		if(i>1) require(a[i-1]<a[i])
		tag[a[i]]=1
	}
	var mp=Array(n+2){IntArray(m+2){0}}
	for(i in 1..n)
	{
		tmp_line=readline_int()
		require(tmp_line.size==m)
		for(j in 1..m)
		{
			mp[i][j]=tmp_line[j-1]
			require(0<=mp[i][j] && mp[i][j]<=1)
		}
	}
	var now=IntArray(n+1){0}
	var ans=0
	for(j in 1..m)
	{
		for(i in n downTo 1)
		{
			now[i]+=tag[j]
			now[i]-=mp[i][j]
			if(now[i]<0)
			{
				now[i-1]+=now[i]
				ans-=now[i]
				now[i]=0
			}
			ans+=now[i]
		}
	}
	for(i in 0..n)
	{
		if(now[i]!=0) ans=-1
	}
	println("${ans}")
}
