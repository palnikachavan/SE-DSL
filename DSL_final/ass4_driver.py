import assignment_4 as mod
n = int(input("Enter Number of Students :"))
lis = mod.Sort(n)
a = int(input("Enter Roll Number to find :"))
x = lis.fibonacci_search(a)
print("output",x)