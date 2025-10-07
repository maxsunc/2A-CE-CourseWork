print("helloso")

def problem1():
    print("Starting problem1...")
    
    # Read matrix A
    with open('A.txt', 'r') as file_a:
        print("Successfully opened A.txt")
        A = []
        for line in file_a:
            row = list(map(float, line.split()))  # Use float for precision
            A.append(row)
    
    # Read vector B  
    with open('B.txt', 'r') as file_b:
        print("Successfully opened B.txt")
        B = []
        for line in file_b:
            value = float(line.strip())
            B.append(value)
    
    print(f"Matrix A: {A}")
    print(f"Vector B: {B}")
    
    # Create augmented matrix [A|B]
    n = len(A)
    augmented = []
    for i in range(n):
        row = A[i][:]  # Copy row from A
        row.append(B[i])  # Append B[i] to make [A|B]
        augmented.append(row)
    
    print(f"Augmented matrix [A|B]: {augmented}")
    
    # Gaussian Elimination - Forward elimination
    for i in range(n):
        # Partial pivoting
        max_val = abs(augmented[i][i])
        max_row = i
        
        for j in range(i + 1, n):
            if abs(augmented[j][i]) > max_val:
                max_val = abs(augmented[j][i])
                max_row = j
        
        # Swap rows if needed
        if max_row != i:
            augmented[i], augmented[max_row] = augmented[max_row], augmented[i]
        
        # Make all rows below this one 0 in current column
        for j in range(i + 1, n):
            if augmented[i][i] == 0:
                continue  # Skip if pivot is zero
            
            factor = augmented[j][i] / augmented[i][i]
            for k in range(i, n + 1):  # Include the B column (n+1 columns total)
                augmented[j][k] -= factor * augmented[i][k]
    
    print(f"Upper triangular matrix: {augmented}")
    
    # Back substitution
    x = [0.0] * n
    for i in range(n - 1, -1, -1):
        if augmented[i][i] == 0:
            print("No unique solution")
            return
        
        x[i] = augmented[i][n]  # Start with B value (column n)
        
        # Subtract known values
        for j in range(i + 1, n):
            x[i] -= augmented[i][j] * x[j]
        
        x[i] /= augmented[i][i]
    
    # Round to 4 significant digits
    x_rounded = [round(val, 4) for val in x]
    print(f"Solution vector (4 sig figs): {x_rounded}")
    
    return x_rounded


def problem1SedielMethod():
    # outline:
    # 1. Read A and B from files
    # 2. Create augmented matrix [A|B]
    # implement sediel iterative method 
    with open ('A.txt', 'r') as file_a:
        A = []
        for line in file_a:
            row = list(map(float, line.split()))  # Use float for precision
            A.append(row)
    with open('B.txt', 'r') as file_b:
        B = []
        for line in file_b:
            value = float(line.strip())
            B.append(value)

    # A|B matrix
    coeff_matrix = []
    for row in range(0, len(A)):
        newRow = A[row].copy()
        newRow.append(B[row])
        coeff_matrix.append(newRow)

    print(f"Coefficient Matrix: {coeff_matrix}")

    n = len(coeff_matrix[0])
    # n- 1 is the B column
    x = [0] * (n-1)  # Solution vector
    # solution is initialized to 0

    # variables
    tolerancePercent = 0.0001; # 0.01% tolerance
    maxIterations = 1000; # max iterations
    iteration = 0

    while iteration < maxIterations:
        iteration += 1
        oldX = x.copy()
        # iterate diagonally
        for i in range(0, min(n-1, len(coeff_matrix))): # dont go to last element
            # looking at element [0,0], [1,1] [2,2]..
            x[i] = coeff_matrix[i][n-1] # last element

            # subtract other elements
            for j in range(0, n-1):
                # skip i
                if j == i:
                    continue

                x[i] -= coeff_matrix[i][j] * x[j]

            x[i] /= coeff_matrix[i][i] # divide by coefficient

        finishIterating = True
        # calculate the error
        for i in range(0,len(x)):
            if x[i] == 0:
                continue    # avoid division by zero
            if abs(oldX[i] - x[i]) / x[i] > tolerancePercent:
                finishIterating = False
                break

        if finishIterating:
            break
    
    print(f"Solution vector (4 sig figs): {[round(val, 4) for val in x]}")
    print(f"Total iterations: {iteration}")






def f(x):
    # returns resistance at temperature x
    return 5.775e-7 * x**2 - 3.9083e-3 * x + 0.391

def problem2(resistance):
    print("called!")
    
    # Define the bounds
    l = 55.0    # Lower bound (temperature)
    r = 260.0   # Upper bound (temperature)
    iterations = 0
    maxIterations = 1000
    tolerance = 0.001
    result = 0

    # Check if root exists in interval
    fL = f(l) - resistance
    fR = f(r) - resistance
    
    if fL * fR > 0:
        print("Error: No root exists in the given interval!")
        return None

    while iterations < maxIterations:
        iterations += 1
        mid = (l + r) / 2
        
        fL = f(l) - resistance
        fm = f(mid) - resistance
        
        # Check if we found the root (close enough)
        if abs(fm) <= tolerance:
            result = mid
            break
            
        # Check if interval is small enough
        if abs(r - l) <= tolerance:
            result = mid
            break
        
        # Update interval based on sign of f(mid)
        if fL * fm < 0:
            # Root is in left half [l, mid]
            r = mid
        else:
            # Root is in right half [mid, r]
            l = mid
    
    print(f"Iterations: {iterations}")
    print(f"Resulting Temperature: {result:.4f}")
    return result



    print("Problem2 function called")

print("About to call problem1()")
problem2(0)
print("Finished calling problem1()")