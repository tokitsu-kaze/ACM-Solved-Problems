s = list(input().split(','))
d = dict()
res = []
for x in s:
    if x not in d:
        res.append(x)
        d[x] = 1
    else:
        res.append(x + '_' + str(d[x] - 1))
        d[x] += 1
print(res)
