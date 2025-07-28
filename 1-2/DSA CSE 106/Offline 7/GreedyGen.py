from random import randint, seed

seed(99)  # Seed for reproducibility

def generate_edge_test_case(n, b, m):
    bench_size = n // b
    seats = [0] * n

    # Try to densely fill seats with type 1 and 2 blockers
    for bench in range(b):
        start = bench * bench_size
        end = start + bench_size
        i = start
        while i < end:
            if i + 1 < end:
                if randint(0, 2) == 0:
                    seats[i] = 2  # Type 2 blocks both sides
                    i += 2
                    continue
                elif randint(0, 2) == 0:
                    seats[i] = 1  # Type 1 blocks right side
                    i += 2
                    continue
            i += 1

    return (n, b, seats, m)

def can_seat_all(n, b, seats, m):
    bench_size = n // b
    blocked = [False] * n

    for bench in range(b):
        start = bench * bench_size
        end = start + bench_size
        for i in range(start, end):
            if seats[i] == 1 and i + 1 < end:
                blocked[i + 1] = True
            elif seats[i] == 2:
                if i - 1 >= start:
                    blocked[i - 1] = True
                if i + 1 < end:
                    blocked[i + 1] = True

    count = 0
    for i in range(n):
        if seats[i] == 0 and not blocked[i]:
            count += 1
    return count >= m

# Parameters
t = 1000
edge_input_text = f"{t}\n"
edge_output_text = ""

# Generate and evaluate test cases
for _ in range(t):
    n = randint(50, 200)
    b = randint(1, min(n, 20))
    n = (n // b) * b  # ensure n divisible by b
    m = randint(1, n)
    n, b, seats, m = generate_edge_test_case(n, b, m)
    edge_input_text += f"{n} {b}\n"
    edge_input_text += ' '.join(map(str, seats)) + '\n'
    edge_input_text += f"{m}\n"
    edge_output_text += f"{str(can_seat_all(n, b, seats, m)).lower()}\n"

# Write to files
with open("input.txt", "w") as f_in:
    f_in.write(edge_input_text)

with open("output.txt", "w") as f_out:
    f_out.write(edge_output_text)

"input.txt", "output.txt"
