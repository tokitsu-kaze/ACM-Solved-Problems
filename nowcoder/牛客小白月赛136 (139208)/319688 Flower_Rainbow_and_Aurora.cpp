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
data class pair(var fi:Int,var se:Long)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
data class node(var x:Int,var y:Int,var now:Int)
var dir=arrayOf(
arrayOf(0,1),
arrayOf(1,0),
arrayOf(0,-1),
arrayOf(-1,0)
)
var dis=Array(1){Array(1){IntArray(1)}}
var mp=Array(1){CharArray(1)}
fun bfs(n:Int,m:Int,s:String)
{
	dis=Array(n){Array(m){IntArray(3){-1}}}
	val q:Queue<node> = LinkedList()
	for(i in 0..2)
	{
		dis[n-1][m-1][i]=0
		q.offer(node(n-1,m-1,i))
	}
	while(!q.isEmpty())
	{
		var t=q.peek()
		q.poll()
		var pre=(t.now-1+3)%3
		for(k in 1..3)
		{
			if(mp[t.x][t.y]!=s[(pre+k-1)%3]) continue
			for(i in 0..3)
			{
				var nex=t.copy()
				nex.x+=dir[i][0]*k
				nex.y+=dir[i][1]*k
				nex.now=pre
				if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=m) continue
				if(dis[nex.x][nex.y][nex.now]==-1)
				{
					dis[nex.x][nex.y][nex.now]=dis[t.x][t.y][t.now]+1
					q.offer(nex)
				}
			}
		}
	}
}
fun go()
{
	var T=readint()
	require(1<=T && T<=1e4)
	var sumnm=0
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var m=tmp_line[1]
		require(1<=n && n<=1000)
		require(1<=m && m<=1000)
		sumnm+=n*m
		require(sumnm<=1e6)
		var s=readstring()
		require(s.length==3)
		for(it in s) require('a'<=it && it<='c')
		mp=Array(n){CharArray(m)}
		for(i in 0..n-1)
		{
			mp[i]=readline_char()
			require(mp[i].size==m)
			for(it in mp[i]) require('a'<=it && it<='c')
		}
		bfs(n,m,s)
		for(i in 0..n-1)
		{
			var tmp=IntArray(m)
			for(j in 0..m-1)
			{
				tmp[j]=dis[i][j][0]
			}
			println(tmp.joinToString(" "))
		}
	}
}

