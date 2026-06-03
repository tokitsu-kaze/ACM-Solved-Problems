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
var sz=IntArray(1)
var ans=0L
var n=0
fun dfs(x:Int,fa:Int,h:Int)
{
	ans-=1L*(h+1)*h/2
	ans+=h
	ans%=mod
	sz[x]=1
	for(to in mp[x])
	{
		if(to==fa) continue
		dfs(to,x,h+1)
		sz[x]+=sz[to]
		ans+=1L*sz[to]*(n-sz[to])
		ans%=mod
	}
}
fun go()
{
	var T=readint()
	require(1<=T && T<=1e4)
	var sumn=0
	while(T-->0)
	{
		n=readint()
		require(2<=n && n<=2e5)
		sumn+=n
		require(sumn<=2e5)
		var dsu=Disjoint_Set_Union()
		dsu.init(n)
		mp=Array(n+1){mutableListOf<Int>()}
		for(i in 1..n-1)
		{
			var tmp_line=readline_int()
			require(tmp_line.size==2)
			var a=tmp_line[0]
			var b=tmp_line[1]
			require(1<=a && a<=n)
			require(1<=b && b<=n)
			require(a!=b)
			require(dsu.merge(a,b))
			mp[a].add(b)
			mp[b].add(a)
		}
		sz=IntArray(n+1){0}
		ans=0L
		dfs(1,0,0)
		ans=(ans%mod+mod)%mod
		println("${ans}")
	}
}

