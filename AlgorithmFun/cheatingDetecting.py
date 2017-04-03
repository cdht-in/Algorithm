#!/usr/bin/python
# -*- coding: utf-8 -*-

'''

created at 4/1/17 10:55 AM

来自：搜狗2016研发工程师笔试题

现在我们需要查出一些作弊的问答社区中的ID，作弊有两种：1.A回答了B的问题，同时B回答了A的问题。那么A和B都是作弊。2.作弊ID用户A和作弊ID用户B同时回答了C的问题，那么C也是作弊。已知每个用户的ID是一串数字，一个问题可能有多个人回答。

输入描述:
每组数据第一行为总问题数N(N小于等于200000)，第二行开始每行一个问题，第一个数字为提问人ID，第二个数字为回答人数，后面则为所有回答人的ID。(ID均为0-1000000的整数)

输出描述:
第一行为作弊ID数量，第二行开始为从小到大的每行一个作弊ID。

输入例子:
3
1 1 2
2 1 1
3 2 1 2

输出例子:
3
1 2 3

'''

import collections


def cheatingDection(mat):
    n = mat[0][0]

    if n <= 2:
        return 0

    leaves = collections.defaultdict(lambda: set())
    cheaters = set()
    for row in mat[1:]:
        if len(row) <= 2 or row[1] == 0:
            continue

        questioner = row[0]
        for answerer in row[2:]:
            leaves[answerer].add(questioner)

    for answerer, questioners in leaves.iteritems():

        for questioner in questioners:
            # cycle, both cheaters
            if questioner not in leaves:
                continue

            if answerer in leaves[questioner]:
                cheaters.add(answerer)
                cheaters.add(questioner)

                joineds = leaves[answerer] & leaves[questioner]
                for joined in joineds:
                    cheaters.add(joined)

    cheaterList = sorted(list(cheaters))
    print cheaterList


if __name__ == "__main__":
    mat = [[3], [1, 1, 2], [2, 1, 1], [3, 2, 1, 2]]
    cheatingDection(mat)
