#!/usr/bin/python3
"""
    Check if a set of integers are valid utf-8 format
    data = [1,2,3 ..., n]
    return True if all integers in list are valid utf-8 format
    Otherwise False
"""


def validUTF8(data):
    """Check if a set of integers are valid utf-8 format"""
    for char_d in data:
        if (char_d & 0xff) > 127:
            return False
    return True
