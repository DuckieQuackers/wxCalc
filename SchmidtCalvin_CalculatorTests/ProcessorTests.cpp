#include "pch.h"
#include "CppUnitTest.h"
#include "../SchmidCalvin_Calculator/Processor.h"
#include "../SchmidCalvin_Calculator/Calculator.h"
#include "../SchmidCalvin_Calculator/Addition.h"
#include "../SchmidCalvin_Calculator/Subtraction.h"
#include "../SchmidCalvin_Calculator/Multiply.h"
#include "../SchmidCalvin_Calculator/Division.h"
#include "../SchmidCalvin_Calculator/Mod.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SchmidtCalvinCalculatorTests
{
	TEST_CLASS(ProcessorTests)
	{
	private:
		Processor* _processor = Processor::GetInstance();

	public:
		TEST_METHOD(TwoPTwoTrue)
		{
			_processor->Add(2);
			_processor->setCalcLine(2);
			int answer = _processor->Calculate();
			Assert::AreEqual(answer, 4);
		}

		TEST_METHOD(TenPFiveTrue) {
			_processor->Add(10);
			_processor->setCalcLine(5);
			int answer = _processor->Calculate();
			Assert::AreEqual(answer, 15);
		}

		TEST_METHOD(ThreeTThreeTrue) {
			_processor->Multi(3);
			_processor->setCalcLine(3);
			int answer = _processor->Calculate();
			Assert::AreEqual(answer, 9);
		}

		TEST_METHOD(FourTFiveFalse) {
			_processor->Multi(4);
			_processor->setCalcLine(5);
			int answer = _processor->Calculate();
			Assert::AreNotEqual(answer, 24);
		}

		TEST_METHOD(ElvenTFourTrue) {
			_processor->Multi(11);
			_processor->setCalcLine(4);
			int answer = _processor->Calculate();
			Assert::AreEqual(answer, 44);
		}

		TEST_METHOD(TenModThreeTrue) {
			_processor->mod(10);
			_processor->setCalcLine(3);
			int answer = _processor->Calculate();
			Assert::AreEqual(answer, 1);
		}

		TEST_METHOD(TwoMTwoFalse) {
			_processor->Multi(2);
			_processor->setCalcLine(2);
			int answer = _processor->Calculate();
			Assert::AreNotEqual(answer, 0);
		}

		TEST_METHOD(OneFiftyOneBinaryTrue) {
			bool answer = _processor->Binary(151) == "00000000000000000000000010010111";
			Assert::IsTrue(answer);
		}

		TEST_METHOD(TwoSixtyTheeBinaryFalse) {
			bool answer = _processor->Binary(263) == "00000000000000000000000100000110";
			Assert::IsFalse(answer);
		}

		TEST_METHOD(TwoFiveEightSevenHexTrue) {
			bool answer = _processor->Hexidecimal(2587) == "0xA1B";
			Assert::IsTrue(answer);
		}
	};
}