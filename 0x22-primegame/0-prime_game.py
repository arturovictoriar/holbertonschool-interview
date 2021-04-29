#!/usr/bin/python3
""" Module for Prime Game """


def prime_colander(nums):
    """Discart NO prime number"""
    n = max(nums)
    sieve = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not sieve[i]:
            continue
        for j in range(i*i, n + 1, i):
            sieve[j] = False

    sieve[0] = sieve[1] = False
    return sieve


def primer_multiple_colander(sieve):
    """Discart all multiples of prime numbers"""
    c = 0
    for i in range(len(sieve)):
        if sieve[i]:
            c += 1
        sieve[i] = c

    return sieve


def isWinner(x, nums):
    """Determine if Maria or Ben win the prime game"""
    if not nums or x < 1:
        return None
    sieve = prime_colander(nums)
    sieve = primer_multiple_colander(sieve)

    player1 = 0
    for n in nums:
        player1 += sieve[n] % 2 == 1
    if player1 * 2 == len(nums):
        return None
    if player1 * 2 > len(nums):
        return "Maria"
    return "Ben"
