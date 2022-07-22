#pragma once
#include "Command.h"
#include "Calculator.h"

class Addition : public Command
{
private:
	float _line = 0;
	Calculator* _calc = nullptr;
public:
	Addition(float input, Calculator* calc) {
		_line = input;
		_calc = calc;
	}

	void Execute() {
		float line2 = _calc->getLine();
		float answer = _line + line2;
		_calc->setAnswer(answer);
	}
};