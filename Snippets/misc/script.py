import random
import os

def get_array(size, min_value, max_value):
    return [random.randint(min_value, max_value) for _ in range(size)]

def array_to_string(array):
    return ' '.join([str(x) for x in array])

def generate_cases(num_tests, min_array_size, max_array_size, min_value, max_value):
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

N = 4
T = 10

# Print string into a file
with open("input.txt", "w") as f:
    input_string = generate_cases(T, 1, N, 1, N)
    f.write(input_string)

# Compile the program
_compile = False
if _compile:
    command = "g++ -std=c++20 -O2"
    file_name = "main"
    os.system(f"{command} ./{file_name}.cpp -o a.out")
    os.system(f"{command} ./brute.cpp -o b.out")

# Run the program
import os
os.system("./a.out < input.txt > output.txt")
os.system("./b.out < input.txt > output_brute.txt")

# Compare the outputs
with open("output.txt", "r") as f:
    output = f.read()

with open("output_brute.txt", "r") as f:
    output_brute = f.read()

# Check which line is wrong
for i, (line, line_brute) in enumerate(list(zip(output.split('\n'), output_brute.split('\n')))):
    if line != line_brute:
        print("Error found")
        print("Line:", i + 1)
        print("Case: " + input_string[i + 1])
        print("Expected:", line_brute)
        print("Got:", line)
        break

