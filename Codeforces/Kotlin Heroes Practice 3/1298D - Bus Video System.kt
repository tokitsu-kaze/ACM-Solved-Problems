fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun main()
{
	var tmp=readline_int()
	var n=tmp[0]
	var w=tmp[1]
	var bit=Array<Long>(n+1){0}
	var l:Long=0
	var r:Long=w*1L
	var a=readline_ll()
	for(i in 0 until n)
	{
		bit[i+1]=bit[i]+a[i]
		r=minOf(r,w-bit[i+1])
		l=maxOf(l,-bit[i+1])
	}
	println("${maxOf(r-l+1,0)}")
}
