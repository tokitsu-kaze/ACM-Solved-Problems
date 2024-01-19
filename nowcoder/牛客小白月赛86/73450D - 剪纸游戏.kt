import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
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
val INF=0x3f3f3f3f
val LLINF=0x3f3f3f3f3f3f3f3fL
val MAX=2e5.toInt()+10
/*------------------------------------------------------------*/
var n=0
var m=0
var mp=mutableListOf<String>()
var flag=Array(1005){IntArray(1005)}
var dir=arrayOf(
arrayOf(0,1),
arrayOf(1,0),
arrayOf(0,-1),
arrayOf(-1,0)
)
fun bfs(x:Int,y:Int):Int
{
	val q:Queue<pair> = LinkedList()
	q.offer(pair(x,y))
	flag[x][y]=1
	var mnx=x
	var mny=y
	var mxx=x
	var mxy=y
	var cnt=1
	while(!q.isEmpty()){
		var t=q.peek()
		q.poll()
		for(i in 0..3){
			var xx=t.fi+dir[i][0]
			var yy=t.se+dir[i][1]
			if(xx<0||xx>=n||yy<0||yy>=m) continue
			if(mp[xx][yy]=='*') continue;
			if(flag[xx][yy]==1) continue;
			flag[xx][yy]=1
			q.offer(pair(xx,yy))
			cnt++
			mnx=min(mnx,xx)
			mny=min(mny,yy)
			mxx=max(mxx,xx)
			mxy=max(mxy,yy)
		}
	}
	if(cnt==(mxx-mnx+1)*(mxy-mny+1)) return 1
	return 0
}
fun go()
{
	var tmp_line=readline_int()
	n=tmp_line[0]
	require(n>=1 && n<=1000)
	m=tmp_line[1]
	require(m>=1 && m<=1000)
	mp=mutableListOf<String>()
	for(i in 0..n-1){
		var tmp=readstring()
		mp.add(tmp)
		for(j in 0..m-1){
			require(mp[i][j]=='.' || mp[i][j]=='*')
			flag[i][j]=0
		}
	}
	var ans=0
	for(i in 0..n-1){
		for(j in 0..m-1){
			if(flag[i][j]==1) continue
			if(mp[i][j]=='*') continue
			ans+=bfs(i,j)
		}
	}
	println("${ans}")
}

