## 전화번호문자조합


## 내풀이

def my_solution(digits: str) -> []:

    phone_letters = {
        "2": ["a", "b", "c"],
        "3": ["d", "e", "f"],
        "4": ["g", "h", "i"],
        "5": ["j", "k", "l"],
        "6": ["m", "n", "o"],
        "7": ["p", "q", "r", "s"],
        "8": ["t", "u", "v"],
        "9": ["w", "x", "y", "z"],
    }

    Output = []
    if digits == "":
        return Output
    def DFS(letter, index):
        if index >= len(digits):
            Output.append(letter)
            return
        digit = digits[index]

        for phone_letter in phone_letters[digit]:
            letter = letter + phone_letter
            DFS(letter, index + 1)
            letter = letter[:index]

    DFS('', 0)


    return Output
if __name__ == '__main__':

    print(my_solution(""))
