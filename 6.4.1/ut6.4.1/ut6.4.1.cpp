#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ut641
{
	TEST_CLASS(ut641)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double a[4] = { -1, 2, 3, -4 };

			double s = 0;

			s = sum(a, 4);

			Assert::AreEqual(-5.0, s);
		}
	};
}
