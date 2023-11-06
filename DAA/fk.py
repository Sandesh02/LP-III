import time
arr=[]
n=int(input("enter number of items:"))
print("Enter profit and wieght of each item")
for i in range(n):
    p=int(input("Enter the profit:"))
    w=int(input("Enter the weight:"))
    arr.append([p,w])
capacity=int(input("Enter max capacity:"))
profit = 0
start=time.time()
arr = sorted(arr,key = lambda x : x[0] / x[1],reverse = True)

for i in range(len(arr)):
    itemwt = arr[i][1]
    itemp = arr[i][0]
    if(itemwt > capacity):
        profit += capacity*(itemp / itemwt)
        break
    else:
        profit += itemp
        capacity -= itemwt
print("max profit that can be achieved is :",profit)
end=time.time()

print("time taken to execute program is :",end-start)