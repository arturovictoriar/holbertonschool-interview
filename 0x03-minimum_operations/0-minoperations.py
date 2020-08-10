#!/usr/bin/python3
"""
    Get the minumun operation iterative
    it no take a lot time
"""


def minOperations(n):
    """Get the minum operation iterative"""
    if n <= 1:
        return 0
    number = n
    div = 2
    min_oper = 0
    while number > 1:
        if number % div == 0:
            number /= div
            min_oper += div
        else:
            div += 1
    return min_oper
