#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Function to encrypt the text using the Additive Cipher
string encryptText(const string& inputText, int shiftAmount, int alphabetBound) {
    string encryptedText;
    for (char ch : inputText) {
        if (isupper(ch)) {
            // Encrypt uppercase letters
            encryptedText += char((ch - 'A' + shiftAmount) % alphabetBound + 'A');
        } else if (islower(ch)) {
            // Encrypt lowercase letters
            encryptedText += char((ch - 'a' + shiftAmount) % alphabetBound + 'a');
        } else {
            // Add non-alphabetic characters without modification
            encryptedText += ch;
        }
    }
    return encryptedText;
}

// Function to decrypt the text using the Additive Cipher
string decryptText(const string& inputText, int shiftAmount, int alphabetBound) {
    string decryptedText;
    for (char ch : inputText) {
        if (isupper(ch)) {
            // Decrypt uppercase letters
            decryptedText += char((ch - 'A' - shiftAmount + alphabetBound) % alphabetBound + 'A');
        } else if (islower(ch)) {
            // Decrypt lowercase letters
            decryptedText += char((ch - 'a' - shiftAmount + alphabetBound) % alphabetBound + 'a');
        } else {
            // Add non-alphabetic characters without modification
            decryptedText += ch;
        }
    }
    return decryptedText;
}

int main() {
    string inputText;
    int shiftAmount;
    int choice;
    int alphabetBound;

    cout << "Enter the character bound (number of letters in alphabet): ";
    cin >> alphabetBound;

    char maxLowerCaseChar = 'a' + (alphabetBound - 1);
    char maxUpperCaseChar = 'A' + (alphabetBound - 1);

    cout << "Enter the text containing letters from 'a' to '" << maxLowerCaseChar 
         << "' and 'A' to '" << maxUpperCaseChar << "': ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline character from the input buffer
    getline(cin, inputText);

    cout << "Enter the shift amount (key): ";
    cin >> shiftAmount;

    cout << "1. Encrypt\n2. Decrypt\nChoose an option (1/2): ";
    cin >> choice;

    if (choice == 1) {
        string encryptedText = encryptText(inputText, shiftAmount, alphabetBound);
        cout << "Encrypted Text: " << encryptedText << endl;
    } else if (choice == 2) {
        string decryptedText = decryptText(inputText, shiftAmount, alphabetBound);
        cout << "Decrypted Text: " << decryptedText << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
