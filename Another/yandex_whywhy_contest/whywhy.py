N, C, R = map(int, input().split())

list1 = list(map(int, input().split()))  
list2 = list(map(int, input().split()))  

list2_have = [1] * R


for i in range(len(list1)):
    if list1[i] in list2:
        j = list2.index(list1[i])
        list2_have[j] = 0
        list1[i] = -1  

for i in range(len(list1)):
    if list1[i] == -1:
        continue

    got = False

    for j in range(len(list2)):
        if list2_have[j] == 1 and (list1[i] - 1 == list2[j] or list1[i] + 1 == list2[j]):
            list2_have[j] = 0
            got = True
            break

    if not got:
        N -= 1

print(N)