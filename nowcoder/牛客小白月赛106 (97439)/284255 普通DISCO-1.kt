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
const val mod=998244353//1e9.toInt()+7
const val MAX=300000+10
/*------------------------------------------------------------*/
class Disjoint_Set_Union()
{
	lateinit var pre:IntArray
	lateinit var sz:IntArray
	fun init(n:Int)
	{
		pre=IntArray(n+1){it}
		sz=IntArray(n+1){1}
	}
	fun find(x:Int):Int
	{
		if(pre[x]!=x) pre[x]=find(pre[x])
		return pre[x]
	}
	fun merge(a:Int,b:Int):Boolean
	{
		var ra=find(a)
		var rb=find(b)
		if(ra!=rb)
		{
			pre[ra]=rb
			sz[rb]+=sz[ra]
			return true
		}
		return false
	}
}
var mp=Array(1){mutableListOf<Int>()}
var dep=IntArray(1)
var mxdep=IntArray(1)
var ans=0
fun dfs(x:Int,fa:Int)
{
	dep[x]=dep[fa]+1
	mxdep[x]=dep[x]
	var mx=-1
	var nmx=-1
	for(to in mp[x])
	{
		if(to==fa) continue
		dfs(to,x)
		mxdep[x]=max(mxdep[x],mxdep[to])
		if(mxdep[to]>mx)
		{
			nmx=mx
			mx=mxdep[to]
		}
		else nmx=max(nmx,mxdep[to])
	}
	if(nmx!=-1) ans=max(ans,mx-dep[x]+nmx-1)
}
fun go()
{
	var n=readint()
	require(n>=3 && n<=5e5)
	mp=Array(n+1){mutableListOf<Int>()}
	var dsu=Disjoint_Set_Union()
	dsu.init(n)
	for(i in 1..n-1)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var a=tmp_line[0]
		var b=tmp_line[1]
		require(a>=1 && a<=n)
		require(b>=1 && b<=n)
		require(a!=b)
		require(dsu.merge(a,b))
		mp[a].add(b)
		mp[b].add(a)
	}
	dep=IntArray(n+1){0}
	mxdep=IntArray(n+1){0}
	ans=0;
	dfs(1,0)
	ans=max(ans,mxdep[1])
	println("${ans}")
}
