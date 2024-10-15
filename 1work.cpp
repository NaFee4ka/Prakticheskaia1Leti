#include <iostream> 
#include <windows.h>

using namespace std;



void printBinInt(int a, int* array) {

    int order = 32;
    unsigned int mask = 1 << (order - 1);

    for (int i = 1; i <= order; i++) {
        putchar(a & mask ? '1' : '0');
        array[i - 1] = a & mask ? 1 : 0;
        a <<= 1;
        if (i % 8 == 0)
            putchar(' ');
        if (i % order - 1 == 0)
            putchar(' ');
    }
    cout << "Binary";
    cout << "\n";

}



void printBinFloat(int h) {

    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(
        console_color, 15);


    int order = 32;
    unsigned int mask = 1 << (order - 1);

    for (int i = 1; i <= order; i++) {
        if (i == 1) {
            SetConsoleTextAttribute(
                console_color, 1);
        }
        if (i > 1 && i < 9) {
            SetConsoleTextAttribute(
                console_color, 6);
        }
        if (i > 9) {
            SetConsoleTextAttribute(
                console_color, 15);
        }
        putchar(h & mask ? '1' : '0');

        h <<= 1;

        if (i % 8 == 0)
            putchar(' ');
        if (i % order - 1 == 0)
            putchar(' ');
    }
    SetConsoleTextAttribute(
        console_color, 0);
    cout << "Binary";
    cout << "\n";
}

void printBinDouble(double c, int* array) {
    union {
        double d;
        int h[2];
    };
    d = c;
    int k = 0;
    unsigned int mask = 1 << 31;
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(
        console_color, 15);

    cout << "Double " << double(c) << " is ";

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 32; i++, mask >>= 1) {
            if (i == 0 && j == 0)
                SetConsoleTextAttribute(
                    console_color, 1);
            else {
                if (i > 0 && i < 11 && j == 0)
                    SetConsoleTextAttribute(console_color, 6);
                else
                    SetConsoleTextAttribute(console_color, 15);
            }
            putchar(h[1 - j] & mask ? '1' : '0');
            array[k] = h[1 - j] & mask ? 1 : 0;
            k++;
            if ((i + 1) % 8 == 0 && i != 0)
                putchar(' ');
            if (j == 0 && i == 0) {
                putchar(' ');
            }
        }
        mask = 1 << 31;
    }
    SetConsoleTextAttribute(
        console_color, 15);
    cout << " Binary" << endl;

}

int main()
{
    int a, x;
   
    double c;
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(
        console_color, 15);

    while (1) {
        cout << "input type of number \n int - 1 \n float - 2 \n double - 3 \n short int - 4 \n long int - 5 \n long doube - 6\n char - 7 \n bool - 8\n to end - 0" << endl;
        cin >> x;
        switch (x) {
        case 1:
            cout << "size - " << sizeof(int) << endl;
            break;
        case 2:
            cout << "size - " << sizeof(float) << endl;
            break;
        case 3:
            cout << sizeof(double) << endl;
            break;
        case 4:
            cout << sizeof(short int) << endl;
            break;
        case 5:
            cout << sizeof(long int) << endl;
            break;
        case 6:
            cout << sizeof(long double) << endl;
            break;
        case 7:
            cout << sizeof(char) << endl;
            break;
        case 8:
            cout << sizeof(bool) << endl;
            break;
        case 0:
            break;
        }
        if (x == 0)
            break;
    }
    x = 0;
    union {
        float f;
        int y;
    };
    while (1) {
        cout << "enter type\n int - 1 \n float - 2 \n double - 3\n end - 0\n";
        cin >> x;
        int array[64];
        int mask = 1;
        switch (x) {
        case 1:
            cout << "enter int number" << endl;
            cin >> a;
            cout << "Int " << a << " is ";
            printBinInt(a, array);

            break;
        case 2:
            cout << "enter float number" << endl;
            cin >> f;

            printBinFloat(y);
            int p, z;
            SetConsoleTextAttribute(
                console_color, 15);

            cin >> p >> z;
            if (z == 1)
                y = (mask << p) | y;
            else
                y = (mask << p) & y;
            printBinFloat(y);
            break;
        case 3:
            cout << "enter double number" << endl;
            cin >> c;
            printBinDouble(c, array);

            break;
        case 0:
            break;
        }
        if (x == 0)
            break;
    }
}
