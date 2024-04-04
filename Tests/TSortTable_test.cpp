//#include  "/my_git/Tree/Tree/Tree/TSortTable.h"
#include "../Tree/TSortTable.h" //мой путь
#include "gtest.h"
#include "string"

TEST(TSortTable, can_create_TSortTable)
{
    ASSERT_NO_THROW(TSortTable table(10));


}

TEST(TSortTable, cant_create_TSortTable_with_size_more_then_max_size)
{
    ASSERT_ANY_THROW(TSortTable table(100000000));


}

TEST(TSortTable, new_TSortTable_is_empty)
{
    TSortTable table(10);
    int a = table.GetDataCount();
    EXPECT_TRUE(a == 0);

}

TEST(TSortTable, TSortTable_is_sorted)
{
    TSortTable table(10);
    std::string str = "test";
  
    for (int i = 9; i > 0; i--)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }
    TKey j = 1;
    for (table.Reset(); !table.IsEnd(); table.GoNext())
    {
        EXPECT_TRUE(table.GetCurrentRecord().key == j);

        j++;
    }



}

TEST(TSortTable, can_insert_new_Record_in_empty_TSortTable)
{
    TSortTable table(10);
    std::string str = "test";
    TRecord a(1, str);
    ASSERT_NO_THROW(table.Insert(a));
    table.Find(1);
    EXPECT_TRUE(a == table.GetCurrentRecord());

}

TEST(TSortTable, can_insert_new_Record_in_first_pos_in_not_empty_TSortTable)
{
    TSortTable table(10);
    std::string str = "test";
    std::string str2 = "test2";
    TRecord a(2, str);
    ASSERT_NO_THROW(table.Insert(a));
    table.Find(1);
    EXPECT_TRUE(a == table.GetCurrentRecord());
    TRecord b(1, str2);
    ASSERT_NO_THROW(table.Insert(b));
    table.Reset();
    EXPECT_TRUE(table.GetCurrentRecord() == b);

}

TEST(TSortTable, can_insert_new_Record_in_last_empty_pos_in_TSortTable)
{
    TSortTable table(10);
    std::string str = "test";

    for (int i = 9; i > 0; i--)
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
    EXPECT_TRUE( table.GetCurrentPos() == 9);


}

TEST(TSortTable, can_insert_new_Record_in_mid_pos_in_TSortTable)
{
    TSortTable table(10);
    std::string str = "test";

    for (int i = 10; i > 0; i-=2)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }
    int count = table.GetDataCount();
    EXPECT_TRUE(count == 5);
    TRecord a(5, str);
    ASSERT_NO_THROW(table.Insert(a));
    table.Find(5);
    EXPECT_TRUE(a == table.GetCurrentRecord());
    EXPECT_TRUE(table.GetCurrentPos() == 2);
}

TEST(TSortTable, cant_insert_new_Record_in_Full_TSortTable)
{
    TSortTable table(10);
    std::string str = "test";

    for (int i = 10; i > 0; i--)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }
    int count = table.GetDataCount();
    EXPECT_TRUE(count == 10);
    EXPECT_TRUE(table.IsFull());
    TRecord a(11, str);
    bool insres = table.Insert(a);
    bool val = table.Find(11);
    EXPECT_TRUE(val == false);
    EXPECT_TRUE(insres == false);


}

TEST(TSortTable, can_delete_first_Record_in_TSortTable)
{
    TSortTable table(10);
    std::string str = "test";
    TRecord a(1, str);
    table.Insert(a);
    table.Find(1);
    EXPECT_TRUE(a == table.GetCurrentRecord());
    bool delres;
    ASSERT_NO_THROW(delres = table.Delete(1));
    EXPECT_TRUE(delres == true);
    EXPECT_TRUE(table.GetDataCount() == 0);



}

TEST(TSortTable, cant_delete_Record_in_empty_TSortTable)
{
    TSortTable table(10);
    bool delres;
    delres = table.Delete(1);
    EXPECT_TRUE(delres == false);
    EXPECT_TRUE(table.GetDataCount() == 0);



}

TEST(TSortTable, can_delete_last_Record_in_Full_TSortTable)
{
    TSortTable table(10);
    std::string str = "test";

    for(int i = 10; i > 0; i--)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }
    int count = table.GetDataCount();
    EXPECT_TRUE(count == 10);
    EXPECT_TRUE(table.IsFull());

    bool delres = table.Delete(10);
    bool val = table.Find(10);
    EXPECT_TRUE(val == false);
    EXPECT_TRUE(delres == true);
    count = table.GetDataCount();
    EXPECT_TRUE(count == 9);
    EXPECT_FALSE(table.IsFull());


}

TEST(TSortTable, can_delete_Record_in_mid_pos_in_TSortTable)
{
    TSortTable table(10);
    std::string str = "test";
  //  TRecord a(5, str);
    for (int i = 10; i > 0; i--)
    {
        TRecord tmp(i, str + std::to_string(i));

        table.Insert(tmp);
    }
    int count = table.GetDataCount();
    EXPECT_TRUE(count == 10);

    EXPECT_TRUE(table.IsFull());

    bool delres = table.Delete(4);
    bool val = table.Find(4);
    EXPECT_TRUE(val == false);
    EXPECT_TRUE(delres == true);


  

}

TEST(TSortTable, can_get_size_in_TSortTable)
{
    TSortTable table(10);
    int size = table.GetSize();

    EXPECT_TRUE(size == 10);

}

TEST(TSortTable, can_get_and_set_current_in_TSortTable)
{
    TSortTable table(10);
    std::string str = "test";
    TRecord a(1, str);
    for (int i = 0; i < 10; i++)
    {
        TRecord tmp(i, str + std::to_string(i));
        if (i == 9)
        {
            a = tmp;
        }
        table.Insert(tmp);
    }
    ASSERT_NO_THROW(table.SetCurrentPos(3));
    EXPECT_TRUE(table.GetCurrentPos() == 3);


}

TEST(TSortTable, cant_insert_the_record_with_the_same_key_in_TSortTable)
{
    std::string str1 = "test1";
    std::string str2 = "test2";
    TSortTable table(10);
    TRecord a(1, str1);
    TRecord b(1, str2);

    bool resins1=table.Insert(a);
    bool resins2 = table.Insert(b);
    EXPECT_TRUE(resins1 == true);
    EXPECT_TRUE(resins2 == false);


}