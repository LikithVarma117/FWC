def nand_gate(A, B):
    return int(not (A and B))

while True:
    A = int(input("Enter A (0 or 1): "))
    B = int(input("Enter B (0 or 1): "))

    Y = nand_gate(A, B)

    if Y == 1:
        print("7-Segment shows: 1")
    else:
        print("7-Segment shows: 0")
