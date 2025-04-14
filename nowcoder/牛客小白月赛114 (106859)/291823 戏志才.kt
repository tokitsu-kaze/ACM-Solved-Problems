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
var mp=Array(1){mutableListOf<Int>()}
var ok=0
var vis=BooleanArray(1){false}
fun dfs(x:Int)
{
	if(vis[x])
	{
		ok=1
		return
	}
	vis[x]=true
	for(to in mp[x]) dfs(to)
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var x=tmp_line[1]
	require(n>=2 && n<=1e5)
	require(x>=1 && x<=n)
	var a=readline_int()
	require(a.size==n)
	mp=Array(n+1){mutableListOf<Int>()}
	for(i in 1..n)
	{
		require(a[i-1]>=1 && a[i-1]<=n && a[i-1]!=i)
		mp[a[i-1]].add(i)
	}
	ok=0
	vis=BooleanArray(n+1){false}
	dfs(x)
	if(ok==1) println("Yes")
	else println("No")
}

