#include "pch.h"

// FOR WORK SWITH config to Test

extern "C" {
#include "data_list.h"
}

namespace SetNamespace {
	TEST(TestCaseName, TestName) {
		uint32_t test_value = test_list();
		EXPECT_EQ(test_value, 10);
		EXPECT_TRUE(true);

		IntList list = { NULL };
		// Добавляем элементы в список
		addItemToFront(&list, 10);
		EXPECT_EQ(list.head->value, 10);

		addItemToFront(&list, 20);
		EXPECT_EQ(list.head->value, 20);

		addItemToFront(&list, 30);
		EXPECT_EQ(list.head->value, 30);

		// Освобождаем память
		freeList(&list);
		EXPECT_EQ(list.head, nullptr);
	}

}