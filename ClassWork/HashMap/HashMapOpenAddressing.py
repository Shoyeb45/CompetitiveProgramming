class Entry:
    def __init__(self, key, val) -> None:
        self.key = key
        self.value = val
        self.hashCode = hash(key)

class HashTable :
    def __init__(self):
        self.__size = 0
        self.__capacity = 6
        self.__data = [None] * self.__capacity


    def __getIndex(self, hash_code):
        return (hash_code % self.__capacity + self.__capacity) % self.__capacity
    
    def P(self, x):
        return 5 * x
    def insert(self, key, value):
        entry = Entry(key, value)
        index = self.__getIndex(entry.hashCode)

        i = 0
        while True:
            ind = index + self.P(i)
            ind = self.__getIndex(ind)
            if self.__data[ind] == None:
                self.__data[ind] = entry
                break
            i += 1