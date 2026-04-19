str = input().lower()

mas = ['.', ',', '!', '?', ';', ':', '-',' ']

arr = []
flag = True

for i in str:
    for m in mas:
        if i == m:
            flag = False
    if flag:
        arr.append(i);
    flag = True
    
nflag = True
for i in range(len(arr)):
    if (arr[i] != arr[len(arr)-1-i]):
        nflag = False
        
if nflag:
    print("YES")
else:
    print("NO")
    

#print(arr)