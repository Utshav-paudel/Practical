from math import exp 

def ANDGateCalculation(x1, x2):
    stringLiteral = f"{x1} AND {x2} = "
    weights = [-2, 1, 1]
    Z = weights[0] + x1 * weights[1] + x2 * weights[2]
    sigmoid_val = 1/(1 + exp(-Z))
    if sigmoid_val >= 0.5:
        print(stringLiteral + "1")
    else:
        print(stringLiteral + "0")

def ORGateCalculation(x1, x2):
    stringLiteral = f"{x1} OR {x2} = "
    weights = [-1, 2, 2]
    Z = weights[0] + x1 * weights[1] + x2 * weights[2]
    sigmoid_val = 1/(1 + exp(-Z))
    if sigmoid_val >= 0.5:
        print(stringLiteral + "1")
    else:
        print(stringLiteral + "0")

for x1 in range(2):
    for x2 in range(2):
        ORGateCalculation(x1, x2)
        ANDGateCalculation(x1, x2)
print("\n\tLab by Utshav Paudel")