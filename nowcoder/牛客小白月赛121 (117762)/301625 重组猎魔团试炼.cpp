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
var cnt=IntArray(10){0}
var ans=INF
fun dfs(x:Int,n:Int,now:Int,d:Int,f:Int)
{
	if(x==n)
	{
		if(now%d==0 && f==1) ans=min(ans,now)
		return
	}
	dfs(x+1,n,now,d,f)
	for(i in 0..9)
	{
		if(cnt[i]==0) continue
		cnt[i]--
		dfs(x+1,n,now*10+i,d,1)
		cnt[i]++
	}
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var d=tmp_line[1]
	require(1<=n && n<=8)
	require(1<=d && d<=100)
	var s=readstring()
	require(s.length==n)
	cnt=IntArray(10){0}
	for(it in s)
	{
		require('0'<=it && it<='9')
		cnt[(it-'0').toInt()]++
	}
	ans=INF
	dfs(0,n,0,d,0)
	if(ans==INF) ans=-1
	println("${ans}")
}

