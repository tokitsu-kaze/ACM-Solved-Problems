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
class Dijkstra()
{
	data class node(var id:Int,var v:Long)
	lateinit var mp:Array<MutableList<node>>
	lateinit var dis:LongArray
	lateinit var vis:BooleanArray
	var n=0
	fun init(_n:Int)
	{
		n=_n
		mp=Array(n+1){mutableListOf<node>()}
	}
	fun add_edge(x:Int,y:Int,v:Long){mp[x].add(node(y,v))}
	fun work(s:Int)
	{
		var q=PriorityQueue<node>(compareBy({it.v}))
		dis=LongArray(n+1){LLINF}
		vis=BooleanArray(n+1){false}
		dis[s]=0;
		q.add(node(s,0L))
		while(q.size>0)
		{
			var t=q.peek()
			q.poll()
			if(t.v>dis[t.id]) continue
			for(it in mp[t.id])
			{
				var to=it.id
				var w=it.v
				if(dis[to]>t.v+w)
				{
					dis[to]=t.v+w
					q.add(node(to,dis[to]))
				}
			}
		}
	}
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var m=tmp_line[1]
	require(2<=n && n<=2e5)
	require(1<=m && m<=2e5)
	var tmp=Array(n+1){mutableListOf<pair>()}
	while(m-->0)
	{
		tmp_line=readline_int()
		require(tmp_line.size==3)
		var a=tmp_line[0]
		var b=tmp_line[1]
		var c=tmp_line[2]
		require(1<=a && a<=n)
		require(1<=b && b<=n)
		require(0<=c && c<=1e9)
		tmp[a].add(pair(b,c))
		tmp[b].add(pair(a,c))
	}
	var dij=Dijkstra()
	dij.init(n)
	for(i in 1..n)
	{
		if(tmp[i].size==0) continue
		var mn=2*tmp[i][0].se
		for(it in tmp[i]) mn=min(mn,2*it.se)
		for(it in tmp[i])
		{
			dij.add_edge(i,it.fi,min(mn,it.se).toLong())
		}
	}
	dij.work(1)
	if(dij.dis[n]==LLINF) println("-1")
	else println("${dij.dis[n]}")
}

