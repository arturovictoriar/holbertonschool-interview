#!/usr/bin/python3

"""
    Given an n x n 2D matrix, rotate it 90 degrees clockwise.
"""


def rotate_2d_matrix(matrix):
    """
    rotate_2d_matrix - Rotate a matrix 90 degrees clockwise
    @matrix: list of list
    Return: Nothing
    """
    r = len(matrix)
    c = len(matrix[0])
    r_matrix = [[0 for i in range(r)] for j in range(c)]
    c_matrix = matrix[:]
    i = 0
    while i < r:
        j = 0
        while j < c:
            r_matrix[j][len(c_matrix) - 1 - i] = c_matrix[i][j]
            j += 1
        matrix.pop()
        i += 1

    i = 0
    while i < c:
        matrix.append(r_matrix[i])
        i += 1
