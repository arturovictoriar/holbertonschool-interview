#!/usr/bin/python3
"""Print statistics from html request"""

import signal
import sys

general_stat = {}


def print_stats():
    """Print the request statistics"""
    msg_to_print = ''
    file_size = 0
    for status_request in sorted(general_stat.keys()):
        number_status = general_stat[status_request]["number_status"]
        msg_to_print += "{}: {}".format(status_request, number_status)
        msg_to_print += '\n'
        file_size += general_stat[status_request]["file_size"]
    print("File size: {}\n{}".format(file_size, msg_to_print), end="")


def signal_handler(signal, frame):
    """Print the stats when ctrl-c interruption will be activated"""
    print_stats()


signal.signal(signal.SIGINT, signal_handler)
i = 1
for line in sys.stdin:
    try:
        parse_line = line.split(" ")
        if parse_line[7] not in general_stat:
            general_stat[parse_line[7]] = {"number_status": 0,
                                           "file_size": 0}
        general_stat[parse_line[7]]["number_status"] += 1
        general_stat[parse_line[7]]["file_size"] += int(parse_line[8])
        if i % 10 == 0:
            print_stats()
            general_stat = {}
        i += 1
    except:
        pass
