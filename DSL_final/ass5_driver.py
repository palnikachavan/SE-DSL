import assignment_5 as mod
n = int(input("Enter Number of Elements :"))
lis = mod.Sort(n)
listt = lis.quick_sort(0,n - 1)
print(listt)