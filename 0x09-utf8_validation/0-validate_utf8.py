#!/usr/bin/python3
"""
    Check if a set of integers are valid utf-8 format
    data = [1,2,3 ..., n]
    return True if all integers in list are valid utf-8 format
    Otherwise False
"""


def validUTF8(data):
    """Check if a set of integers are valid utf-8 format"""
    num_bytes = 0
    for char_d in data:
        byte = char_d & 0xff
        if num_bytes and byte & 0b10000000 and byte & 0b01000000:
            return False
        num_bytes -= 1
        num_bytes = max(num_bytes, 0)
        while (7 - num_bytes) and byte & (1 << (7 - num_bytes)):
            num_bytes += 1
        if num_bytes == 1 or num_bytes > 4:
            return False

    if num_bytes:
        return False
    return True
