## 로그파일재정렬

## 내풀이
def my_solution(logs: []) -> []:
    digit_list = []
    letter_list = []
    for log in logs:
        identifier = "".join(log.split(" ")[1::])
        if identifier.isdigit():
            digit_list.append(log)
        else:
            letter_list.append(log)



    for i, v in enumerate(letter_list):


        for i1 in range(i + 1, len(letter_list)):
            main_identifier = letter_list[i].split(" ")[0]
            main_content = letter_list[i].split(" ")[1::]

            identifier = letter_list[i1].split(" ")[0]
            content = letter_list[i1].split(" ")[1::]

            if (content == main_content and identifier < main_identifier) or (content < main_content):
                temp_letter = letter_list[i1]
                letter_list[i1] = letter_list[i]
                letter_list[i] = temp_letter

    return letter_list + digit_list

## 람다와 + 연산자 이용
def solution1(logs: []) -> []:
    letters, digits = [], []

    for log in logs:
        if log.split()[1].isdigit():
            digits.append(log)
        else:
            letters.append(log)

    letters.sort(key=lambda x: (x.split()[1:], x.split()[0]))
    return letters + digits
if __name__ == '__main__':

    print(solution1(["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]))
    # ["27 85717 7", "2 y xyr fc", "52 314 99", "d 046099 0", "m azv x f", "7e apw c y", "8 hyyq z p", "6 3272401",
    #  "c otdk cl", "8 ksif m u"]

