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
fun go()
{
	var T=readint()
	require(T>=1 && T<=10)
	var sumn=0
	var summ=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var m=tmp_line[1]
		require(n>=2 && n<=2e5)
		require(m>=1 && m<=2e5)
		sumn+=n
		summ+=m
		require(sumn>=1 && sumn<=2e5)
		require(summ>=1 && summ<=2e5)
		var a=IntArray(m+1)
		var b=IntArray(m+1)
		var d=IntArray(n+1){0}
		var ck=mutableListOf<pair>()
		for(i in 1..m)
		{
			tmp_line=readline_int()
			require(tmp_line.size==2)
			a[i]=tmp_line[0]
			b[i]=tmp_line[1]
			require(a[i]>=1 && a[i]<=n)
			require(b[i]>=1 && b[i]<=n)
			require(a[i]!=b[i])
			d[a[i]]++
			d[b[i]]++
			if(a[i]<b[i]) ck.add(pair(a[i],b[i]))
			else ck.add(pair(b[i],a[i]))
		}
		ck.sortWith(cmp)
		for(i in 1..ck.size-1) require(!(ck[i].fi==ck[i-1].fi&&ck[i].se==ck[i-1].se))
		var mp=Array(n+1){mutableListOf<pair>()}
		for(i in 1..m)
		{
			if(d[a[i]]>d[b[i]]) a[i]=b[i].also{b[i]=a[i]}
			else if(d[a[i]]==d[b[i]])
			{
				if(a[i]>b[i]) a[i]=b[i].also{b[i]=a[i]}
			}
			mp[a[i]].add(pair(b[i],i))
		}
		var dsu=Disjoint_Set_Union()
		dsu.init(m)
		var vis=Array<pair>(n+1){pair(0,0)}
		for(i in 1..n)
		{
			for(j in mp[i]) vis[j.fi]=pair(i,j.se)
			for(j in mp[i])
			{
				for(k in mp[j.fi])
				{
					if(vis[k.fi].fi!=i) continue
					dsu.merge(j.se,k.se)
					dsu.merge(j.se,vis[k.fi].se)
				}
			}
		}
		var cnt=0
		for(i in 1..m)
		{
			if(dsu.find(i)==i) cnt++
		}
//		println("${cnt}")
		if(cnt==1) println("Yes")
		else println("No")
	}
}

