## 일정재구성

import collections
## 내풀이

def my_solution(tickets: [[str]]) -> [str]:
    result = []
    ticket_info = {}
    for ticket in tickets:

        departure = ticket[0]
        arrival = ticket[1]
        if ticket_info.get(departure) == None:
            ticket_info[departure] = []
            ticket_info[departure].append(arrival)
        else:
            prev_arrival = ticket_info[departure][0]
            if prev_arrival > arrival:
                ticket_info[departure].insert(0, arrival)
            else:
                ticket_info[departure].append(arrival)


    def DFS(start_departure):

        if ticket_info.get(start_departure) == None or not ticket_info[start_departure]:

            return

        while ticket_info[start_departure]:
            next_start_departure = ticket_info[start_departure].pop(0)
            result.append(next_start_departure)

            DFS(next_start_departure)
            for _, v in ticket_info.items():
                if v:
                    result.pop()
                    ticket_info[start_departure].append(next_start_departure)
                    break

    result.append("JFK")
    DFS("JFK")
    return result

def solution1(tickets: [[str]]) -> [str]:
    route = []
    graph = collections.defaultdict(list)
    for a, b in sorted(tickets):
        graph[a].append(b)
    print(graph)
    def dfs(a):

        while graph[a]:
            dfs(graph[a].pop(0))
        route.append(a)
        print(route)
    dfs('JFK')
    print(route)
    return route[::-1]
if __name__ == '__main__':

    # tickets = [["JFK", "KUL"], ["JFK", "NRT"], ["NRT", "JFK"]]
    tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    result = solution1(tickets)
    print(result)
