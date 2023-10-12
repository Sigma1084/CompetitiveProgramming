import random
import os


def get_array(size, min_value, max_value):
    return [random.randint(min_value, max_value) for _ in range(size)]


def array_to_string(array):
    return ' '.join([str(x) for x in array])


def get_lowercase_string(size):
    return ''.join([chr(random.randint(97, 122)) for _ in range(size)])


def get_l_r(n):
    _l = random.randint(1, n)
    _r = random.randint(_l, n)
    return _l, _r


def generate_cases(num_tests, min_array_size, max_array_size, min_value,
                   max_value):
    arrays = [
        get_array(
            size=random.randint(min_array_size, max_array_size),
            min_value=min_value, max_value=max_value
        )
        for _ in range(num_tests)
    ]
    return f"{num_tests}\n" + "\n".join([
        f"{len(array)}  {array_to_string(array)}"
        for array in arrays
    ])


T = 200  # Number of test cases
N = 100  # Max number size
print_test = True


def test():
    res = ""
    if print_test:
        res += "1\n"

    n = random.randint(1, N)
    nq = random.randint(1, N)
    res += f"{n} {nq}\n"
    res += get_lowercase_string(n) + "\n"

    for _ in range(nq):
        t = random.randint(1, 2)
        l, r = get_l_r(n)
        res += f"{t} {l} {r}"
        if t == 1:
            res += f" {random.randint(1, 26)}"
        res += "\n"

    with open("input.txt", "w") as f:
        f.write(res)

    # Run the solutions
    os.system("./temp")
    os.system("./brute")

    # Compare the outputs
    with open("output_temp.txt", "r") as f:
        output_temp = f.read()

    with open("output_brute.txt", "r") as f:
        output_brute = f.read()

    for line_temp, line_brute in zip(output_temp.split("\n"),
                                     output_brute.split("\n")):
        if line_temp != line_brute:
            print("Wrong answer")
            print("input:", res)
            print("temp:", line_temp)
            print("brute:", line_brute)
            exit(0)


# Generate test cases
if __name__ == "__main__":
    for _ in range(T):
        test()
