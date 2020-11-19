#!/usr/bin/python3
"""
    Given a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains.
"""


def retained_water(r, d):
    """
    retained_watter - calculate how much water will be retained
    @r: list of retainers
    @d: 0 from left to righ. 1 from right to left
    """
    minV = -1
    num_values_between = 0
    sum_values_between = 0
    ret_water = 0
    i = 0
    while i < len(r):
        if r[i] > 0 and minV < 0:
            minV = r[i]
        elif minV > 0 and r[i] < minV:
            num_values_between += 1
            sum_values_between += r[i]
        elif minV > 0 and ((not d and r[i] >= minV) or (d and r[i] > minV)):
            if num_values_between > 0:
                ret_water += (num_values_between * minV)
                ret_water -= sum_values_between
            num_values_between = 0
            sum_values_between = 0
            minV = r[i]
        i += 1
    return ret_water


def rain(walls):
    """
    rain - calculate how much water will be retained after it rains
    @walls: list of retainers
    """
    if not walls:
        return 0
    return retained_water(walls, 0) + retained_water(walls[::-1], 1)
