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
var dir=arrayOf(
arrayOf(0,1),
arrayOf(1,0),
arrayOf(0,-1),
arrayOf(-1,0)
)
var mp=Array(2){CharArray(1){'.'}}
var vis=Array(2){BooleanArray(1){false}}
var n=0
var h=0L
var b=0L
var ans=0L
var cnt=0L
fun dfs(x:Int,y:Int)
{
	if(vis[x][y]) return
//	println("${x} ${y} ${mp[x][y]}")
	vis[x][y]=true
	if(mp[x][y]=='W') cnt++
	if(mp[x][y]=='#') return
	for(i in 0..3)
	{
		var nx=x+dir[i][0]
		var ny=y+dir[i][1]
		if(nx<0||nx>=2||ny<0||ny>=n) continue
		dfs(nx,ny)
	}
}
fun dfs0(x:Int,y:Int,f:Int,now:Int)
{
	if(f==4)
	{
		vis=Array(2){BooleanArray(n+2){false}}
		cnt=0
		dfs(x,y)
//		println("${now} ${cnt}")
		ans=min(now*b+cnt*h,ans)
		return
	}
	var nx=x+dir[f][0]
	var ny=y+dir[f][1]
	if(nx<0||nx>=2||ny<0||ny>=n) dfs0(x,y,f+1,now)
	else
	{
		mp[nx][ny]='#'
		dfs0(x,y,f+1,now+1)
		mp[nx][ny]='.'
		dfs0(x,y,f+1,now)
	}
}
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var tmp_line=readline_int()
		n=tmp_line[0]
		h=tmp_line[1].toLong()
		b=tmp_line[2].toLong()
		mp[0]=readline_char()
		mp[1]=readline_char()
		var x=0
		var y=0
		for(i in 0..1)
		{
			for(j in 0..n-1)
			{
				if(mp[i][j]=='S')
				{
					x=i
					y=j
				}
			}
		}
		ans=LLINF
		dfs0(x,y,0,0)
		println("${ans}")
	}
}
