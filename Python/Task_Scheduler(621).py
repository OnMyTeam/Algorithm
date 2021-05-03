## 태스크 스케쥴러
from typing import *

import collections

## 내풀이
def my_solution(tasks: List[str], n: int) -> int:
    result = []
    task_count = collections.Counter(tasks)

    run_task_index = collections.defaultdict(int)
    for task in tasks:
        run_task_index[task] = -1

    index = 0

    while True:

        loop_count = 0
        for k, v in task_count.most_common():


            if run_task_index[k] == -1 or (index - run_task_index[k]) > n:

                run_task_index[k] = index
                result.append(k)
                tasks.remove(k)

                index += 1
                task_count[k] -= 1

                loop_count = 0
                if task_count[k] == 0:
                    del task_count[k]

                break
            else:
                loop_count += 1


        if len(tasks) == 0:

            return len(result)

        if loop_count == len(task_count):
            result.append("idle")
            index += 1



## 우선순위 큐 이용
def solution1(tasks: List[str], n: int) -> int:
    counter = collections.Counter(tasks)
    print(counter)
    result = 0

    while True:
        sub_count = 0

        for task, _ in counter.most_common(n + 1):
            sub_count += 1
            result += 1
            counter.subtract(task)

            counter += collections.Counter()

        print("counter:", counter)
        if not counter:
            break

        result += n - sub_count + 1
    return result

## 석용
def solution2(tasks: List[str], n: int) -> int:
    counter = collections.Counter(tasks)
    time = 0
    while counter:  # Run until all tasks finished.

        sched_tasks = list(zip(*counter.most_common(n + 1)))[0]
        print(sched_tasks)
        counter.subtract(sched_tasks)
        counter += collections.Counter()
        time += n + 1
    print(sched_tasks)
    return time - (n + 1) + len(sched_tasks)

if __name__ == '__main__':
    # tasks = ["A","A","A","B","B","B", "C","C","C", "D", "D", "E"]
    # n = 2
    tasks = ["A","A","A","B","C","D"]
    n = 2
    print(solution2(tasks, n))