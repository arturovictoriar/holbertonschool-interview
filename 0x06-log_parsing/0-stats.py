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

import signal

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


def main():
    """Read a line and save request information"""
    for i in range(10000):
        line = input()
        parse_line = line.split()
        if parse_line[7] not in general_stat:
            general_stat[parse_line[7]] = {"number_status": 0, "file_size": 0}
        general_stat[parse_line[7]]["number_status"] += 1
        general_stat[parse_line[7]]["file_size"] += int(parse_line[7], base=10)
        if (i + 1) % 10 == 0:
            print_stats()

if __name__ == "__main__":
    signal.signal(signal.SIGINT, signal_handler)
    main()
