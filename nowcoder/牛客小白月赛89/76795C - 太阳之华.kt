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
var dir=arrayOf(
arrayOf(0,1),
arrayOf(1,0),
arrayOf(0,-1),
arrayOf(-1,0)
)
var flag=Array(1,{IntArray(1)})
var mp=Array(1,{CharArray(1)})
var n=0
var m=0
var cnt=0
fun dfs(x:Int,y:Int,cas:Int)
{
	if(flag[x][y]==1||mp[x][y]!='#') return
	flag[x][y]=1
	for(i in 0..3)
	{
		var xx=x+dir[i][0]
		var yy=y+dir[i][1]
		if(xx<0||yy<0||xx>=n||yy>=m) continue
		if(mp[xx][yy]=='.')
		{
			if(flag[xx][yy]<cas)
			{
				flag[xx][yy]=cas
				cnt++
			}
		}
		else if(mp[xx][yy]=='#') dfs(xx,yy,cas)
	}
}

fun go()
{
	var t=readint()
	require(t>=1 && t<=100)
	var sumn=0
	var summ=0
	while(t-->0)
	{
		var tmp_line=readline_int()
		n=tmp_line[0]
		m=tmp_line[1]
		require(n>=1 && n<=2000)
		require(m>=1 && m<=2000)
		sumn+=n
		summ+=m
		require(sumn<=2000)
		require(summ<=2000)
		mp=Array(n,{CharArray(m)})
		for(i in 0..n-1) mp[i]=readline_char()
		flag=Array(n,{IntArray(m){0}})
		var tot=0
		for(i in 0..n-1)
		{
			for(j in 0..m-1)
			{
				require(mp[i][j]=='#'||mp[i][j]=='.')
				if(mp[i][j]=='.') tot++
			}
		}
		if(tot==n*m)
		{
			println("Blue")
			continue
		}
		var ok=false
		var cas=0
		for(i in 0..n-1)
		{
			for(j in 0..m-1)
			{
				if(mp[i][j]=='#')
				{
					cnt=0
					cas++
					dfs(i,j,cas)
					if(cnt==tot)
					{
						ok=true
						break
					}
				}
			}
			if(ok) break
		}
		if(ok) println("Red")
		else println("Draw")
	}
}

