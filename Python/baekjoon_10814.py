# 나이순 정렬(10814) 백준
#
import sys
from operator import itemgetter


t = int(sys.stdin.readline())
member_list = []


for i in range(t):
    info = sys.stdin.readline().split()
    age, name = int(info[0]), info[1]
    member_list.append([i, age, name])

member_list.sort(key=itemgetter(1,0))

for member in member_list:
    print(str(member[1]) + " " +member[2])
