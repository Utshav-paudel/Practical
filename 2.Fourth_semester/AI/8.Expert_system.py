print("====================================")
print(" COVID CHECKER ")
print("====================================")
print("Answer the following questions:\n")

cough = (input("Do you have a Cough? ")).lower() == "y"
shortnessOfBreath = (input("Do you have shorness of breath? ")).lower() == "y"
fever = (input("Do you have a fever? ")).lower() == "y"
lossOfTaste = (input("Have you lost your taste or smell? ")).lower() == "y"

symtomFactorWeight = {
    "fever": [3, -2],
    "cough": [2, -1],
    "breath": [3, -2],
    "taste": [2, 0],
}

valuePredictor = 0

if fever:
    valuePredictor += symtomFactorWeight["fever"][0]
else:
    valuePredictor += symtomFactorWeight["fever"][1]

if cough:
    valuePredictor += symtomFactorWeight["cough"][0]
else:
    valuePredictor += symtomFactorWeight["cough"][1]

if shortnessOfBreath:
    valuePredictor += symtomFactorWeight["breath"][0]
else:
    valuePredictor += symtomFactorWeight["breath"][1]

if lossOfTaste:
    valuePredictor += symtomFactorWeight["taste"][0]
else:
    valuePredictor += symtomFactorWeight["taste"][1]

if valuePredictor > 0:
    print("You show the symptoms of Covid 19. Go for a checkup as soon as possible")
else:
    print("You do not show the symptoms of Covid 19")
print("\n\tLab by Utshav Paudel")