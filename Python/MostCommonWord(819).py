## 가장 흔한 단어
import re, operator, collections

## 내풀이
def my_solution(paragraph:str, banned: []) -> []:

    words_count = {}

    paragraph = re.sub(r'[^\w]', ' ', paragraph).lower()

    for banned_word in banned:
        paragraph = paragraph.replace(banned_word+" ", "").replace(banned_word, "")

    words = set(paragraph.split())

    for word in words:
        words_count[word] = 0
        for paragraph_word in paragraph.split():
            if word == paragraph_word:
                words_count[word] += 1
    sort_words_count = sorted(words_count.items(), key=operator.itemgetter(1), reverse=True)
    return sort_words_count[0][0]
if __name__ == '__main__':

    print(my_solution("a, a, a, a, b,b,b,c, c", ["a"]))

