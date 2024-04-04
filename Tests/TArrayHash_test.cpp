#include "../Tree/TArrayHash.h"
#include "gtest.h"
#include "string"

TEST(TArrayHash, can_create_TArrayHash_table)
{
    ASSERT_NO_THROW(TArrayHash table(10,3));
}

TEST(TArrayHash, cant_create_TArrayHash_table_with_size_more_then_max_size)
{
    ASSERT_ANY_THROW(TArrayHash table(100000000,3));
}

TEST(TArrayHash, can_get_size_from_TArrayHash_table)
{
    TArrayHash table(10);
    int size = table.GetSize();
    EXPECT_TRUE(size == 10);
}

TEST(TArrayHash, can_get_and_set_current_in_TArrayHash_table)
{
    TArrayHash table(10);
    std::string str = "test";
    
    for (int i = 0; i < 10; i++)
    {
        TRecord tmp(i, str + std::to_string(i));

        table.Insert(tmp);
    }

    TRecord a(55, "test55");
    TRecord a1(5, "test5");
    ASSERT_NO_THROW(table.SetCurrentPos(5));
    EXPECT_EQ(table.GetCurrentRecord().key,5);
    EXPECT_EQ(table.GetCurrentRecord().value, "test5");
    ASSERT_NO_THROW(table.SetCurrentRecord(a));
    EXPECT_EQ(table.GetCurrentRecord().key, 55);
    EXPECT_EQ(table.GetCurrentRecord().value, "test55");
}

TEST(TArrayHash, new_TArrayHash_table_is_empty)
{
    TArrayHash table(10);
    EXPECT_EQ(true, table.IsEmpty());
}

TEST(TArrayHash, can_insert_new_Record_in_empty_TArrayHash_table)
{
    TArrayHash table(10);
    std::string str = "test";
    TRecord a(1, str);
    ASSERT_NO_THROW(table.Insert(a));
    table.Find(1);
    EXPECT_TRUE(a == table.GetCurrentRecord());
}

TEST(TArrayHash, can_insert_new_Record_in_last_empty_pos_in_TArrayHash_table)
{
    TArrayHash table(10);
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

TEST(TArrayHash, can_insert_new_Record_in_mid_pos_in_TArrayHash_table)
{
    TArrayHash table(10);
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

TEST(TArrayHash, cant_insert_new_Record_in_Full_TArrayHash_table)
{
    TArrayHash table(10);
    std::string str = "test";

    for (int i = 0; i < 10; i++)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }

    int count = table.GetDataCount();
    EXPECT_TRUE(count == 10);
    EXPECT_TRUE(table.IsFull());

    TRecord a(10, str);
    ASSERT_ANY_THROW(table.Insert(a));
}

TEST(TArrayHash, return_false_when_insert_existing_Record_in_TArrayHash_table)
{
    TArrayHash table(10);
    std::string str = "test";

    for (int i = 0; i < 9; i++)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }

    TRecord a(8, "test0");
    EXPECT_EQ(false,table.Insert(a));
}

TEST(TArrayHash, can_delete_first_Record_from_TArrayHash_table)
{
    TArrayHash table(10);
    std::string str = "test";

    TRecord a(1, str);
    table.Insert(a);
    table.Find(1);
    EXPECT_TRUE(a == table.GetCurrentRecord());

    ASSERT_NO_THROW(table.Delete(1));
    EXPECT_TRUE(table.GetDataCount() == 0);
}

TEST(TArrayHash, cant_delete_Record_from_empty_TArrayHash_table)
{
    TArrayHash table(10);
    ASSERT_ANY_THROW(table.Delete(1));
}

TEST(TArrayHash, return_false_when_delete_unexisting_Record_from_TArrayHash_table)
{
    TArrayHash table(10);
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

TEST(TArrayHash, can_delete_last_Record_from_Full_TArrayHash_table)
{
    TArrayHash table(10);
    std::string str = "test";

    for (int i = 0; i < 10; i++)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }

    int count = table.GetDataCount();
    EXPECT_TRUE(count == 10);
    EXPECT_TRUE(table.IsFull());

    table.Delete(9);
    bool val = table.Find(9);
    EXPECT_TRUE(val == false);
    
    count = table.GetDataCount();
    EXPECT_TRUE(count == 9);
    EXPECT_FALSE(table.IsFull());
}

TEST(TArrayHash, can_delete_Record_from_mid_pos_in_TArrayHash_table)
{
    TArrayHash table(10);
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