#!/usr/bin/python3


def min_c(m, n, i, c):
    """Get the minum operation recursive"""
    if m > n or i > n:
        return -1
    elif m == n:
        return i
    min1 = min_c(m + c, n, i + 1, c)
    min2 = min_c(m, n, i + 1, m)

    if min1 == -1 and min2 != -1:
        return min2
    if min2 == -1 and min1 != -1:
        return min1
    if min1 == -1 and min2 == -1:
        return -1
    if min1 > min2:
        return min2
    if min2 > min1:
        return min1
    return min1


def minOperations(n):
    """Get the minum operation recursive"""
    if n <= 1:
        return 0
    i = 0
    m = 1
    c = m
    i += 1
    m = m + c
    i += 1
    min = min_c(m, n, i, c)
    if min == -1:
        return 0
    return min
