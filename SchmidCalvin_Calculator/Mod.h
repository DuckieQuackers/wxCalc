#pragma once
#include "Command.h"
#include "Calculator.h"

class Mod : public Command
{
private:
	float _line = 0;
	Calculator* _calc = nullptr;
public:
	Mod(float input, Calculator* calc) {
		_line = input;
		_calc = calc;
	}

	void Execute() {
		float line2 = _calc->getLine();
		float answer = (int)_line % (int) line2;
		_calc->setAnswer(answer);
	}
};

