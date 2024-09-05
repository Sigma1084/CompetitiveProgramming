import random
import os
from math import gcd
from tqdm import tqdm
import numpy as np


def get_array(size, min_value, max_value):
    arr = [random.randint(min_value, max_value) for _ in range(size)]
    return arr


def array_to_string(array):
    return ' '.join([str(x) for x in array])


def get_lowercase_string(size):
    return ''.join([chr(random.randint(97, 122)) for _ in range(size)])


def get_l_r(n):
    _l = random.randint(1, n)
    _r = random.randint(_l, n)
    return _l, _r


def get_graph(n, sparsity=0.2):
    mat = np.random.randint(0, int(1 / sparsity), (n, n))
    edges = list()
    for i in range(n):
        for j in range(i + 1, n):
            if mat[i][j] == 1:
                edges.append((i + 1, j + 1))
    return edges


def get_tree(n):
    edges = list()
    for i in range(2, n + 1):
        edges.append((random.randint(1, i - 1), i))
    return edges


T = 10000  # Number of test cases
N = 100000
print_test = True
compile_initial = True


def test():
    res = ""

    if print_test:
        res += f"{1}\n"

    # write into res

    # Write the test case to the input file
    with open("input.txt", "w") as f:
        f.write(res)

    # Run the solutions
    os.system("./sol < input.txt > output_sol.txt")
    os.system("./brute < input.txt > output_brute.txt")

    # Compare the outputs
    with open("output_sol.txt", "r") as f:
        output_sol = f.read()

    with open("output_brute.txt", "r") as f:
        output_brute = f.read()

    for line_sol, line_brute in zip(output_sol.split("\n"),
                                    output_brute.split("\n")):
        if line_sol != line_brute:
            print("Wrong answer")
            print("input:", res)
            print("sol:", line_sol)
            print("brute:", line_brute)
            exit(0)


# Generate test cases
if __name__ == "__main__":
    if compile_initial:
        os.system("g++ -std=c++20 brute.cpp -o brute")
        os.system("g++ -std=c++20 sol.cpp -o sol")
    for i in tqdm(range(T)):
        test()
