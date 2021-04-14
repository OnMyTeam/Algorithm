## 로그파일재정렬
from collections import defaultdict
## 내풀이
class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 100
        self.hashTable = [-1 for i in range(self.size)]
        self.discoveredCollision = defaultdict(int)
        self.dataCount = 0
    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        hashValue = key % self.size
        if self.hashTable[hashValue] == -1:
            self.hashTable[hashValue] = value
        else:
            for i in range(hashValue + 1, self.size):
                if self.hashTable[i] == -1:
                    self.hashTable[i] = value
                    self.discoveredCollision[key] = i
                    return

        return
    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        if self.discoveredCollision[key] != 0:
            hashValue = self.discoveredCollision[key]
            return self.hashTable[hashValue]
        else:
            hashValue = key % self.size
            return self.hashTable[hashValue]
    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        if self.discoveredCollision[key] != 0:
            hashValue = self.discoveredCollision[key]
            del self.hashTable[hashValue]
        else:
            hashValue = key % self.size
            del self.hashTable[hashValue]

if __name__ == '__main__':
    Input = ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
    Input_Value = [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
    myHash = None
    for i, i_v in enumerate(Input):
        if i == 0:
            myHashMap = MyHashMap();
            continue
        if len(Input_Value[i]) == 1:
        print(myHashMap.put(1, 1))
        print(myHashMap.put(2, 2))
        print(myHashMap.get(1))
        print(myHashMap.get(3))
        print(myHashMap.put(2, 1))
        print(myHashMap.get(2))
        print(myHashMap.remove(2))
        print(myHashMap.get(2))