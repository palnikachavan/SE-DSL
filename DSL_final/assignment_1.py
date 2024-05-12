class Student:
    def __init__(self, n = 0):  
        # int n
        self.n = n
        self.lis = []

    def input(self):
        i = 0
        while i != self.n:
            element = int(input("Enter Rollno :"))
            if element in self.lis:
                print("Repeating Element Enter Again. ")
            else:
                self.lis.append(element)
                i += 1

    def union(self, X):
        # X is Student Object
        res = X.lis
        for each in range(self.n):
            for every in range(len(res)):
                if self.lis[each] == res[every]:
                    flag = 0
                    break
                else:
                    flag = 1
            if flag == 1:
                res.append(self.lis[each])
        result = Student(n = len(res))
        result.lis = res
        return result
        
    
    def intersection(self, X):
        # X is Student Object 
        res = []
        for each in range(self.n):
            for every in range(X.n):
                if self.lis[each] == X.lis[every]:
                    res.append(self.lis[each])
                    break
        result = Student(n = len(res))
        result.lis = res
        return result
    
    def complement(self, X):
        # X is universal Set-->dtype is list
        res = X
        for each in range(self.n):
            if self.lis[each] in res:
                res.remove(self.lis[each])
        result = Student(n = len(res))
        result.lis = res
        return result
    
    def subtraction(self, X):
        # X is Student Object  self - X
        inter = Student()
        inter.lis = self.intersection(X).lis
        inter.n = self.intersection(X).n
        res = self.lis
        for i in range(inter.n):
            res.remove(inter.lis[i])
        result = Student(n = len(res))
        result.lis = res
        return result

# class Stud:
#     def __init__(self,rn):
#         # rn --> roll no
#         self.rn = rn
    
# class s1(Stud):
