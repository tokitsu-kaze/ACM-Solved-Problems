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
const val MAX=1e5.toInt()+10
const val mod=(1e9).toInt()+7
/*------------------------------------------------------------*/
const val LOG=20
var fa=Array(1){IntArray(1)}
var dep=IntArray(1)
var mp=Array(1){mutableListOf<Int>()}
var s=""
const val sd1=131L
const val sd2=233L
const val p1=(1e9).toLong()+7L
const val p2=998244353L
const val revsd1=190839696L
const val revsd2=844009174L
var t1=LongArray(1)
var t2=LongArray(1)
var revt1=LongArray(1)
var revt2=LongArray(1)
var hal1=LongArray(1)
var hal2=LongArray(1)
var har1=LongArray(1)
var har2=LongArray(1)
fun dfs(x:Int,pre:Int)
{
	dep[x]=dep[pre]+1
	fa[x][0]=pre
	var c=s[x].toLong()
	require(c>=0)
	hal1[x]=(hal1[pre]+c*t1[dep[x]-1])%p1
	hal2[x]=(hal2[pre]+c*t2[dep[x]-1])%p2
	har1[x]=(har1[pre]*sd1+c)%p1
	har2[x]=(har2[pre]*sd2+c)%p2
	for(i in 1..LOG-1) fa[x][i]=fa[fa[x][i-1]][i-1]
	for(to in mp[x])
	{
		if(to==pre) continue
		dfs(to,x)
	}
}
fun lca(xx:Int,yy:Int):Int
{
	var x=xx
	var y=yy
	if(dep[x]<dep[y]) x=y.also{y=x}
	var d=dep[x]-dep[y]
	for(i in 0..LOG-1)
	{
		if(((d shr i) and 1)==1) x=fa[x][i]
	}
	if(x==y) return x
	for(i in LOG-1 downTo 0)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i]
			y=fa[y][i]
		}
	}
	return fa[x][0]
}
fun init(n:Int)
{
	mp=Array(n+5){mutableListOf<Int>()}
	fa=Array(n+5){IntArray(LOG+1){0}}
	dep=IntArray(n+5){0}
	hal1=LongArray(n+5){0L}
	hal2=LongArray(n+5){0L}
	har1=LongArray(n+5){0L}
	har2=LongArray(n+5){0L}
	t1=LongArray((1 shl LOG)+5){0L}
	t2=LongArray((1 shl LOG)+5){0L}
	revt1=LongArray((1 shl LOG)+5){0L}
	revt2=LongArray((1 shl LOG)+5){0L}
	t1[0]=1L
	t2[0]=1L
	revt1[0]=1L
	revt2[0]=1L
	for(i in 1..(1 shl LOG))
	{
		t1[i]=t1[i-1]*sd1%p1
		t2[i]=t2[i-1]*sd2%p2
		revt1[i]=revt1[i-1]*revsd1%p1
		revt2[i]=revt2[i-1]*revsd2%p2
	}
}
fun ck(xx:Int,yy:Int,z:Int,
	t:LongArray,revt:LongArray,p:Long,
	hal:LongArray,har:LongArray):Boolean
{
	var x=xx
	var y=yy
	var faz=fa[z][0]
//	println("x,y,z: ${x} ${y} ${z}")
	var res1=(hal[x]-hal[z]+p)*revt[dep[z]]%p
//	println("${res1} ${res1*t[dep[y]-dep[faz]]}")
	res1=(res1*t[dep[y]-dep[faz]]+(har[y]-har[faz]*t[dep[y]-dep[faz]]%p+p))%p
	x=y.also{y=x}
	var res2=(hal[x]-hal[z]+p)*revt[dep[z]]%p
	res2=(res2*t[dep[y]-dep[faz]]+(har[y]-har[faz]*t[dep[y]-dep[faz]]%p+p))%p
	require(res1>=0 && res1<p)
	require(res2>=0 && res2<p)
//	println("${res1} ${res2}")
	return res1==res2
}
fun go()
{
	var n=readint()
	require(n>=1 && n<=1e5)
	init(n)
	s=readstring()
	require(s.length==n)
	s=" "+s
	var a=readline_int()
	require(a.size==n)
	var rt=-1
	for(i in 0..n-1)
	{
		require(a[i]>=0 && a[i]<=i)
		if(a[i]==0)
		{
			require(rt==-1)
			rt=i+1
		}
		else mp[a[i]].add(i+1)
	}
	require(rt==1)
	dfs(rt,0)
	var q=readint()
	require(q>=1 && q<=1e5)
	while(q-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var x=tmp_line[0]
		var y=tmp_line[1]
		var z=lca(x,y)
		if(ck(x,y,z,t1,revt1,p1,hal1,har1)&&
		   ck(x,y,z,t2,revt2,p2,hal2,har2)) println("YES")
		else println("NO")
	}
}

