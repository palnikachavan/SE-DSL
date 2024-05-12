class Matrix:
    def __init__(self, r, c):
        self.mat = []
        self.r = r
        self.c = c
        for i in range(r):
            row = []
            for j in range(c):
                row.append(0)
            self.mat.append(row)

    def input(self):
        for i in range(self.r):
            row = []
            for j in range(self.c):
                element = int(input("Enter element :"))
                row.append(element)
            self.mat[i] = row

        
    def display(self):
        for i in range(self.r):
            print(self.mat[i])

    
    def addition(self, M1):
        # M1 is Object of Matrix class
        if self.r == M1.r:
            if self.c == M1.c:
                result = Matrix(self.r ,self.c)
                for i in range(self.r):
                    row = []
                    for j in range(self.c):
                        summ = self.mat[i][j] + M1.mat[i][j]
                        row.append(summ)
                    result.mat[i] = row
                return result

        else:
            print("Addition is not Possible. ")


    def subtraction(self, M1):
        # M1 is Object of Matrix class
        if self.r == M1.r:
            if self.c == M1.c:
                result = Matrix(self.r ,self.c)
                for i in range(self.r):
                    row = []
                    for j in range(self.c):
                        diff = self.mat[i][j] - M1.mat[i][j]
                        row.append(diff)
                    result.mat[i] = row
                return result

        else:
            print("Matrix Addition is NOT Possible. ")
    
    def transpose(self):
        result = Matrix(self.c, self.r)
        for i in range(self.c):
            row = []
            for j in range(self.r):
                row.append(self.mat[j][i])
            result.mat[i] = row
        return result
    
    def multiplication(self, M1):
        # M1 is Matrix Object
        # [self].[M1]
        if self.r == M1.c:
            if self.c == M1.r:
                result = Matrix(self.r, M1.c)
                for i in range(self.r):
                    for j in range(M1.c):
                        for k in range(M1.r):
                            result.mat[i][j] += self.mat[i][k] * M1.mat[k][j]
                return result    
        else:
            print("Matrix Multiplication is NOT Possible")