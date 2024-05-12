class Sort():
    def __init__(self, n):
        self.lis = []
        self.n = n

    def getData(self):
        for i in range(self.n):
            element = int(input("Enter Rollno :"))
            self.lis.append(element)
        print(self.lis)

    def bubble_sort(self):
        for i in range(self.n):
            swap = False
            for j in range(self.n - i - 1):
                if self.lis[j] > self.lis[j + 1]:
                    swap = True
                    self.lis[j], self.lis[j + 1] = self.lis[j + 1], self.lis[j]
            if swap == False:
                break
        print(self.lis)


    def insertion_sort(self):
        for i in range(self.n):
            key = self.lis[i]
            j = i - 1
            while j >= 0 and key < self.lis[j]:
                self.lis[j + 1] = self.lis[j]
                j -= 1
            self.lis[j + 1] = key
        print(self.lis)

    def selection_sort(self):
        for i in range(self.n):
            idx = i
            for j in range(i + 1,self.n):
                if self.lis[idx] > self.lis[j]:
                    idx = j

            self.lis[i], self.lis[idx] = self.lis[idx], self.lis[i]
        print(self.lis)

    def shell_sort(self):
        gap = self.n//2
        while gap > 0:
            j = gap
            while j < self.n:
                i = j - gap
                while i >= 0:
                    if self.lis[i + gap] > self.lis[i]:
                        break
                    else:
                        self.lis[i + gap], self.lis[j] = self.lis[j], self.lis[i + gap]
                    i -= gap
                j += 1
            gap //= 2
        print(self.lis)


    def partition(self, left, right):
        i = left
        j = right
        pivot = self.lis[right]
        while i < j:
            while i < right and self.lis[i] < pivot:
                i += 1
            while j > left and self.lis[j] >= pivot:
                j -= 1
            if i < j:
                self.lis[i], self.lis[j] = self.lis[j], self.lis[i]
        if self.lis[i] > pivot:
            self.lis[i], self.lis[right] = self.lis[right], self.lis[i]
        return i
    
    def quick_sort(self,left, right):
        if left < right:
            posn = self.partition(left, right)
            self.quick_sort(posn + 1 , right)
            self.quick_sort(left, posn - 1)
        return self.lis




n = int(input('Enter number of elements :'))
obj1 = Sort(n)
obj1.getData()
print("Bubble sort :")
obj1.bubble_sort()
print("Insertion Sort :")
obj1.insertion_sort()
print("Selection Sort :")
obj1.selection_sort()
print("Shell Sort :")
obj1.shell_sort()
print("Quick Sort :")
lis = obj1.quick_sort(0,n - 1)
print(lis)