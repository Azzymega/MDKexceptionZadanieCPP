#pragma once
#include <iostream>
class WrongLoginException : std::exception {
public:
	WrongLoginException() {

	}
	WrongLoginException(const char* message) : std::exception(message) {

	}
};