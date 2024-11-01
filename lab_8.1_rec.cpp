#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* str, int i) {
    const char* pattern = "while";
    int len = strlen(pattern);

    if (str[i + len - 1] == '\0')  // ������� ���� �����
        return 0;

    if (strncmp(&str[i], pattern, len) == 0) {
        return 1 + Count(str, i + len);  // ������� "while", ������� ���
    }
    else {
        return Count(str, i + 1);  // ���������� �����
    }
}

char* Change(char* dest, const char* str, char* t, int i) {
    const char* pattern = "while";
    const char* replacement = "***";
    int len = strlen(pattern);

    if (str[i] == '\0') {  // ������� ���� �����
        *t = '\0';
        return dest;
    }

    if (strncmp(&str[i], pattern, len) == 0) {
        strcat(t, replacement);  // ����� �� "***"
        return Change(dest, str, t + strlen(replacement), i + len);  // ���� ��� �������� ������
    }
    else {
        *t++ = str[i];  // ������� �������� ������
        *t = '\0';
        return Change(dest, str, t, i + 1);
    }
}

int main() {
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str, 0) << " groups of \"while\"" << endl;

    char* dest1 = new char[201];
    dest1[0] = '\0';

    char* ModifiedStr = Change(dest1, str, dest1, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << ModifiedStr << endl;

    delete[] dest1;
    return 0;
}
