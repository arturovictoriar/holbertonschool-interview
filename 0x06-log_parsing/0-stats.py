#!/usr/bin/python3
"""Print statistics from html request"""

import sys

general_stat = {"200": 0, "301": 0, "400": 0, "401": 0,
                "403": 0, "404": 0, "405": 0, "500": 0}
size_file = 0


def print_stats():
    """Print the request statistics"""
    print("File size: {}".format(size_file))
    for status_req in sorted(general_stat.keys()):
        if general_stat[status_req]:
            print("{}: {}".format(status_req, general_stat[status_req]))
        general_stat[status_req] = 0

i = 1
try:
    for line in sys.stdin:
        parse_line = line.split(" ")
        general_stat[parse_line[7]] += 1
        size_file += int(parse_line[8])
        if i % 10 == 0:
            print_stats()
            size_file = 0
        i += 1
except KeyboardInterrupt:
    print_stats()
    raise
