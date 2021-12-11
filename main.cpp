#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>


using namespace std;

typedef char Item;
class Stack {

private:
    enum {
        MAX = 20
    };
    Item items[MAX];
    int top;

public:
    Stack() : top(0) {}

    bool isEmpty() const { return top == 0; }

    bool isFull() const { return top == MAX; }

    bool push(const Item &item);

    bool pop(Item &item);
};

bool Stack::push(const Item & item) {
    if (!isFull()) {
        items[top++] = item;
        return true;
    }
    return false;
}

bool Stack::pop(Item & item) {
    if (!isEmpty()) {
        item = items[--top];
        return true;
    }
    return false;
}

int main() {
    Stack odd_digits, even_digits;
    int a;
    cout << "\n1.keyboard input\n2.reading from file\nselect:";
    cin >> a;
    switch (a) {
        case 1: {
            char ch;
            int c;
            string s;
            cout << "enter numbers: ";
            cin >> s;
            istringstream iss(s);
            while (iss >> ch) {
                c = ch - '0';
                if (c % 2) odd_digits.push(ch);
                else even_digits.push(ch);
            }
            cout << endl << "odd - stack" << endl;
            while (!odd_digits.isEmpty()) {
                odd_digits.pop(ch);
                cout << ch;
            }
            cout << endl;
            cout << endl << "even - stack" << endl;
            while (!even_digits.isEmpty()) {
                even_digits.pop(ch);
                cout << ch;
            }
            cout << endl;
            return 0;
        }
        case 2: {
            fstream file(R"(C:\Users\huawei\CLionProjects\3\text.txt)");
            char s[20];
            int c;
            file >> s;
            for (int i = 0; i < strlen(s); i++) {
                c = s[i] - '0';
                if (c % 2) odd_digits.push(s[i]);
                else even_digits.push(s[i]);
            }
                cout << endl << "odd - stack" << endl;
            for (int i = 0; i < strlen(s); i++) {
                while (!odd_digits.isEmpty()) {
                    odd_digits.pop(s[i]);
                    cout << s[i];
                }
                cout << endl;
                cout << endl << "even - stack" << endl;
                while (!even_digits.isEmpty()) {
                    even_digits.pop(s[i]);
                    cout << s[i];
                }
                cout << endl;
                return 0;
            }
        }
    }
}