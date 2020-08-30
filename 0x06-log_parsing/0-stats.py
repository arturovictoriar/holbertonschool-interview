#!/usr/bin/python3
import sys


def print_stats(number_status, total_size):
    """
    Print the stats of the request
    """
    print("File size: {}".format(total_size))
    for status_req, num_status in number_status.items():
        if num_status != 0:
            print("{}: {}".format(status_req, num_status))
        number_status[status_req] = 0

number_status = {
    "200": 0, "301": 0, "400": 0, "401": 0,
    "403": 0, "404": 0, "405": 0, "500": 0
}
i = 1
total_size = 0

try:
    for line in sys.stdin:
        parse_line = line.split(" ")
        total_size += int(parse_line[8])
        number_status[parse_line[7]] += 1
        if i % 10 == 0:
            print_stats(number_status, total_size)
            total_size = 0
        i += 1
except KeyboardInterrupt:
    print_stats(number_status, total_size)
    raise
