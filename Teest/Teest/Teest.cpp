#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool isNumberString(const string& s) {
    int length = s.length();
    for (int i = 0; i < length; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;   
    }
    return true;
}

int main() {

    setlocale(LC_ALL, "Russian");
    string cardNumber;

    cout << "Эта программа использует алгоритм Луна для проверки номера кредитной карты." << endl;
    cout << "Вы можете ввести 'exit' в любое время, чтобы выйти." << endl;

    while (true) {

        cout << "Пожалуйста, введите номер кредитной карты для проверки: ";
        cin >> cardNumber;

        if (cardNumber == "exit")
            break;

        else if (!isNumberString(cardNumber)) {
            cout << "Неверный ввод! ";
            continue;
        }

        int length = cardNumber.length();
        int doubleEvenSum = 0;

        // Шаг 1: Удвоение каждой второй цифры, начиная справа. Если это
        // приводит к двузначному числу, добавьте обе цифры, чтобы получить однозначное
        // число. В конечном итоге сложите все ответы, чтобы получить 'doubleEvenSum'.

        for (int i = length - 2; i >= 0; i = i - 2) {
            int dbl = ((cardNumber[i] - 48) * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }

        // Шаг 2: Сложение каждой нечетной цифры, начиная справа, с значением 'doubleEvenSum'.

        for (int i = length - 1; i >= 0; i = i - 2) {
            doubleEvenSum += (cardNumber[i] - 48);
        }

        // Шаг 3: Проверка, делится ли 'doubleEvenSum' на 10 без остатка.
        // Если да, то номер кредитной карты считается действительным, в противном случае - нет.

        cout << (doubleEvenSum % 10 == 0 ? "Действительно!" : "Недействительно!") << endl;

        continue;
    }

    return 0;
}
