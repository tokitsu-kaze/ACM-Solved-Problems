import os
import sys
from io import BytesIO, IOBase
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 

sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
"""****************************fastIO end************************************"""
from collections import deque
from collections import defaultdict
MAX=(int)(3e5+10)
mp=defaultdict(list)
def bfs(x):
    global mx,rt
    q=deque()
    q.append((x,0,1))
    while len(q)>0:
        x,fa,h=q.popleft()
        if mx<h:
            mx=h
            rt=x
        for to in mp[x]:
            if to==fa: continue
            q.append((to,x,h+1))


def go():
    n=int(input())
    mp.clear()
    for i in range(n-1):
        a,b=map(int,input().split())
        mp[a].append(b)
        mp[b].append(a)
    global mx,rt
    mx=0
    rt=1
    bfs(rt)
    mx=0
    bfs(rt)
    print((mx-1)*3)



if __name__ == '__main__':
    go()

