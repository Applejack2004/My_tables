#include "../Tree/AVLTree.h" 
#include "gtest.h"
#include "string"

TEST(AVLTree, can_create_AVLTree)
{
	ASSERT_NO_THROW(AVLTree tree);
}

TEST(AVLTree, new_tree_table_is_empty)
{
	AVLTree tree;
	EXPECT_EQ(true, tree.IsEmpty());
}

TEST(AVLTree, can_get_dataCount)
{
	AVLTree tree;
	std::string val;

	for (int i = 0; i < 5; i++)
	{
		val = "test" + std::to_string(i);
		TRecord record(i, val);
		tree.Insert(record);
	}

	EXPECT_EQ(5, tree.GetDataCount());
}

TEST(AVLTree, can_reset)
{
	AVLTree tree1;
	std::string val;
	for (int i = 1; i < 8; i++)
	{
		val = "test" + std::to_string(i);
		if (i <= 4)
		{
			TRecord record(i + 3, val);
			tree1.Insert(record);
		}
		else {
			TRecord record(i - 4, val);
			tree1.Insert(record);
		}
	}
	tree1.Reset();
	EXPECT_EQ(1, tree1.GetCurrentRecord().key);

	AVLTree tree2;
	for (int i = 1; i < 5; i++)
	{
		val = "test" + std::to_string(i);
		TRecord record(i, val);
		tree2.Insert(record);
	}
	tree2.Reset();
	EXPECT_EQ(1, tree2.GetCurrentRecord().key);

	AVLTree tree3;
	for (int i = 5; i >= 1; i--)
	{
		val = "test" + std::to_string(i);
		TRecord record(i, val);
		tree3.Insert(record);
	}
	tree3.Reset();
	EXPECT_EQ(1, tree3.GetCurrentRecord().key);

	AVLTree tree;
	TRecord rec4(4, "test4");
	tree.Insert(rec4);
	TRecord rec3(3, "test3");
	tree.Insert(rec3);
	TRecord rec2(2, "test2");
	tree.Insert(rec2);
	TRecord rec5(5, "test5");
	tree.Insert(rec5);
	TRecord rec6(6, "test6");
	tree.Insert(rec6);
	TRecord rec7(7, "test7");
	tree.Insert(rec7);
	tree.Reset();
	TRecord rec1(1, "test7");
	tree.Insert(rec1);
	tree.Reset();
	EXPECT_EQ(1, tree.GetCurrentRecord().key);
}

TEST(AVLTree, can_understand_that_isEnd)
{
	AVLTree tree;
	TRecord rec4(4, "test4");
	tree.Insert(rec4);
	TRecord rec3(3, "test3");
	tree.Insert(rec3);
	tree.Reset();
	tree.GoNext();
	tree.GoNext();
	EXPECT_EQ(true, tree.IsEnd());
}

TEST(AVLTree, can_go_next)
{
	AVLTree tree;
	ASSERT_ANY_THROW(tree.GoNext());

	TRecord rec4(4, "test4");
	tree.Insert(rec4);
	TRecord rec3(3, "test3");
	tree.Insert(rec3);
	TRecord rec6(6, "test6");
	tree.Insert(rec6);
	TRecord rec2(2, "test2");
	tree.Insert(rec2);
	TRecord rec5(5, "test5");
	tree.Insert(rec5);
	TRecord rec7(7, "test7");
	tree.Insert(rec7);
	tree.Reset();
	for (int i = 2; i <= 7; i++)
	{
		EXPECT_EQ(i, tree.GetCurrentRecord().key);
		tree.GoNext();
	}

	ASSERT_ANY_THROW(tree.GoNext());
}

TEST(AVLTree, can_find_record)
{
	AVLTree tree;
	TRecord rec(1, "test1");
	tree.Insert(rec);
	EXPECT_FALSE(tree.Find(2));
	TRecord rec2(2, "test2");
	tree.Insert(rec2);
	EXPECT_TRUE(tree.Find(2));
}

