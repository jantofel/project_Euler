#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Problem50\Problem50.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Problem50Test
{		
	TEST_CLASS(Problem50Test)
	{
	public:

    TEST_METHOD(TestMethod100)
    {
      Problem50 p50;
      Assert::AreEqual(41, p50.findConsecutivePrimeSumThatAddsToAPrime(100));
      // TODO: Your test code here
    }

    TEST_METHOD(TestMethod1000)
    {
      Problem50 p50;
      Assert::AreEqual(953, p50.findConsecutivePrimeSumThatAddsToAPrime(1000));
      // TODO: Your test code here
    }

	};
}