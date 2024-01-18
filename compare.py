#!/usr/bin/env python3


# Problem:
# There are multiple two compare expression such as a < b or a <= b.
# The comparasion operator is always '<' or '<='.
# You are given many expression like this, please judge whether it is possible that all expressions are True.
# For example:
# 1. a < b, b <= a: False
# 2. a < b, b <= c, c <= d, d <= b: True

# Solution:
# We could use topological sort algorithm to solve this problem.
# But we should care about the equal operator.
# 1. find all nodes doesn't have from_nodes. For node x, there is not edge a -> x.
# 2. remove all edges from these nodes, delete all edges x -> y.
# 3. Repeat step 1 if could find such nodes.
# 4. For all the remained nodes, check all the edges between them are '<='

import re
from collections import Counter, deque


def construct(comps: list):
    from_nodes = dict()
    to_nodes = dict() # name -> dict(next_node -> is_equal)
    for x, y, eq in comps:
        to_nodes.setdefault(x, dict())
        to_nodes.setdefault(y, dict())
        if y not in to_nodes[x] or to_nodes[x][y]:
            to_nodes[x][y] = eq
        from_nodes.setdefault(x, dict())
        from_nodes.setdefault(y, dict())
        if x not in from_nodes[y] or from_nodes[y][x]:
            from_nodes[y][x] = eq
    return from_nodes, to_nodes


def check_cycle(from_nodes, to_nodes):
    if not from_nodes:
        return True
    que = deque()
    from_count = Counter()
    print(from_nodes)
    print(to_nodes)
    for node in from_nodes.keys():
        from_count[node] = len(from_nodes[node])
    for node in to_nodes.keys():
        if from_count[node] == 0:
            que.append(node)
    remained = set(from_nodes.keys())
    print(f"nodes not in cycles: {que}")
    while len(que) > 0:
        head = que.popleft()
        remained.remove(head)
        for node in to_nodes[head].keys():
            from_count[node] -= 1
            if from_count[node] == 0:
                que.append(node)
    # the remained node must equal.
    que = deque(remained)
    print(f"nodes in cycles: {que}")
    visited = set()
    while len(que) > 0:
        head = que.popleft()
        if head in visited:
            continue
        cur_que = deque([head])
        print("Found equal nodes: ")
        while len(cur_que) > 0:
            cur = cur_que.popleft()
            if cur in visited:
                continue
            print(cur)
            visited.add(cur)
            all_neighors = from_nodes[node] | to_nodes[node]
            for node, eq in all_neighors.items():
                if node not in remained:
                    continue
                if not eq:
                    return False
                cur_que.append(node)
        print("------")
    return True


def solve():
    comps = []
    comp_patern = re.compile(r"(\w+)\s*<(=?)\s*(\w+)")
    while True:
        try:
            line = input()
            matched =comp_patern.fullmatch(line)
            x, eq, y = matched.groups()
            comps.append((x, y, eq == "="))
        except EOFError:
            break
    from_nodes, to_nodes = construct(comps)
    res = check_cycle(from_nodes, to_nodes)
    print(f"result: {res}")


if __name__ == "__main__":
    solve()