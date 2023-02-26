#pragma once
#include <iostream>
class WrongPasswordException : std::exception {
public:
	WrongPasswordException() {

	}
	WrongPasswordException(const char* message) : std::exception(message) {

	}
};