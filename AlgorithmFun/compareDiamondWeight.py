#!/usr/bin/python
# -*- coding: utf-8 -*-

'''

created at 3/31/17 11:20 PM

'''

'''

题目：小明陪小红去看钻石，他们从一堆钻石中随机抽取两颗并比较她们的重量。这些钻石的重量各不相同。在他们们比较了一段时间后，它们看中了两颗钻石g1和g2。现在请你根据之前比较的信息判断这两颗钻石的哪颗更重。

给定两颗钻石的编号g1,g2，编号从1开始，同时给定关系数组vector,其中元素为一些二元组，第一个元素为一次比较中较重的钻石的编号，第二个元素为较轻的钻石的编号。最后给定之前的比较次数n。请返回这两颗钻石的关系，若g1更重返回1，g2更重返回-1，无法判断返回0。输入数据保证合法，不会有矛盾情况出现。

测试样例：
2,3,[[1,2],[2,4],[1,3],[4,3]],4
返回: 1

'''

import collections


def BFS(graph, start, end):
    history = set()

    queue = [start]
    while len(queue) > 0:
        head = queue.pop()

        if head in history:
            continue

        if head == end:
            return 1

        history.add(head)
        if head in graph:
            nodes = graph[head]
            [queue.append(node) for node in nodes]

    return 0


def compareWeight(m, n, pairs, size):
    leaves = collections.defaultdict(lambda: set())

    for pair in pairs:
        l, r = pair
        leaves[l].add(r)

    if BFS(leaves, m, n) == 1:
        return 1

    if BFS(leaves, n, m) == 1:
        return -1

    return 0


if __name__ == "__main__":
    m = 2
    n = 3
    pairs = [[1, 2], [2, 4], [1, 3], [4, 3]]
    size = len(pairs)
    print compareWeight(m, n, pairs, size)
