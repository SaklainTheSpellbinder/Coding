import random

def generate_dna_sequence(length):
    return ''.join(random.choice('ACGT') for _ in range(length))

def global_alignment(s1, s2, match, mismatch, gap):
    n, m = len(s1), len(s2)
    dp = [[0] * (m+1) for _ in range(n+1)]

    for i in range(n+1):
        dp[i][0] = i * gap
    for j in range(m+1):
        dp[0][j] = j * gap

    for i in range(1, n+1):
        for j in range(1, m+1):
            diag = dp[i-1][j-1] + (match if s1[i-1] == s2[j-1] else mismatch)
            up = dp[i-1][j] + gap
            left = dp[i][j-1] + gap
            dp[i][j] = max(diag, up, left)

    x, y = "", ""
    i, j = n, m
    while i > 0 and j > 0:
        if s1[i-1] == s2[j-1] and dp[i][j] == dp[i-1][j-1] + match:
            x += s1[i-1]
            y += s2[j-1]
            i -= 1
            j -= 1
        elif s1[i-1] != s2[j-1] and dp[i][j] == dp[i-1][j-1] + mismatch:
            x += s1[i-1]
            y += s2[j-1]
            i -= 1
            j -= 1
        elif dp[i][j] == dp[i-1][j] + gap:
            x += s1[i-1]
            y += '-'
            i -= 1
        else:
            x += '-'
            y += s2[j-1]
            j -= 1
    while i > 0:
        x += s1[i-1]
        y += '-'
        i -= 1
    while j > 0:
        x += '-'
        y += s2[j-1]
        j -= 1

    return x[::-1], y[::-1], dp[n][m]

def local_alignment(s1, s2, match, mismatch, gap):
    n, m = len(s1), len(s2)
    dp = [[0] * (m+1) for _ in range(n+1)]

    max_score = 0
    end_i = end_j = 0

    for i in range(1, n+1):
        for j in range(1, m+1):
            diag = dp[i-1][j-1] + (match if s1[i-1] == s2[j-1] else mismatch)
            up = dp[i-1][j] + gap
            left = dp[i][j-1] + gap
            dp[i][j] = max(0, diag, up, left)
            if dp[i][j] > max_score:
                max_score = dp[i][j]
                end_i, end_j = i, j

    x, y = "", ""
    i, j = end_i, end_j
    while i > 0 and j > 0 and dp[i][j] > 0:
        if s1[i-1] == s2[j-1] and dp[i][j] == dp[i-1][j-1] + match:
            x += s1[i-1]
            y += s2[j-1]
            i -= 1
            j -= 1
        elif s1[i-1] != s2[j-1] and dp[i][j] == dp[i-1][j-1] + mismatch:
            x += s1[i-1]
            y += s2[j-1]
            i -= 1
            j -= 1
        elif dp[i][j] == dp[i-1][j] + gap:
            x += s1[i-1]
            y += '-'
            i -= 1
        else:
            x += '-'
            y += s2[j-1]
            j -= 1

    return x[::-1], y[::-1], max_score

with open("testcases.txt", "w") as f:
    for case_num in range(1, 101):
        s1 = generate_dna_sequence(random.randint(6, 12))
        s2 = generate_dna_sequence(random.randint(6, 12))
        match = random.randint(1, 3)
        mismatch = random.randint(-5, -1)
        gap = random.randint(-5, -1)

        g1, g2, gscore = global_alignment(s1, s2, match, mismatch, gap)
        l1, l2, lscore = local_alignment(s1, s2, match, mismatch, gap)

        f.write(f"=== Test Case {case_num} ===\n")
        f.write("Input:\n")
        f.write(f"{s1}\n{s2}\n{match}\n{mismatch}\n{gap}\n")

        f.write("Global Alignment:\n")
        f.write(f"{g1}\n{g2}\n")
        f.write(f"Maximum Score: {gscore}\n\n")

        f.write("Local Alignment:\n")
        f.write(f"{l1}\n{l2}\n")
        f.write(f"Maximum Score: {lscore}\n\n")
