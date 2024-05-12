#@ Program to Implement monoalphabetic cipher in python 
# Python program for decoding the string
# using classical cipher
import string

# stores all upper case alphabets
all_alphabets = list(string.ascii_uppercase)

# Function generates the encoded text
def encoder(key):

	encoded = ""
	
	# This array represents the
	# 26 letters of alphabets
	arr = [False]*26

	# This loop inserts the keyword
	# at the start of the encoded string
	for i in range(len(key)):

		if key[i] >= 'A' and key[i] <= 'Z':
		
			# To check whether the character is inserted
			# earlier in the encoded string or not
			if arr[ord(key[i]) - 65] == False:
				encoded += key[i]
				arr[ord(key[i]) - 65] = True
		elif key[i] >= 'a' and key[i] <= 'z':
			if arr[ord(key[i]) - 97] == False:
				encoded += chr(ord(key[i]) - 32)
				arr[ord(key[i]) - 97] = True

	for i in range(26):
		if arr[i] == False:
			arr[i] = True
			encoded += (chr(i + 65))

	return encoded


# This function will decode the message
def decipheredIt(msg, encoded):

	# Original Set of letters
	plaintext = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	decipher = ""
	
	# Hold the position of every character (A-Z) from encoded string
	enc = {}

	for i in range(len(encoded)):
		enc[encoded[i]] = i

	# This loop deciphered the message.
	# Spaces, special characters and numbers remain same.
	for i in range(len(msg)):
		if msg[i] >= 'a' and msg[i] <= 'z':
			pos = enc.get((chr)(msg[i]-32))
			decipher += plaintext[pos]

		elif msg[i] >= 'A' and msg[i] <= 'Z':
			pos = enc.get(msg[i])
			decipher += plaintext[pos]

		else:
			decipher += msg[i]

	return decipher

# Hold the Keyword
key = "Howareyoudoing"
print("Keyword : " + key)

# Function call to generate encoded text
decoded = encoder(list(key))

# Message that need to encode
message = "EUUDN TIL EUUDN"
print("Message before Deciphering : " + message)

# Function call to print ciphered text
print("Ciphered Text : " + decipheredIt(message, decoded))

print("\nLab by Utshav Paudel")

# This code is contributed by arorapranay.
