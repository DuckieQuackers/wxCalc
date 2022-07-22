#pragma once

class Calculator
{
private:
	float _currentLine;
	float _answer;
public:
	Calculator();
	void setLine(float set);
	void setAnswer(float answer);
	float getLine();
	float getAnswer();
};

