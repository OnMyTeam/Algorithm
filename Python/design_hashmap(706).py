## 해쉬테이블 구현


from collections import defaultdict
## 내풀이
class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 10000
        self.hashTable = [-1 for i in range(self.size)]
        self.discoveredCollision = defaultdict(int)
    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        hashValue = key % self.size
        if self.hashTable[hashValue] == -1:
            self.hashTable[hashValue] = value
        else:
            success = False
            for i in range(hashValue + 1, self.size):
                if self.hashTable[i] == -1:
                    self.hashTable[i] = value
                    self.discoveredCollision[key] = i
                    success = True
                    return
            if success == False:
                nextHashTable = [-1 for i in range(self.size)]
                self.hashTable + nextHashTable
                self.put(key, value)

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
            self.hashTable[hashValue] = -1
            self.discoveredCollision[key] = 0
        else:
            hashValue = key % self.size
            self.hashTable[hashValue] = -1

if __name__ == '__main__':

    Input = ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
    Input_Value = [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]

    # Input = ["MyHashMap", "remove", "put", "remove", "remove", "get", "remove", "put", "get", "remove", "put", "put", "put",
    #  "put", "put", "put", "put", "put", "put", "put", "put", "remove", "put", "put", "get", "put", "get", "put", "put",
    #  "get", "put", "remove", "remove", "put", "put", "get", "remove", "put", "put", "put", "get", "put", "put",
    #  "remove", "put", "remove", "remove", "remove", "put", "remove", "get", "put", "put", "put", "put", "remove", "put",
    #  "get", "put", "put", "get", "put", "remove", "get", "get", "remove", "put", "put", "put", "put", "put", "put",
    #  "get", "get", "remove", "put", "put", "put", "put", "get", "remove", "put", "put", "put", "put", "put", "put",
    #  "put", "put", "put", "put", "remove", "remove", "get", "remove", "put", "put", "remove", "get", "put", "put"]
    # Input_Value = [[], [27], [65, 65], [19], [0], [18], [3], [42, 0], [19], [42], [17, 90], [31, 76], [48, 71], [5, 50], [7, 68],
    #  [73, 74], [85, 18], [74, 95], [84, 82], [59, 29], [71, 71], [42], [51, 40], [33, 76], [17], [89, 95], [95],
    #  [30, 31], [37, 99], [51], [95, 35], [65], [81], [61, 46], [50, 33], [59], [5], [75, 89], [80, 17], [35, 94], [80],
    #  [19, 68], [13, 17], [70], [28, 35], [99], [37], [13], [90, 83], [41], [50], [29, 98], [54, 72], [6, 8], [51, 88],
    #  [13], [8, 22], [85], [31, 22], [60, 9], [96], [6, 35], [54], [15], [28], [51], [80, 69], [58, 92], [13, 12],
    #  [91, 56], [83, 52], [8, 48], [62], [54], [25], [36, 4], [67, 68], [83, 36], [47, 58], [82], [36], [30, 85],
    #  [33, 87], [42, 18], [68, 83], [50, 53], [32, 78], [48, 90], [97, 95], [13, 8], [15, 7], [5], [42], [20], [65],
    #  [57, 9], [2, 41], [6], [33], [16, 44], [95, 30]]
    myHashMap = None
    for i, i_v in enumerate(Input):
        if i == 0:
            myHashMap = MyHashMap();
            print(None)
            continue
        if Input[i] == "put":
            key, value = tuple(Input_Value[i])
            print(myHashMap.put(key, value))
        elif Input[i] == "get":
            key = Input_Value[i][0]
            print(myHashMap.get(key))
        else:
            key = Input_Value[i][0]
            print(myHashMap.remove(key))


