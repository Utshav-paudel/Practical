import re

def autoEncryption(msg, key):
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    len_msg = len(msg)
    new_key = key + msg
    new_key = new_key[:len(new_key) - len(key)]
    encrypt_msg = ""

    for x in range(len_msg):
        first = alphabet.index(msg[x])
        second = alphabet.index(new_key[x])
        total = (first + second) % 26
        encrypt_msg += alphabet[total]
    return encrypt_msg

def autoDecryption(msg, key):
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    current_key = key
    decrypt_msg = ""

    for x in range(len(msg)):
        get1 = alphabet.index(msg[x])
        get2 = alphabet.index(current_key[x])
        total = (get1 - get2) % 26
        total = total if total >= 0 else total + 26
        decrypt_msg += alphabet[total]
        current_key += alphabet[total]
    return decrypt_msg

def main():
    msg = "UTSHAVPAUDEL"
    key = "N"

    if re.match("[-+]?d*.?d+", key):
        key = alphabet[int(key) % 26]

    enc = autoEncryption(msg, key)

    print("Plaintext:", msg)
    print("Encrypted:", enc)
    print("Decrypted:", autoDecryption(enc, key))

if __name__ == "__main__":
    main()
