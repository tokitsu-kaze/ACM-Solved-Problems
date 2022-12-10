package main

import "fmt"
import "os"
import "bufio"
import "strconv"

func min(a,b int)int {
    var res int;
    if a<b {
        res=a
    } else {
        res=b;
    }
    return res;
}

func solve(){
    var s string
    s=readString()
    var n,i,ans,now,tmp,mod int
    mod=readInt()
    n=len(s)
    now=0
    tmp=1
    for i=0;i<n;i++ {
        now=now*10+(int)(s[i]-'0')
        now=now%mod
        if i>0 {
            tmp=tmp*10
            tmp=tmp%mod
        }
    }
    ans=now
    for i=0;i<n;i++ {
        if s[i]!='0' {
            ans=min(ans,now)
        }
        now=((now-(int)(s[i]-'0')*tmp%mod+mod)*10%mod+(int)(s[i]-'0'))%mod
    }
    fmt.Println(ans)
}


var scanner *bufio.Scanner

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	const MaxTokenLength = 1024 * 1024
	scanner.Buffer(make([]byte, 0, MaxTokenLength), MaxTokenLength)
	scanner.Split(bufio.ScanWords)
	solve()
}
func readString() string {
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	val, _ := strconv.Atoi(readString())
	return val
}

func readInt64() int64 {
	v, _ := strconv.ParseInt(readString(), 10, 64)
	return v
}