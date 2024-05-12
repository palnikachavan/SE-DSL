import assignment_3 as mod

r1 = int(input("Enter number of rows for matrix 1 :"))
c1 = int(input("Enter number of columns for matrix 1 :"))

r2 = int(input("Enter number of rows for matrix 2 :"))
c2 = int(input("Enter number of columns for matrix 2 :"))

mat1 = mod.Matrix(r1 ,c1)
mat2 = mod.Matrix(r2, c2)


mat3 = mat1.addition(mat2)
# choice = 'y'
# while choice == 'y':
#     print("""\t\t\tMenu
# 1. """)