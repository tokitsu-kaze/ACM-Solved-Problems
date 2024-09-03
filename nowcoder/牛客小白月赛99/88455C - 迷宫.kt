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
var dis=Array(1){IntArray(1)}
var vx=IntArray(1)
var vy=IntArray(1)
fun bfs(n:Int,m:Int,sx:Int,sy:Int,mp:Array<CharArray>,f:Int)
{
	dis=Array(n){IntArray(m){INF}}
	dis[sx][sy]=0
	val q:Queue<node> = LinkedList()
	q.offer(node(sx,sy))
	while(!q.isEmpty())
	{
		var t=q.peek()
		q.poll()
		vx[t.x]=vx[t.x] or f
		vy[t.y]=vy[t.y] or f
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
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var m=tmp_line[1]
	require(n>=2 && n<=1000)
	require(m>=2 && m<=1000)
	var mp=Array(n){CharArray(m)}
	var sx=-1
	var sy=-1
	var tx=-1
	var ty=-1
	for(i in 0..n-1)
	{
		mp[i]=readline_char()
		require(mp[i].size==m)
		for(j in 0..m-1)
		{
			require(mp[i][j]=='#'||
					mp[i][j]=='.'||
					mp[i][j]=='S'||
					mp[i][j]=='E')
			if(mp[i][j]=='S')
			{
				require(sx==-1 && sy==-1)
				sx=i
				sy=j
			}
			else if(mp[i][j]=='E')
			{
				require(tx==-1 && ty==-1)
				tx=i
				ty=j
			}
		}
	}
	vx=IntArray(n){0}
	vy=IntArray(m){0}
	bfs(n,m,sx,sy,mp,1)
	bfs(n,m,tx,ty,mp,2)
	var ok=false
	for(i in 0..n-1)
	{
		if(vx[i]==3) ok=true
		if(i>0&&(vx[i] or vx[i-1])==3) ok=true
	}
	for(i in 0..m-1)
	{
		if(vy[i]==3) ok=true
		if(i>0&&(vy[i] or vy[i-1])==3) ok=true
	}
	if(ok) println("YES")
	else println("NO")
}

