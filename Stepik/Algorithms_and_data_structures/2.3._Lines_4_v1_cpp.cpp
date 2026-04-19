#include <iostream>
#include <vector>
#include <locale>
#include <string>
#include <windows.h>

int main() {

    SetConsoleCP(65001);       // Кодировка ввода
    SetConsoleOutputCP(65001); // Кодировка вывода

    setlocale(LC_ALL, "Russian"); // Устанавливаем русскую локаль
    //std::string str;

    std::wstring str;

    getline(std::wcin, str);

    //char mas[] {".", ",", "!", "?", ";", ":", "-"," ","/"};
    wchar_t mas[] = { '.', ',', '!', '?', ';', ':', '-' };

    //std::cout << str.size();
    //std::cout << str;

    std::vector<std::wstring> vec;

    bool fnew = true;

    for (const char c : str)
    {
        //std::string s{std::toupper(c)}; 

        //std::string s{std::tolower(c)};

        std::wstring s;

        s = std::tolower(c);
        std::wcout << s << std::endl;
        for (const wchar_t i : mas)
        {
            std::wstring si{ i };
            if (s == si)
            {
                //std::cout << s << " " << si << std::endl;
                fnew = false;
            }
        }

        if (fnew) {
            //std::string s{c};
            //std::cout << c << " ";
            vec.push_back(s);
        }
        fnew = true;
    }
    //std::cout << vec << " ";

    bool flag = true;

    for (int i{ 0 }; i < vec.size(); i++) {
        if (vec[i] != vec[vec.size() - 1 - i])
        {
            flag = false;
            break;
        }

    }

    if (flag == true) {
        std::wcout << "YES";
    }
    else {
        std::wcout << "NO";
    }
    //str[0] = 'A';

    //std::cout << str;
    //std::cout << str[1];

    // put your code here
    return 0;
}