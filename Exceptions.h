//
// Created by youssef albali on 09-Jan-22.
//

#include <exception>

#ifndef PROJECT_EXCEPTIONS_H
#define PROJECT_EXCEPTIONS_H

#endif //PROJECT_EXCEPTIONS_H

	class OutOfRange : public std::exception {
	std::string _index{};
	std::string msg{};

public:
	 explicit OutOfRange(const int index) {
		_index = std::to_string(index);
		msg = "The Index " + _index + " Is out of range";
	}

	const char *what() const noexcept override {
		return msg.c_str();
	}

};