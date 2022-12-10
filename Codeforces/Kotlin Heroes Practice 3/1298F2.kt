fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
class Fenwick_Tree(var n:Int)
{
	var bit=Array(n+1){0}
	fun lowbit(x:Int):Int{return x and (-x)}
	fun insert(xx:Int,v:Int)
	{
		var x=xx
		while(x<=n)
		{
			bit[x]+=v
			x+=lowbit(x)
		}
	}
	fun get(xx:Int):Int
	{
		var res=0
		var x=xx
		while(x>0)
		{
			res+=bit[x]
			x-=lowbit(x)
		}
		return res
	}
	fun ask(l:Int,r:Int):Int
	{
		return get(r)-get(l-1)
	}
}
fun main()
{
	var tmp=readline_int()
	var n=tmp[0]
	var m=tmp[1]
	var a=readline_int()
	fun gao(x:Int):Long
	{
		var bit=Array(n+1){0}
		for(i in 0 until n)
		{
			bit[i+1]=bit[i]
			if(a[i]<=x) bit[i+1]++
			else bit[i+1]--
		}
		var t=Fenwick_Tree(2*n+1)
		t.insert(n+1,1)
		var res=0L
		for(i in 1 until n+1)
		{
			res+=t.ask(1,bit[i]+n+1)
			t.insert(bit[i]+n+1,1)
		}
		return res
	}
	println("${gao(m)-gao(m-1)}")
}
