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
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
data class node(var x:Int,var y:Int)
var dir=arrayOf(
arrayOf(0,1),
arrayOf(1,0),
arrayOf(0,-1),
arrayOf(-1,0)
)
var mp=Array(1){CharArray(1)}
var dis=Array(1){IntArray(1)}
fun get_dis(n:Int,m:Int,res:MutableList<node>)
{
	dis=Array(n){IntArray(m){INF}}
	val q:Queue<node> = LinkedList()
	for(it in res)
	{
		dis[it.x][it.y]=0
		q.offer(it)
	}
	while(!q.isEmpty())
	{
		var t=q.peek()
		q.poll()
		for(i in 0..3)
		{
			var nex=t.copy()
			nex.x+=dir[i][0]
			nex.y+=dir[i][1]
			if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=m) continue
			if(mp[nex.x][nex.y]=='#') continue
			if(dis[nex.x][nex.y]>dis[t.x][t.y]+1)
			{
				dis[nex.x][nex.y]=dis[t.x][t.y]+1
				q.offer(nex)
			}
		}
	}
}
data class node_two(var x1:Int,var y1:Int,var x2:Int,var y2:Int)
var dis_two=Array(1){IntArray(1)}
fun bfs(n:Int,m:Int,x:Int,y:Int):Int
{
	var ans=INF
	dis_two=Array(n){IntArray(m){INF}}
	dis_two[x][y]=0
	val q:Queue<node_two> = LinkedList()
	q.offer(node_two(x,y,x,y))
	while(!q.isEmpty())
	{
		var t=q.peek()
		q.poll()
		for(i in 0..3)
		{
			var nex=t.copy()
			nex.x1+=dir[i][0]
			nex.y1+=dir[i][1]
			nex.x2+=dir[i][0]*(-1)
			nex.y2+=dir[i][1]*(-1)
			if(nex.x1<0||nex.x1>=n||nex.y1<0||nex.y1>=m) continue
			if(nex.x2<0||nex.x2>=n||nex.y2<0||nex.y2>=m) continue
			if(mp[nex.x1][nex.y1]=='#') continue
			if(mp[nex.x2][nex.y2]=='#') continue
			if(mp[nex.x1][nex.y1]=='@')
			{
				ans=min(ans,dis_two[t.x1][t.y1]+1+dis[nex.x2][nex.y2])
				continue
			}
			if(dis_two[nex.x1][nex.y1]>dis_two[t.x1][t.y1]+1)
			{
				dis_two[nex.x1][nex.y1]=dis_two[t.x1][t.y1]+1
				q.offer(nex)
			}
		}
	}
	if(ans==INF) ans=-1
	return ans
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==4)
	var n=tmp_line[0]
	var m=tmp_line[1]
	var x=tmp_line[2]
	var y=tmp_line[3]
	require(n>=1 && n<=2e3)
	require(m>=1 && m<=2e3)
	require(x>=1 && x<=n)
	require(y>=1 && y<=m)
	x--
	y--
	mp=Array(n){CharArray(m)}
	var res=mutableListOf<node>()
	for(i in 0..n-1)
	{
		mp[i]=readline_char()
		require(mp[i].size==m)
		for(j in 0..m-1)
		{
			require(mp[i][j]=='.' || mp[i][j]=='#' || mp[i][j]=='@')
			if(mp[i][j]=='@') res.add(node(i,j))
		}
	}
	require(mp[x][y]=='.')
	get_dis(n,m,res)
	println("${bfs(n,m,x,y)}")
}

