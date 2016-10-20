#include "Soundex.hpp"
#include <string>
#include <iostream>

void encodeAndPrint(const std::string& p_str)
{
    std::cout << "\"" << p_str << "\" was encoded as \"" << Soundex::encode(p_str) << "\"" << std::endl;
}

int main()
{
    std::string str0{"Robert"}, str1{"Rubert"}, str2{"Rubin"}, str3{"Ashcraft"}, str4{"Ashcroft"}, 
                str5{"Tymczak"}, str6{"Pfister"};

    encodeAndPrint(str0);
    encodeAndPrint(str1);
    encodeAndPrint(str2);
    encodeAndPrint(str3);
    encodeAndPrint(str4);
    encodeAndPrint(str5);
    encodeAndPrint(str6);

    return 0;
}
