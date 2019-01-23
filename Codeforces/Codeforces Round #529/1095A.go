package main

import "fmt"
import "os"
import "bufio"
import "strconv"

func min(a,b int)int {
    var res int
    if a<b {
        res=a
    } else {
        res=b;
    }
    return res;
}

func solve(){
    var i,n,flag,cnt int
    var s,ans string
    n=readInt()
    s=readString()
    flag=1
    cnt=0
    for i=0;i<n;i++{
        cnt++
        if cnt==flag{
            flag++
            cnt=0
            ans=ans+(string)(s[i])
        }
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