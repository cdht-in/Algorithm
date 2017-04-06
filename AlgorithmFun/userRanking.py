#!/usr/bin/python
# -*- coding: utf-8 -*-

'''

created at 4/5/17 9:44 PM

题目：一个排行榜，存储用户的id（unique），要求：
1 能根据用户id查询到它排在第几名
2 能直接将一个新id插入到第k名的位置
3 能将一个id从第i名调整到第j名的位置，比如从第100名提到第3名，则原3到99的用户依次后移一名

求具体的实现方案？

'''


class UserRanking:
    def __init__(self):
        self.userToRank = {}
        self.users = []

    def getRank(self, userId):
        if userId in self.userToRank:
            return self.userToRank[userId]

        raise RuntimeError("userId: {} doesn't exist".format(userId))

    def insertUserAtK(self, userId, k):

        if k < 0 or k > len(self.users):
            raise RuntimeError("index {} is out of bound".format(k))

        for user in self.users[k:]:
            if user not in self.userToRank:
                raise RuntimeError("user: {} not in the queue".format(user))

            self.userToRank[user] += 1

        self.users.insert(k, userId)
        self.userToRank[userId] = k

    def rerankUser(self, i, j):

        if j < 0 or j > len(self.users) or i < 0 or j > len(self.users):
            raise RuntimeError("index is out of bound")

        userId = self.users[j]

        for user in self.users[j:]:
            if user not in self.userToRank:
                raise RuntimeError("user: {} not in the queue".format(user))

            self.userToRank[user] -= 1

        self.users.pop(j)

        self.insertUserAtK(userId, i)


if __name__ == "__main__":
    userRanking = UserRanking()

    userRanking.insertUserAtK("123", 0)
    userRanking.insertUserAtK("456", 0)
    userRanking.rerankUser(1, 0)

    print userRanking.getRank("456")
