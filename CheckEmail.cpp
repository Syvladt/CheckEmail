// CheckEmail.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

bool checkRightPart(string inStr) {
    bool correct = false;
    if (inStr[0] != '.' && inStr[inStr.length() - 1] != '.') {
        for (int i = 0; i < inStr.length(); i++) {
            if (inStr[i] == '.' || inStr[i] == '-' || (inStr[i] >= 'A' && inStr[i] <= 'Z') || (inStr[i] >= 'a' && inStr[i] <= 'z') || (inStr[i] >= '0' && inStr[i] <= '9')) {
                if (inStr[i] == '.' && inStr[i - 1] == '.') {
                    return false;
                }
                else correct = true;
            }
            else return false;
        }
        if (correct) return true;
        else return false;
    }
    else return false;
}

int main()
{
    string inStr, leftPart, rightPart;
    int at = 0, atPosition;
    cout << "\nE-mail verification program\n\n";
    cout << "Input e-mail: ";
    getline(cin, inStr);
    for (int i = 0; i < inStr.length(); i++) {
        if (inStr[i] == '@') {
            at++;
            atPosition = i;
        }
    }
    leftPart = inStr.substr(0, atPosition);
    rightPart = inStr.substr(atPosition + 1);

    if (at > 1 || at == 0) cout << "No\n";
    else if (atPosition < 1 || atPosition > 64 && (inStr.length() - atPosition - 1) > 63 || (inStr.length() - atPosition - 1) < 1) cout << "No\n";
    else if (checkRightPart(rightPart)) cout << "Yes\n";
    else cout << "No\n";

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
