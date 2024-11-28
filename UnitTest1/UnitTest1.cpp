#include "pch.h"
#include "CppUnitTest.h"
#include "../LR12.1C++/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double* x = new double[10];
			int pos = 0;
			x = Create("text.dat");
			bool v = false;
			if (x[0] != NULL)
				v = true;
			bool exp = true;

			Assert::AreEqual(exp, v);
		}
	};
}
