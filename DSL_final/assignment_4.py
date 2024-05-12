class Sort():
    def __init__(self, n):
        self.lis = [] 
        self.n = n
        i = 0
        while i != self.n:
            element = int(input("Enter Roll Number"))
            if element in self.lis:
                print("Repeating Element Enter Again.")
            else:
                self.lis.append(element)
                i += 1

    def linear_search(self, a):
        # int a
        i = 0
        while i != self.n:
            if self.lis[i] == a:
                print("Element found at position",i + 1)
                break
            i += 1

    def sentinel_search(self, a):
        self.lis.append(a)
        i = 0
        while self.lis[i] != a:
            i += 1
        if i == self.n:
            print("Element NOT found. ")
        else:
            print("Element found at position",i)
            
    def binary_search(self, a, s, e):
        self.lis.sort()
        mid = (s + e)//2
        print("MID", mid)
        if self.lis[mid] > a:
            e = mid - 1
            self.binary_search(a,s,e)
        elif self.lis[mid] < a:
            s = mid + 1
            self.binary_search(a,s,e)
        else:
            print("Element Found at position", mid)

    def fibonacci(self):
        fibm1 = 1
        fibm2 = 0
        fib = fibm1 + fibm2
        lis = [0, 1, 1]
        while fib < self.n:
            fibm2 = fibm1
            fibm1 = fib
            fib = fibm1 + fibm2
            lis.append(fib)
        return lis
        
    def fibonacci_search(self, a):
        fib = self.fibonacci()
        self.lis.sort()
        offset = -1
        m = 0
        while fib[m] < self.n:
            m += 1
        while fib[m] > 1:
            mid = min(offset + fib[m - 2], self.n - 1)
            if a > self.lis[mid]:
                m -= 1
                offset = mid
            elif a < self.lis[mid]:
                m -= 2
            else:
                return mid
        if fib[m - 2] == 1 and self.lis[offset + 1] == a:
            return offset + 1
        else:
            print("Element Not Found")