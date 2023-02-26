#pragma once
#include <iostream>
#include "WrongLoginException.h"
#include "WrongPasswordException.h"
using std::string;

bool PasswordCheck(string login, string password, string confirmpassword) {
    try {
        string correctSymbols = "";
        string allowedSymbols = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890_";
        if (login.length() >= 20) {
            throw WrongLoginException("����� ������ 20 ��������");
        }
        if (password.length() >= 20) {
            throw WrongLoginException("������ ������ 20 ��������");
        }
        for (char loginSymbol : login)
        {
            for (char allowedSymbol : allowedSymbols) {
                if (loginSymbol == allowedSymbol) {
                    correctSymbols.append(&loginSymbol);
                }
            }
        }
        correctSymbols = "";
        if (correctSymbols != login) {
            throw WrongLoginException("����� ������� �������");
        }
        for (char passwordSymbol : password) {
            for (char allowedSymbol : allowedSymbols) {
                correctSymbols.append(&passwordSymbol);
            }
        }
        if (correctSymbols != password) {
            throw WrongLoginException("������ ������� �������");
        }
        if (password != confirmpassword) {
            throw WrongLoginException("������������� ������ ���������� �� ������");
        }
        return true;
    }
    catch (WrongPasswordException e) {
        return false;
    }
    catch (WrongLoginException e) {
        return false;
    }
}
