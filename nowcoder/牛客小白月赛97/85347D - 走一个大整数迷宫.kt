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
data class pair(var fi:Long,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
var dir=arrayOf(
arrayOf(0,1),
arrayOf(1,0),
arrayOf(0,-1),
arrayOf(-1,0)
)
var mp=Array(12){IntArray(12){0}}
var dis=Array(12){Array(12){IntArray(10001)}}
data class node(var x:Int,var y:Int,var s:Int)
fun bfs(n:Int,m:Int,p:Int)
{
	for(i in 1..n)
	{
		for(j in 1..m)
		{
			for(k in 0..p-1)
			{
				dis[i][j][k]=INF
			}
		}
	}
	dis[1][1][mp[1][1]]=0
	val q:Queue<node> = LinkedList()
	q.offer(node(1,1,mp[1][1]))
	while(!q.isEmpty())
	{
		var t=q.peek()
		q.poll()
		for(i in 0..3)
		{
			var nex=t.copy()
			nex.x+=dir[i][0]
			nex.y+=dir[i][1]
			if(nex.x<1||nex.x>n||nex.y<1||nex.y>m) continue
			nex.s=(nex.s+mp[nex.x][nex.y])%p
			if(dis[t.x][t.y][t.s]+1<dis[nex.x][nex.y][nex.s])
			{
				dis[nex.x][nex.y][nex.s]=dis[t.x][t.y][t.s]+1
				q.offer(nex)
			}
		}
	}
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==3)
	var n=tmp_line[0]
	var m=tmp_line[1]
	var p=tmp_line[2]
	require(n>=1 && n<=10)
	require(m>=1 && m<=10)
	require(p>=2 && p<=1e4)
	for(i in 1..n)
	{
		tmp_line=readline_int()
		require(tmp_line.size==m)
		for(it in tmp_line) require(it>=0 && it<=1e6)
		for(j in 1..m)
		{
			if(p==2) mp[i][j]=0
			else mp[i][j]=tmp_line[j-1]%(p-1)
		}
	}
	for(i in 1..n)
	{
		tmp_line=readline_int()
		require(tmp_line.size==m)
		for(it in tmp_line) require(it>=0 && it<=1e6)
	}
	bfs(n,m,p-1)
	if(dis[n][m][0]==INF) println("-1")
	else println("${dis[n][m][0]}")
}

