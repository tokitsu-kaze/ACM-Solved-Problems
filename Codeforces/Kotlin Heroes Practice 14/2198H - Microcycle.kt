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
data class pair(var first:Int,var second:Int)
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e7.toInt()+10
const val mod=1e9.toInt()+7
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
const val LOG=20
var mp=Array(1){mutableListOf<pair>()}
var fa=Array(1){IntArray(1)}
var mn=Array(1){IntArray(1)}
var dep=IntArray(1)
var vis=IntArray(1)
fun dfs(x:Int,pre:Int)
{
	fa[0][x]=pre
	dep[x]=dep[pre]+1
	vis[x]=1
	for(i in 1..LOG-1)
	{
		fa[i][x]=fa[i-1][fa[i-1][x]]
		mn[i][x]=min(mn[i-1][fa[i-1][x]],mn[i-1][x])
	}
	for(it in mp[x])
	{
		var to=it.first
		var w=it.second
		if(to==pre) continue
		mn[0][to]=w;
		dfs(to,x)
	}
}
fun go(xx:Int,dd:Int):pair
{
	var res=INF
	var x=xx
	var d=dd
	for(i in 0..LOG-1)
	{
		if(((d shr i) and 1)==1)
		{
			d-=(1 shl i)
			res=min(res,mn[i][x])
			x=fa[i][x]
		}
	}
	return pair(x,res)
}
fun lca(xx:Int,yy:Int):pair
{
	var x=xx
	var y=yy
	if(dep[x]<dep[y]) x=y.also{y=x}
	var it=go(x,dep[x]-dep[y])
	x=it.first;
	var res=it.second;
	if(x==y) return pair(x,res)
	for(i in LOG-1 downTo 0)
	{
		if(fa[i][x]!=fa[i][y])
		{
			res=min(res,mn[i][x])
			res=min(res,mn[i][y])
			x=fa[i][x]
			y=fa[i][y]
		}
	}
	res=min(res,mn[0][x])
	res=min(res,mn[0][y])
	return pair(fa[0][x],res)
}
data class node(var x:Int,var y:Int,var w:Int)
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var tmp_line=readline_int()
		var n=tmp_line[0]
		var m=tmp_line[1]
		var dsu=Disjoint_Set_Union()
		var e=mutableListOf<node>()
		mp=Array(n+1){mutableListOf<pair>()}
		fa=Array(LOG){IntArray(n+1){0}}
		mn=Array(LOG){IntArray(n+1){INF}}
		dep=IntArray(n+1){0}
		vis=IntArray(n+1){0}
		dsu.init(n)
		for(i in 0..m-1)
		{
			tmp_line=readline_int()
			var a=tmp_line[0]
			var b=tmp_line[1]
			var c=tmp_line[2]
			if(dsu.merge(a,b))
			{
				mp[a].add(pair(b,c))
				mp[b].add(pair(a,c))
			}
			else e.add(node(a,b,c))
		}
		for(i in 1..n)
		{
			if(vis[i]==1) continue
			dfs(i,0)
		}
		var ans=INF
		var a=0
		var b=0
		for(it in e)
		{
			if(min(lca(it.x,it.y).second,it.w)<ans)
			{
				ans=min(lca(it.x,it.y).second,it.w)
				a=it.x
				b=it.y
			}
		}
		var ra=mutableListOf<Int>()
		var rb=mutableListOf<Int>()
		var res=mutableListOf<Int>()
		var ca=lca(a,b).first
		while(a!=ca)
		{
			ra.add(a)
			a=go(a,1).first
		}
		while(b!=ca)
		{
			rb.add(b)
			b=go(b,1).first
		}
		rb.reverse()
		for(it in ra) res.add(it)
		res.add(ca)
		for(it in rb) res.add(it)
		println("${ans} ${res.size}")
		println(res.joinToString(" "))
	}
}
