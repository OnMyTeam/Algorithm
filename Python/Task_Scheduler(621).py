## 태스크 스케쥴러
from typing import *

import collections

## 내풀이
def my_solution(tasks: List[str], n: int) -> int:
    result = []


    run_task_index = collections.defaultdict(int)
    for task in tasks:
        run_task_index[task] = -1

    index = 0
    loop_count = 0
    while tasks:
        if loop_count == len(tasks):
            result.append("Idle")
            index +=1
            loop_count = 0
        task = tasks.pop(0)

        if run_task_index[task] == -1 or (index - run_task_index[task]) > n:

            run_task_index[task] = index
            result.append(task)
            index += 1
            loop_count = 0

        else:
            loop_count += 1
            tasks.append(task)
            print(tasks)
    print(result)
    return result


if __name__ == '__main__':
    tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"]
    n = 2
    print(my_solution(tasks, n))