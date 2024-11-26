def max_profit(n, a, b):
    max_profit = 0
    max_k = min(n, b)
    
    for k in range(max_k + 1):
        profit_promo = k * b - k * (k - 1) // 2
        profit_regular = (n - k) * a
        total_profit = profit_promo + profit_regular
        max_profit = max(max_profit, total_profit)
    
    return max_profit

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    index = 1
    results = []
    
    for _ in range(t):
        n = int(data[index])
        a = int(data[index + 1])
        b = int(data[index + 2])
        index += 3
        results.append(max_profit(n, a, b))
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
