import assignment_1 as mod
SE = mod.Student(n = 50)
SE.lis = list(range(1,51))
print(SE)
obj = mod.Student()
nc = int(input("Enter number of students playing Cricket :"))
cric = mod.Student(n = nc)
cric.input()
nb = int(input("Enter number of students playing Badminton :"))
badmin = mod.Student(n = nb)
badmin.input()
nf = int(input("Enter number of students playing Football :"))
football = mod.Student(n = nf)
football.input()

choice = "y"
while choice == "y":
    print("""\t\t\t MENU
1. Both Cricket and Badminton.
2. Either Cricket or Badminton.
3. Neither Cricket Nor Badminton
4. Cricket and Football but not Badminton.""")
    op = int(input("Enter Operation :"))
    if op == 1:
        print("Cricket Team :")
        print(cric.lis)
        print("Badminton Team :")
        print(badmin.lis)
        final1 = cric.union(badmin)
        print("Result :",final1.lis)
    
    elif op == 2:
        print("Cricket Team :")
        print(cric.lis)
        print("Badminton Team :")
        print(badmin.lis)
        final2 = cric.union(badmin).subtraction(cric.intersection(badmin))
        print("Result :",final2.lis)

    elif op == 3:
        print("Cricket Team :")
        print(cric.lis)
        print("Badminton Team :")
        print(badmin.lis)
        print("Football Team :")
        print(football.lis)
        final3 = SE.subtraction(cric.union(badmin))
        # football.subtraction(football.intersection(cric).union(football.intersection(badmin)))
        print("Result :",final3.lis)

    elif op == 4:
        print("Cricket Team :")
        print(cric.lis)
        print("Badminton Team :")
        print(badmin.lis)
        print("Football Team :")
        print(football.lis)
        final4 = cric.union(badmin).subtraction(cric.intersection(badmin).intersection(football))
        print("Result :",final4.lis)

    else:
        print("Enter Valid Operation")

    choice = input("Do you want to continue? (y/n) :")
    choice = choice.lower()