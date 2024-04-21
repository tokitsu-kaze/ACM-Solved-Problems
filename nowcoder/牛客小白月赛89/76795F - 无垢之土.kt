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
inline fun <T:Number> lower_bound_pos(
a:MutableList<T>,L:Int,R:Int,target:T):Int{
	var l=L
	var r=R
	var mid:Int
	while(l<r){
    	mid=(l+r) shr 1
    	if(a[mid].toLong()>=target.toLong()) r=mid
    	else l=mid+1
    }
	return l
}
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
/*------------------------------------------------------------*/
class Disjoint_Set_Union()
{
	var pre=IntArray(1){0}
	var sz=IntArray(1){0}
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
class Dijkstra()
{
	data class node(var id:Int,var pre:Int,var bir:Int,var v:Int)
	var mp=Array(1){mutableListOf<node>()}
	var dis=IntArray(1)
	var ndis=IntArray(1)
	var bir=IntArray(1)
	var nbir=IntArray(1)
	var vis=BooleanArray(1)
	var n=0
	fun init(_n:Int)
	{
		n=_n
		mp=Array(n+1){mutableListOf<node>()}
	}
	fun add_edge(x:Int,y:Int,v:Int){mp[x].add(node(y,0,0,v))}
	fun work(s:Int)
	{
		var q=PriorityQueue<node>(compareBy({it.v}))
		dis=IntArray(n+1){INF}
		ndis=IntArray(n+1){INF}
		bir=IntArray(n+1){-1}
		nbir=IntArray(n+1){-1}
		vis=BooleanArray(n+1){false}
		dis[s]=0;
		q.add(node(s,0,-1,0))
		while(q.size>0)
		{
			var t=q.peek()
			q.poll()
			if(t.v>ndis[t.id]) continue
			for(it in mp[t.id])
			{
				var to=it.id
				if(t.pre==to) continue
				var w=it.v
				var b:Int
				if(t.bir==-1&&t.id!=s) b=w
				else b=t.bir
				if(dis[to]>t.v+w)
				{
					ndis[to]=dis[to]
					nbir[to]=bir[to]
					dis[to]=t.v+w
					bir[to]=b
					q.add(node(to,t.id,bir[to],dis[to]))
				}
				else if(ndis[to]>t.v+w)
				{
					ndis[to]=t.v+w
					nbir[to]=b
					q.add(node(to,t.id,nbir[to],ndis[to]))
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
	require(n>=1 && n<=1e5)
	require(m>=2 && m<=1e5)
	var dij=Dijkstra()
	var s=n+m+1
	dij.init(s)
	var dsu=Disjoint_Set_Union()
	dsu.init(n)
	for(i in 1..n-1)
	{
		tmp_line=readline_int()
		require(tmp_line.size==2)
		var a=tmp_line[0]
		var b=tmp_line[1]
		require(a>=1 && a<=n)
		require(b>=1 && b<=n)
		dij.add_edge(a,b,1)
		dij.add_edge(b,a,1)
		require(dsu.merge(a,b))
	}
	for(i in 1..m)
	{
		tmp_line=readline_int()
		require(tmp_line.size==2)
		var a=tmp_line[0]
		var w=tmp_line[1]
		require(a>=1 && a<=n)
		require(w>=0 && w<=1e6)
		dij.add_edge(s,n+i,0)
		dij.add_edge(n+i,a,w)
	}
	dij.work(s)
	var ans=INF
	for(i in 1..n)
	{
		if(dij.dis[i]<dij.nbir[i]) ans=min(ans,dij.ndis[i]*2)
		else ans=min(ans,dij.dis[i]+dij.ndis[i])
	}
	println("${ans}")
}
/*
3 2
1 2
1 3
2 1
3 10
*/
