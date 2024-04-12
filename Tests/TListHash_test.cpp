#include "../Tree/TListHash.h"
#include "gtest.h"
#include "string"

TEST(TListHash, can_create_TListHash_table)
{
    ASSERT_NO_THROW(TListHash table(10));
}

TEST(TListHash, cant_create_TListHash_table_with_size_more_then_max_size)
{
    ASSERT_ANY_THROW(TListHash table(100000000));
}

TEST(TListHash, can_get_size_from_TListHash_table)
{
    TListHash table(10);
    int size = table.GetSize();
    EXPECT_TRUE(size == 10);
}

TEST(TListHash, new_TListHash_table_is_empty)
{
    TListHash table(10);
    EXPECT_EQ(true, table.IsEmpty());
}

TEST(TListHash, can_insert_new_Record_in_empty_TListHash_table)
{
    TListHash table(10);
    std::string str = "test";
    TRecord a(1, str);
    ASSERT_NO_THROW(table.Insert(a));
    table.Find(1);
    EXPECT_TRUE(a == table.GetCurrentRecord());
}

TEST(TListHash, can_insert_new_Record_in_last_empty_pos_in_TListHash_table)
{
    TListHash table(10);
    std::string str = "test";

    for (int i = 0; i < 9; i++)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }

    int count = table.GetDataCount();
    EXPECT_TRUE(count == 9);
    TRecord a(10, str);
    ASSERT_NO_THROW(table.Insert(a));
    table.Find(10);
    EXPECT_TRUE(a == table.GetCurrentRecord());
}

TEST(TListHash, can_insert_new_Record_in_mid_pos_in_TListHash_table)
{
    TListHash table(10);
    std::string str = "test";

    for (int i = 0; i < 5; i++)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }

    int count = table.GetDataCount();
    EXPECT_TRUE(count == 5);
    TRecord a(6, str);
    ASSERT_NO_THROW(table.Insert(a));

    for (int i = 7; i < 10; i++)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }

    table.Find(6);
    EXPECT_TRUE(a == table.GetCurrentRecord());
}



TEST(TListHash, return_false_when_insert_existing_Record_in_TListHash_table)
{
    TListHash table(10);
    std::string str = "test";

    for (int i = 0; i < 9; i++)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }

    TRecord a(8, "test0");
    EXPECT_EQ(false, table.Insert(a));
}

TEST(TListHash, can_delete_first_Record_from_TListHash_table)
{
    TListHash table(10);
    std::string str = "test";

    TRecord a(1, str);
    table.Insert(a);
    table.Find(1);
    EXPECT_TRUE(a == table.GetCurrentRecord());

    ASSERT_NO_THROW(table.Delete(1));
    EXPECT_TRUE(table.GetDataCount() == 0);
}

TEST(TListHash, cant_delete_Record_from_empty_TListHash_table)
{
    TListHash table(10);
    ASSERT_ANY_THROW(table.Delete(1));
}

TEST(TListHash, return_false_when_delete_unexisting_Record_from_TListHash_table)
{
    TListHash table(10);
    std::string str = "test";

    for (int i = 0; i < 9; i++)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }

    bool delres;
    delres = table.Delete(11);
    EXPECT_TRUE(delres == false);
}

TEST(TListHash, can_delete_Record_from_mid_pos_in_TListHash_table)
{
    TListHash table(10);
    std::string str = "test";
    TRecord a(1, str);
    for (int i = 0; i < 10; i++)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }

    int count = table.GetDataCount();
    EXPECT_TRUE(count == 10);

    table.Delete(4);
    bool val = table.Find(4);
    EXPECT_TRUE(val == false);
    EXPECT_TRUE(table.GetDataCount() == 9);
}