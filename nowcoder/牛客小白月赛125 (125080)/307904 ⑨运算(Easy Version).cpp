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
data class node(var x:Int,var f:Int)
var dis=Array(MAX){IntArray(2){INF}}
fun bfs()
{
	val q:Queue<node> = LinkedList()
	q.offer(node(9,0))
	q.offer(node(99,0))
	q.offer(node(999,0))
	q.offer(node(9999,0))
	q.offer(node(99999,0))
	q.offer(node(999999,0))
	q.offer(node(9999999,0))
	dis[9][0]=0
	dis[99][0]=0
	dis[999][0]=0
	dis[9999][0]=0
	dis[99999][0]=0
	dis[999999][0]=0
	dis[9999999][0]=0
	while(!q.isEmpty())
	{
		var t=q.peek()
		q.poll()
		if(t.x%9==0 && t.f==0)
		{
			var nex=t.copy()
			nex.x/=9
			nex.f=1
			if(dis[t.x][t.f]+1<dis[nex.x][nex.f])
			{
				dis[nex.x][nex.f]=dis[t.x][t.f]+1
				q.offer(nex)
			}
		}
		if(t.x-9>=1)
		{
			var nex=t.copy()
			nex.x-=9
			if(dis[t.x][t.f]+1<dis[nex.x][nex.f])
			{
				dis[nex.x][nex.f]=dis[t.x][t.f]+1
				q.offer(nex)
			}
		}
	}
}
fun go()
{
	bfs()
	var T=readint()
	require(1<=T && T<=1e4)
	var sumx=0
	while(T-->0)
	{
		var x=readint()
		require(1<=x && x<=1e6)
		sumx+=x
		require(sumx<=1e6)
		println("${min(dis[x][0],dis[x][1])}")
	}
}