TEST(AVLTree, can_insert)
{
	AVLTree tree;
	TRecord rec4(4, "test4");
	tree.Insert(rec4);
	TRecord rec3(3, "test3");
	tree.Insert(rec3);
	TRecord rec2(2, "test2");
	tree.Insert(rec2);
	TRecord rec5(5, "test5");
	tree.Insert(rec5);
	TRecord rec6(6, "test6");
	tree.Insert(rec6);

	EXPECT_EQ(-1, tree.GetRightKey(6));
	TRecord rec7(7, "test7");
	tree.Insert(rec7);
	EXPECT_EQ(7, tree.GetRightKey(6));

	EXPECT_EQ(-1, tree.GetLeftKey(2));
	TRecord rec1(1, "test1");
	tree.Insert(rec1);
	EXPECT_EQ(1, tree.GetLeftKey(2));
}

TEST(AVLTree, can_delete_from_the_end)
{
	AVLTree tree;
	TRecord rec52(52, "test52");
	tree.Insert(rec52);
	TRecord rec43(43, "test43");
	tree.Insert(rec43);
	TRecord rec21(21, "test21");
	tree.Insert(rec21);
	TRecord rec60(60, "test60");
	tree.Insert(rec60);
	TRecord rec57(57, "test57");
	tree.Insert(rec57);
	TRecord rec70(70, "test70");
	tree.Insert(rec70);

	EXPECT_EQ(70, tree.GetRightKey(60));
	tree.Delete(70);
	EXPECT_EQ(-1, tree.GetRightKey(60));
}

TEST(AVLTree, can_delete_from_the_middle)
{
	//-----------------------------------
	AVLTree tree;
	TRecord rec52(52, "test52");
	tree.Insert(rec52);
	TRecord rec43(43, "test43");
	tree.Insert(rec43);
	TRecord rec21(21, "test21");
	tree.Insert(rec21);
	TRecord rec60(60, "test60");
	tree.Insert(rec60);
	TRecord rec57(57, "test57");
	tree.Insert(rec57);
	TRecord rec70(70, "test70");
	tree.Insert(rec70);

	EXPECT_EQ(43, tree.GetLeftKey(57));
	tree.Delete(43);
	EXPECT_EQ(52, tree.GetLeftKey(57));

	//-----------------------------------
	AVLTree tree1;
	tree1.Insert(rec52);
	tree1.Insert(rec43);
	tree1.Insert(rec21);
	tree1.Insert(rec60);
	tree1.Insert(rec57);
	tree1.Insert(rec70);

	EXPECT_EQ(60, tree1.GetRightKey(57));
	EXPECT_EQ(-1, tree1.GetLeftKey(60));
	EXPECT_EQ(70, tree1.GetRightKey(60));
	EXPECT_EQ(43, tree1.GetLeftKey(57));
	tree1.Delete(60);
	EXPECT_EQ(70, tree1.GetRightKey(57));
	EXPECT_EQ(-1, tree1.GetRightKey(70));
	EXPECT_EQ(-1, tree1.GetLeftKey(70));
	EXPECT_EQ(43, tree1.GetLeftKey(57));
	
}

TEST(AVLTree, can_delete_root)
{
	AVLTree tree;
	TRecord rec52(52, "test52");
	tree.Insert(rec52);
	TRecord rec43(43, "test43");
	tree.Insert(rec43);
	TRecord rec21(21, "test21");
	tree.Insert(rec21);
	TRecord rec45(45, "test45");
	tree.Insert(rec45);
	TRecord rec60(60, "test60");
	tree.Insert(rec60);
	TRecord rec57(57, "test57");
	tree.Insert(rec57);
	TRecord rec70(70, "test70");
	tree.Insert(rec70);
    

	EXPECT_EQ(60, tree.GetRightKey(52));
	EXPECT_EQ(43, tree.GetLeftKey(52));
	EXPECT_EQ(-1, tree.GetRightKey(57));
	EXPECT_EQ(-1, tree.GetLeftKey(57));
	EXPECT_EQ(70, tree.GetRightKey(60));
	EXPECT_EQ(57, tree.GetLeftKey(60));
	tree.Delete(52);
	EXPECT_EQ(60, tree.GetRightKey(57));
	EXPECT_EQ(43, tree.GetLeftKey(57));
	EXPECT_EQ(70, tree.GetRightKey(60));
	EXPECT_EQ(-1, tree.GetLeftKey(60));
}

TEST(AVLTree, can)
{
	AVLTree tree;
	for (int i = 0; i < 100; i++) {
		std::string str = "name" + std::to_string(i);
		TRecord rec(i, str);
		tree.Insert(rec);
	}

}