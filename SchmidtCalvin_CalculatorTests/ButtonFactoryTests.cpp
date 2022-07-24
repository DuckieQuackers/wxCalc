#include "pch.h"
#include "CppUnitTest.h"
#include "wx/wx.h"
#include "../SchmidCalvin_Calculator/Factory.h"
#include "../SchmidCalvin_Calculator/Factory.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SchmidtCalvinCalculatorTests
{
	TEST_CLASS(ButtonFactoryTests)
	{
	private:
		Factory* _factory;

	public:

		TEST_METHOD(LabelButton1True)
		{
			wxButton* btn =_factory->createButton(nullptr, wxID_ANY, "Button1", 0, 0);
			std::string label = std::string(btn->GetLabel().c_str());
			Assert::IsTrue(label == "Button1");
		}
	};
}