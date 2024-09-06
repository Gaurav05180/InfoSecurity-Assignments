#include <iostream>
#include <string>

using namespace std;

// Function to decrypt the ciphertext with a given key
string decryptText(const string &ciphertext, int key) {
    string decryptedText;

    for (char character : ciphertext) {
        if (isupper(character)) {
            // Decrypt uppercase letters
            decryptedText += char((character - key - 'A' + 26) % 26 + 'A');
        } else if (islower(character)) {
            // Decrypt lowercase letters
            decryptedText += char((character - key - 'a' + 26) % 26 + 'a');
        } else {
            // Non-alphabetic characters remain unchanged
            decryptedText += character;
        }
    }

    return decryptedText;
}

int main() {
    string ciphertext;

    // Input the ciphertext
    cout << "Enter the ciphertext: ";
    getline(cin, ciphertext);

    cout << "\nAttempting to decrypt using all possible keys:\n";

    // Try all possible keys from 1 to 26
    for (int key = 1; key <= 26; ++key) {
        string decryptedText = decryptText(ciphertext, key);
        cout << "Key " << key << ": " << decryptedText << endl;
    }

    return 0;
}
