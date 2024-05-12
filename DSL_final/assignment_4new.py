class Search():
    def __init__(self, n = 0):
        self.lis = []
        self.n = n

    def getdata(self):
        i = 0
        while (i != self.n):
            element = int(input("Enter Rollno :"))
            if element in self.lis:
                print("Repeating Element enter again :")
            else:
                self.lis.append(element)
                i += 1

    def fibonacci(self):
        res = [0, 1]
        for i in range(2, self.n):
            result = res[i - 1] + res[i - 2]
            res.append(result)
        return res


    def fibonacci_search(self,a):
        fib = self.fibonacci()
        self.lis.sort()
        print(self.lis)
        m = 0
        offset = -1
        while fib[m] < self.n:
            m += 1

        while fib[m] > 1:
            mid = min(offset + fib[m - 2], self.n - 1)
            if self.lis[mid] < a:
                offset = mid
                m -= 1
            elif self.lis[mid] > a:
                m -= 2
            else:
                return mid
        if fib[m - 2] == 1 and self.lis[offset + 1] == a:
            return offset + 1
        else:
            print("Element Not Found.")
        


n = int(input("Enter number of elements :"))
obj = Search(n)
obj.getdata()
f = int(input("Enter to find :"))
x = obj.fibonacci_search(f)
print(x)
