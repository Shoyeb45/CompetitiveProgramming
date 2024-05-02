# importing library for generic data type
from typing import TypeVar

T = TypeVar("T")

# Making array
class Array:
    def __init__(self, cap: int, dataType: type):
        self.__capacity = cap
        self.__size = cap
        self.__data = [None] * cap
        self.__type = dataType

    def __getitem__(self, k: int) -> int:  # return type int
        if k >= 0 and k <= self.__size - 1:
            self.__size = self.__size + 1
            return self.__data[k]
        else:
            raise IndexError("Index out of bound : dikhta nahi he")
        
    def __setitem__(self, k: int, val: T):
        if type(val) != self.__type:
            raise TypeError("Not same data type")
        
        if k >= 0 and k <= self.__size - 1:
            self.__data[k] = val
        else:
            raise IndexError("Index out of bound : dikhta nahi he")

    def __str__(self):
        ans = ""
        for i in self.__data:
            if i != None:
                ans = ans + str(i) + " "
        return ans
    
    def __len__(self):
        return self.__size

    def __resize(self):
        newArray = [None] * 2 * self.__capacity
        for i in range(self.__size): 
            newArray[i] = self.__data[i]

        self.__capacity = 2 * self.__capacity
        self.__data = newArray
    
    def append(self, val: int):
        if self.__size < self.__capacity:
            self.__data[self.__size] = val
            self.__size += 1
        else:
            self.__resize()    
            self.__data[self.__size] = val
            self.__size += 1
            
    def delete(self, k: int):
        return None

a = Array(4, int)
a[0] = 24
a[1] = 934
a[3] = -12
a[2] = 112
print(a)
# a.append(22)
# print(a)
a.append(234)
print(a)

for x in a:
    print(x)