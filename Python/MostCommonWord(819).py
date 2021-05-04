## 가장 흔한 단어
import re, operator, collections
from typing import *

## 내풀이
def my_solution(paragraph: str, banned: List[str]) -> str:

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

def my_solution2(paragraph: str, banned: List[str]) -> str:

    words = []
    paragraph = re.sub(r'[^\w]', ' ',paragraph)

    for p in paragraph.split():

        if p.isalnum() and p.lower() not in banned:
            words.append(p.lower())
    words_count = collections.Counter(words)

    return words_count.most_common(1)[0][0]
if __name__ == '__main__':
    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
    banned = ["hit"]
    print(my_solution2(paragraph, banned))

