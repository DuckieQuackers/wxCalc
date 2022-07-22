#include "Calculator.h"

Calculator::Calculator() {
	_answer = 0;
	_currentLine = 0;
}

float Calculator::getAnswer() {
	return _answer;
}

float Calculator::getLine() {
	return _currentLine;
}

void Calculator::setAnswer(float answer) {
	_answer = answer;
}

void Calculator::setLine(float set) {
	_currentLine = set;
}