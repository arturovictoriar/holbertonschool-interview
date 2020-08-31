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

general_stat = {"200": 0,
                "301": 0,
                "400": 0,
                "401": 0,
                "403": 0,
                "404": 0,
                "405": 0,
                "500": 0}
total_size = {"total": 0}


def print_stats():
    """Print the request statistics"""
    print("File size: {}".format(total_size["total"]))
    for status_req in sorted(general_stat.keys()):
        if general_stat[status_req]:
            print("{}: {}".format(status_req, general_stat[status_req]))


def assign_values(line):
    """save the values parsed"""
    try:
        line = line[:-1]
        parse_line = line.split(" ")
        total_size["total"] += int(parse_line[8])
        if parse_line[7] in general_stat:
            general_stat[parse_line[7]] += 1
    except:
        pass


if __name__ == "__main__":
    try:
        i = 1
        for line in sys.stdin:
            assign_values(line)
            if i % 10 == 0:
                print_stats()
            i += 1
        print_stats()
    except KeyboardInterrupt:
        print_stats()
        raise
