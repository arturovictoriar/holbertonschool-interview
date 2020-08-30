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

general_stat = {"200": {"number_status": 0, "file_size": 0},
                "301": {"number_status": 0, "file_size": 0},
                "400": {"number_status": 0, "file_size": 0},
                "401": {"number_status": 0, "file_size": 0},
                "403": {"number_status": 0, "file_size": 0},
                "404": {"number_status": 0, "file_size": 0},
                "405": {"number_status": 0, "file_size": 0},
                "500": {"number_status": 0, "file_size": 0}}


def print_stats():
    """Print the request statistics"""
    msg_to_print = ''
    file_size = 0
    for status_request in sorted(general_stat.keys()):
        number_status = general_stat[status_request]["number_status"]
        if number_status:
            msg_to_print += "{}: {}\n".format(status_request, number_status)
        file_size += general_stat[status_request]["file_size"]
    print("File size: {}".format(file_size))
    print(msg_to_print, end="")


def main():
    """Read a line and save request information"""
    i = 1
    for line in sys.stdin:
        parse_line = line.split(" ")
        if parse_line[7] not in general_stat:
            continue
        general_stat[parse_line[7]]["number_status"] += 1
        general_stat[parse_line[7]]["file_size"] += int(parse_line[8])
        if i % 10 == 0:
            print_stats()
        i += 1


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
