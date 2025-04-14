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
const val LOG=20
var mp=Array(1){mutableListOf<Int>()}
var fa=Array(1){IntArray(1)}
var dep=IntArray(1)
var mxdep=IntArray(1)
var res=Array(1){mutableListOf<Int>()}
fun dfs(x:Int,pre:Int)
{
	fa[0][x]=pre
	for(i in 1..LOG-1) fa[i][x]=fa[i-1][fa[i-1][x]]
	dep[x]=dep[pre]+1
	mxdep[x]=dep[x]
	for(to in mp[x])
	{
		if(to==pre) continue
		dfs(to,x)
		mxdep[x]=max(mxdep[x],mxdep[to])
	}
}
fun lca(xx:Int,yy:Int):Int
{
	var x=xx
	var y=yy
	if(dep[x]<dep[y]) x=y.also{y=x}
	var d=dep[x]-dep[y]
	for(i in 0..LOG-1)
	{
		if(((d shr i) and 1)==1) x=fa[i][x]
	}
	if(x==y) return x
	for(i in LOG-1 downTo 0)
	{
		if(fa[i][x]!=fa[i][y])
		{
			x=fa[i][x]
			y=fa[i][y]
		}
	}
	return fa[0][x]
}
fun ck(x:Int,n:Int):Boolean
{
	var z=0
	for(i in 1..n)
	{
		if(dep[i]>x)
		{
			if(z==0) z=i
			else z=lca(z,i)
		}
	}
	if(z==0) return true
	if(dep[z]>x) z=fa[0][z]
	for(i in 1..n)
	{
		var tmp=lca(z,i)
		if(z==tmp || i==tmp) continue
		if(dep[i]-1+(mxdep[z]-dep[z]+1)<=x &&
		   dep[z]-1+(mxdep[i]-dep[i]+1)<=x) return true
	}
	return false
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
	fa=Array(LOG){IntArray(n+5){0}}
	res=Array(n+1){mutableListOf<Int>()}
	dfs(1,0)
	var l=1
	var r=n
	while(l<r)
	{
		var mid=(l+r) shr 1
		if(ck(mid,n)) r=mid
		else l=mid+1
	}
	println("${l}")
}
/*
6
1 2
1 3
2 4
2 5
5 6
7
1 2
1 3
2 4
2 5
5 6
5 7
10
1 2
2 3
2 4
4 5
4 6
6 7
1 8
8 9
5 10
*/
