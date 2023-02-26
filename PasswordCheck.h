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
                    correctSymbols = correctSymbols + loginSymbol;
                }
            }
        }
        if (correctSymbols != login) {
            throw WrongLoginException("����� ������� �������");
        }
        correctSymbols = "";
        for (char passwordSymbol : password) {
            for (char allowedSymbol : allowedSymbols) {
                if (passwordSymbol == allowedSymbol) {
                    correctSymbols = correctSymbols + passwordSymbol;
                }
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
