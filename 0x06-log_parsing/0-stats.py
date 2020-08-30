#!/usr/bin/python3
"""
    According this input request:
    <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
    <status code> <file size>
    Print the request statistics in the next way:
    File size: <total size>
    <status code>: <number>
    .
    .
    .
    <status code>: <number>
"""

import sys

general_stat = {}
size_file = 0


def print_stats():
    """Print the request statistics"""
    print("File size: {}".format(size_file))
    for status_request in sorted(general_stat.keys()):
        number_status = general_stat[status_request]["number_status"]
        print("{}: {}".format(status_request, number_status))

try:
    i = 1
    for line in sys.stdin:
        parse_line = line.split(' ')
        if parse_line[7] not in general_stat:
            general_stat[parse_line[7]] = {"number_status": 0, "file_size": 0}
        general_stat[parse_line[7]]["number_status"] += 1
        general_stat[parse_line[7]]["file_size"] += int(parse_line[8])
        size_file += int(parse_line[8])
        if i % 10 == 0:
            print_stats()
        i += 1
except KeyboardInterrupt:
    print_stats()
    raise
