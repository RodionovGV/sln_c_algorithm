#include "pch.h"

extern "C" {
#include "data_queue.h"
}
namespace QueueNamespace {
	TEST(TestCaseName, TestName) {
		EXPECT_EQ(1, 1);
		QueuePtr q;
		q = initQueue();

		EXPECT_FALSE(q == nullptr);
		EXPECT_TRUE(true);


	}
}