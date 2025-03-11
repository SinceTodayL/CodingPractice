
record = set()
temp = []
for i in range(0, 120, 2):
    record.update(ele + i for ele in temp)
    temp.clear()
    t = i
    temp.append(t)
    for j in range(i - 2, 0, -2):
        temp.append(t + j)
        t += j
print(sorted(record)) 

