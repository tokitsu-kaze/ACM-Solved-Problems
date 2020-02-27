fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun main()
{
	var tmp=readline_int()
	var n=tmp[0]
	var m=tmp[1]
	var a=readline_int()
	var pos=0
	for(i in 0 until n)
	{
		if(a[i]==m) pos=i
	}
	var ans=1L
	var mp:MutableMap<Int,Int> = mutableMapOf()
	var mx=0
	var mn=0
	for(i in pos-1 downTo 0)
	{
		if(a[i]>m) mx++
		else mn++
		mp[mx-mn]=(mp[mx-mn]?:0)+1
	}
	ans+=mp[0]?:0
	ans+=mp[1]?:0
	mn=0
	mx=0
	for(i in pos+1 until n)
	{
		if(a[i]>m) mx++
		else mn++
		if(mx-mn==0||mx-mn==1) ans++
		ans+=mp[0-(mx-mn)]?:0
		ans+=mp[1-(mx-mn)]?:0
	}
	println("${ans}")
}
