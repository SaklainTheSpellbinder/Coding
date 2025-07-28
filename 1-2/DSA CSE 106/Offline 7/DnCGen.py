from random import randint, seed

seed(123)  # For reproducibility

# Generate a rough stress test case
def generate_test_case(n, k, max_workload=10**9):
    tasks = [randint(1, max_workload) for _ in range(n)]
    return n, k, tasks

# Binary Search + Greedy check for D&C style solution
def is_possible(tasks, k, max_limit):
    count = 1
    current_sum = 0
    for task in tasks:
        if task > max_limit:
            return False
        if current_sum + task > max_limit:
            count += 1
            current_sum = task
        else:
            current_sum += task
    return count <= k

def find_min_max_workload(tasks, k):
    n = len(tasks)
    if k > n:
        return -1

    low = max(tasks)
    high = sum(tasks)
    answer = high

    while low <= high:
        mid = (low + high) // 2
        if is_possible(tasks, k, mid):
            answer = mid
            high = mid - 1
        else:
            low = mid + 1

    return answer

# Create multiple test cases
t = 5000
input_text = f"{t}\n"
output_text = ""

for _ in range(t):
    n = randint(10, 100)  # smaller size for rough stress
    k = randint(1, n)
    n, k, tasks = generate_test_case(n, k)
    input_text += f"{n} {k}\n"
    input_text += ' '.join(map(str, tasks)) + "\n"
    result = find_min_max_workload(tasks, k)
    output_text += f"{result}\n"

# Write to files
with open("input1.txt", "w") as f_in:
    f_in.write(input_text)

with open("output1.txt", "w") as f_out:
    f_out.write(output_text)

"input1.txt", "output1.txt"
