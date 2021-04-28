## 태스크 스케쥴러
from typing import *

import collections

## 내풀이
def my_solution(tasks: List[str], n: int) -> int:
    result = []
    task_count = collections.Counter(tasks)

    run_task_index = collections.defaultdict(int)
    print(task_count)
    for task in tasks:
        run_task_index[task] = -1

    index = 0

    while True:

        loop_count = 0
        for k, v in task_count.items():


            if run_task_index[k] == -1 or (index - run_task_index[k]) > n:

                run_task_index[k] = index
                result.append(k)
                tasks.remove(k)

                index += 1
                task_count[k] -= 1
                print(task_count)
                loop_count = 0
                if task_count[k] == 0:
                    del task_count[k]
                break
            else:
                loop_count += 1


        if len(tasks) == 0:
            print(result)
            return len(result)

        if loop_count == len(task_count):
            result.append("idle")
            index += 1





if __name__ == '__main__':
    tasks = ["A","A","A","B","B","B", "C","C","C", "D", "D", "E"]
    n = 2
    print(my_solution(tasks, n))