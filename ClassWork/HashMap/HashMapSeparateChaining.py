from typing import Any


class Entry:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.hash_code = hash(key)
    

class HashMap:
        
    def __init__(self):
        self.__size = 0
        self.__capacity = 5
        self.__data = [[] for i in range(self.__capacity)] 

    def __getIndex(self, hash_code):
        return (hash_code % self.__capacity + self.__capacity) % self.__capacity
    
    def get_size(self):
        return self.__size

    def insert(self, key, value):
        """
        This method takes two arguments: key and value. It will update the value if it is already present else it will insert the key into hash table
        """
        new_entry = Entry(key, value)
        index = self.__getIndex(new_entry.hash_code)

        for i in range(len(self.__data[index])):
            # if self.__data[index][i].key == key: 
            #     self.__data[index][i].value = value
            #     return
            if self.__data[index][i].hash_code == new_entry.hash_code :
                self.__data[index][i].value = value
                return
        
        self.__size += 1
        self.__data[index].append(new_entry)
        return
    
    def remove(self, key):
        index = self.__getIndex(hash(key))

        for i in range(len(self.__data[index])):
            if self.__data[index][i].key == key :
                self.__data[index].pop(i)
                self.__size -= 1
                return
        
        raise("Key not found")

        

    def get(key):
        pass

    def printBuckets(self):
        for i in range(self.__capacity):
            print("Bucket :", i, end = ':\n')
            for j in range(len(self.__data[i])):
                print(f"Key : {self.__data[i][j].key}, Value : {self.__data[i][j].value}", end = "\n")
            print()
        print("-" * 70)
    
    def __getitem__(self, key):
        # Getting Index
        index = self.__getIndex(hash(key))

        for i in range(len(self.__data[index])):
            if self.__data[index][i].key == key:
                return self.__data[index][i].value
        return None

hashtable = HashMap()

# hashtable.printBuckets()

hashtable.insert("Prakhar", 19)
hashtable.insert("Durgesh", 90)
hashtable.insert("Shoyeb", 19)
# hashtable.printBuckets()
hashtable.insert("Shoyeb", 20)

hashtable.printBuckets()

# print(hashtable["Shoyeb"])
# print(hashtable["Prakhar"])

hashtable.remove("Shoyeb")
hashtable.printBuckets()
# print(hashtable["Shoyeb"])