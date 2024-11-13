#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("text.txt");
    if (!file) {
        cout << "Не удалось открыть файл.\n";
        return 1;
    }

    int letterFreq[26] = {0};
    int bigramFreq[26][26] = {0};
    char prevChar = 0, ch;

    while (file.get(ch)) {
        if (ch >= 'A' && ch <= 'Z') ch = ch + 'a' - 'A';
        if (ch >= 'a' && ch <= 'z') {
            letterFreq[ch - 'a']++;
            if (prevChar) {
                bigramFreq[prevChar - 'a'][ch - 'a']++;
            }
            prevChar = ch;
        } else {
            prevChar = 0;
        }
    }

    cout << "Частота букв:\n";
    for (int i = 0; i < 26; i++) {
        if (letterFreq[i] > 0) {
            cout << (char)('a' + i) << ": " << letterFreq[i] << endl;
        }
    }

    cout << "\nЧастота биграмм:\n";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (bigramFreq[i][j] > 0) {
                cout << (char)('a' + i) << (char)('a' + j) << ": " << bigramFreq[i][j] << endl;
            }
        }
    }

    return 0;
}