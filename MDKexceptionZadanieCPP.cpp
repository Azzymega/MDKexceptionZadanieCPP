#include <iostream>
#include "WrongLoginException.h"
#include "WrongPasswordException.h"
#include "PasswordCheck.h"
using std::string;

int main()
{
    std::cout << PasswordCheck("log", "123", "123");
}
