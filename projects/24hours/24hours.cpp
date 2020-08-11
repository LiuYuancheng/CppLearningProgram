#include <iostream>


// In vscode select Terminal> Run build Task > C/C++:g++.exe build atice file to compile.

int add(int x, int y)
{
    // add integer x and integer y then return the sum value
    std::cout << "Calculating ... \n";
    return x + y;
}

int main()
{
    std::cout << "section2: sum two int together: \n";
    std::cout << " 123 + 456 =" << add(123,456) <<"\n";
    return 0;
}
