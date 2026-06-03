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
const val MAX=1e5.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
class Disjoint_Set_Union()
{
	lateinit var pre:IntArray
	lateinit var sz:IntArray
	lateinit var dis:LongArray
	fun init(n:Int)
	{
		pre=IntArray(n+1){it}
		dis=LongArray(n+1){0}
	}
	fun find(x:Int):Int
	{
		if(pre[x]!=x)
		{
			var fa=pre[x]
			pre[x]=find(pre[x])
			dis[x]+=dis[fa]
		}
		return pre[x]
	}
	fun merge(a:Int,b:Int,k:Long):Boolean
	{
		// a->b
		var ra=find(a)
		var rb=find(b)
		if(ra==rb)
		{
			if(dis[a]-dis[b]==k) return true
			return false
		}
		pre[ra]=rb
		dis[ra]=dis[b]-dis[a]+k
		return true
	}
}
fun go()
{
	var T=readint()
	require(1<=T && T<=500)
	var sumn=0
	var sumq=0
	var res=mutableListOf<String>()
	while(T-->0)
	{
		var tmp_line1=readline_int()
		require(tmp_line1.size==2)
		var n=tmp_line1[0]
		var q=tmp_line1[1]
		require(1<=n && n<=5e5)
		require(1<=q && q<=5e5)
		sumn+=n
		sumq+=q
		require(sumn<=5e5)
		require(sumq<=5e5)
		var dsu=Disjoint_Set_Union()
		dsu.init(n+1)
		while(q-->0)
		{
			var tmp_line=readline_ll()
			var op=tmp_line[0].toInt()
			require(1<=op && op<=3)
			var u=0
			var v=0
			var k=0L
			if(op==1)
			{
				require(tmp_line.size==4)
				u=tmp_line[1].toInt()
				v=tmp_line[2].toInt()
				k=tmp_line[3]
				require(1<=u && u<=n)
				require(1<=v && v<=n)
				require(-1e12<=k && k<=1e12)
				if(dsu.merge(u,v,k)) res.add("OK")
				else res.add("CONTRADICTION")
			}
			else if(op==2)
			{
				require(tmp_line.size==3)
				u=tmp_line[1].toInt()
				k=tmp_line[2]
				require(1<=u && u<=n)
				require(-1e12<=k && k<=1e12)
				if(dsu.merge(u,n+1,k)) res.add("OK")
				else res.add("CONTRADICTION")
			}
			else
			{
				require(tmp_line.size==3)
				u=tmp_line[1].toInt()
				v=tmp_line[2].toInt()
				require(1<=u && u<=n)
				require(1<=v && v<=n)
				if(dsu.find(u)!=dsu.find(v)) res.add("UNKNOWN")
				else res.add("${dsu.dis[u]-dsu.dis[v]}")
			}
		}
	}
	println(res.joinToString("\n"))
}

