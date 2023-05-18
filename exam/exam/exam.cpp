#include"Param.h"

string pickRandomWord(int topic) {
    string file;
    switch (topic) {
    case 1:
        file = "Random.txt";
        break;
    case 2:
        file = "Animals.txt";
        break;
    case 3:
        file = "Professions.txt";
        break;
    case 4:
        file = "Countries.txt";
        break;
    default:
        return "";
    }

    ifstream ran(file);
    string str;
    if (ran.is_open()) {
        int i = 0;
        getline(ran, str);
        int r = random(1, 50);
        while (getline(ran, str)) {
            i++;
            if (i == r) {
                return str;
            }
        }
        ran.close();
    }
    else {
        cout << "File opening error" << endl;
        return "";
    }
    return "";
}

void human(int mistakes) {
    switch (mistakes) {
    case 0:
        cout << "  _____ " << endl;
        cout << " |     |" << endl;
        cout << " |      " << endl;
        cout << " |      " << endl;
        cout << " |      " << endl;
        cout << " |      " << endl;
        cout << " |      " << endl;
        break;
    case 1:
        cout << "  _____ " << endl;
        cout << " |     |" << endl;
        cout << " |     O" << endl;
        cout << " |      " << endl;
        cout << " |      " << endl;
        cout << " |      " << endl;
        cout << " |      " << endl;
        break;
    case 2:
        cout << "  _____ " << endl;
        cout << " |     |" << endl;
        cout << " |     O" << endl;
        cout << " |     |" << endl;
        cout << " |     |" << endl;
        cout << " |      " << endl;
        cout << " |      " << endl;
        break;
    case 3:
        cout << "  _____ " << endl;
        cout << " |     |" << endl;
        cout << " |     O" << endl;
        cout << " |    /|" << endl;
        cout << " |     |" << endl;
        cout << " |      " << endl;
        cout << " |      " << endl;
        break;
    case 4:
        cout << "  _____ " << endl;
        cout << " |     |" << endl;
        cout << " |     O" << endl;
        cout << " |    /|\\" << endl;
        cout << " |     |" << endl;
        cout << " |      " << endl;
        cout << " |      " << endl;
        break;
    case 5:
        cout << "  _____ " << endl;
        cout << " |     |" << endl;
        cout << " |     O" << endl;
        cout << " |    /|\\" << endl;
        cout << " |     |" << endl;
        cout << " |    /  " << endl;
        cout << " |      " << endl;
        break;
    case 6:
        cout << "  _____ " << endl;
        cout << " |     |" << endl;
        cout << " |     O" << endl;
        cout << " |    /|\\" << endl;
        cout << " |     |" << endl;
        cout << " |    / \\" << endl;
        cout << " |      " << endl;
        break;
    }
}

void win(const string & str, const string & guessedLetters) {
    bool flag = true;
   for (int i = 0; i < str.length(); i++) {
        if (toupper(str[i]) != toupper(guessedLetters[i])) {
            flag = false;
            break;
        }
    }
    if (flag) {
        system("cls");
        cout << "Congratulations! You guessed the word: " << str << endl;
    }
    else {
        cout << "You've lost! The word was: " << str << endl;
    }
}


int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int topic;
    cout << "\tThemes" << endl;
    cout << "1) Random" << endl;
    cout << "2) Animals" << endl;
    cout << "3) Professions" << endl;
    cout << "4) Countries" << endl;
    cin >> topic;
    if (topic < 1 || topic > 4) {
        cout << "There is no such topic!" << endl;
        return 0;
    }
    string str = pickRandomWord(topic);
    string guessedLetters(str.length(), '_');
    char letter;
    int mist = 0;
    while (mist < 6 && guessedLetters.find('_') != string::npos) {
        cout << "Number of letters: " << str.length() << endl;
        cout << "Enter a letter: ";
        cin >> letter;
        system("cls");
        bool flag = false;

        for (int i = 0; i < str.length(); i++) {
            if (toupper(str[i]) == toupper(letter)) {
                flag = true;
                guessedLetters[i] = letter;
            }
        }
        if (!flag) {
            mist++;
            cout << "Wrong guess!" << endl;
            human(mist);
        }
        cout << "Guessed letters: " << guessedLetters << endl;
        cout << endl;
    }
    win(str, guessedLetters);
}