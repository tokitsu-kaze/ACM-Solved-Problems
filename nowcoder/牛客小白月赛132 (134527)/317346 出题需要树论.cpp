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
fun readline_ull()=(readLine()!!.split(" ").map{it.toULong()}).toULongArray()
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
var w=IntArray(1)
var l=IntArray(1)
var r=IntArray(1)
var tot=0
var k=0
var n=0
var ans=LLINF
var summx=LongArray(1)
var premx=LongArray(1)
var sufmx=LongArray(1)
var submx=LongArray(1)
fun dfs0(x:Int,fa:Int,sum:Long,now:Long)
{
	tot++
	l[x]=tot
	var nsum=sum+w[x]
	var nnow=now+(k xor w[x])
	summx[l[x]]=nsum
	submx[x]=nnow
	for(to in mp[x])
	{
		if(to==fa) continue
		dfs0(to,x,nsum,nnow)
		submx[x]=max(submx[x],submx[to])
	}
	r[x]=tot
}
fun dfs(x:Int,fa:Int,now:Long)
{
	var tmp=submx[x]+now
	if(l[x]-1>=1) tmp=max(tmp,premx[l[x]-1])
	if(r[x]+1<=n) tmp=max(tmp,sufmx[r[x]+1])
	ans=min(ans,tmp)
	var nnow=now+w[x]-(w[x] xor k)
	for(to in mp[x])
	{
		if(to==fa) continue
		dfs(to,x,nnow)
	}
}
fun go()
{
	var T=readint()
	require(1<=T && T<=1e4)
	var sumn=0
	var res=mutableListOf<Long>()
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		n=tmp_line[0]
		k=tmp_line[1]
		require(1<=n && n<=2e5)
		sumn+=n
		require(sumn<=2e5)
		require(1<=k && k<(1 shl 30))
		w=IntArray(n+1)
		mp=Array(n+1){mutableListOf<Int>()}
		tmp_line=readline_int()
		require(tmp_line.size==n)
		for(it in tmp_line) require(1<=it && it<(1 shl 30))
		for(i in 1..n) w[i]=tmp_line[i-1]
		var dsu=Disjoint_Set_Union()
		dsu.init(n)
		for(i in 1..n-1)
		{
			tmp_line=readline_int()
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
		l=IntArray(n+1)
		r=IntArray(n+1)
		tot=0
		summx=LongArray(n+1)
		submx=LongArray(n+1)
		dfs0(1,0,0L,0L)
		premx=LongArray(n+1){-LLINF}
		for(i in 1..n) premx[i]=max(premx[i-1],summx[i])
		sufmx=LongArray(n+2){-LLINF}
		for(i in n downTo 1) sufmx[i]=max(sufmx[i+1],summx[i])
		ans=LLINF
		dfs(1,0,0L)
		res.add(ans)
	}
	println(res.joinToString("\n"))
}
