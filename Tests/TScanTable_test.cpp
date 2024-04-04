
//#include  "/my_git/Tree/Tree/Tree/TScanTable.h"
#include "../Tree/TScanTable.h" //мой путь
#include "gtest.h"
#include "string"

TEST(TScanTable, can_create_TScanTable)
{
    ASSERT_NO_THROW(TScanTable table(10));
    

}

TEST(TScanTable, cant_create_TScanTable_with_size_more_then_max_size)
{
    ASSERT_ANY_THROW(TScanTable table(100000000));


}

TEST(TScanTable, new_TScanTable_is_empty)
{
    TScanTable table(10);
   int a = table.GetDataCount();
   EXPECT_TRUE(a == 0);

}

TEST(TScanTable, can_insert_new_Record_in_empty_TScanTable)
{
    TScanTable table(10);
    std::string str = "test";
    TRecord a(1, str);
    ASSERT_NO_THROW(table.Insert(a));
    table.Find(1);
    EXPECT_TRUE(a == table.GetCurrentRecord());

}

TEST(TScanTable, can_insert_new_Record_in_last_empty_pos_in_TScanTable)
{
    TScanTable table(10);
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

TEST(TScanTable, can_insert_new_Record_in_mid_pos_in_TScanTable)
{
    TScanTable table(10);
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
    table.Find(6);
    EXPECT_TRUE(a == table.GetCurrentRecord());

}

TEST(TScanTable, cant_insert_new_Record_in_Full_TScanTable)
{
    TScanTable table(10);
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
   bool insres = table.Insert(a);
   bool val = table.Find(10);
   EXPECT_TRUE(val == false);
   EXPECT_TRUE(insres == false);


}

TEST(TScanTable, can_delete_first_Record_in_TScanTable)
{
    TScanTable table(10);
    std::string str = "test";
    TRecord a(1, str);
     table.Insert(a);
    table.Find(1);
    EXPECT_TRUE(a == table.GetCurrentRecord());
    bool delres;
    ASSERT_NO_THROW(delres=table.Delete(1));
    EXPECT_TRUE(delres == true);
    EXPECT_TRUE(table.GetDataCount() == 0);



}

TEST(TScanTable, cant_delete_Record_in_empty_TScanTable)
{
    TScanTable table(10);
    bool delres;
    delres = table.Delete(1);
    EXPECT_TRUE(delres == false);
    EXPECT_TRUE(table.GetDataCount() == 0);



}

TEST(TScanTable, can_delete_last_Record_in_Full_TScanTable)
{
    TScanTable table(10);
    std::string str = "test";

    for (int i = 0; i < 10; i++)
    {
        TRecord tmp(i, str + std::to_string(i));
        table.Insert(tmp);
    }
    int count = table.GetDataCount();
    EXPECT_TRUE(count == 10);
    EXPECT_TRUE(table.IsFull());

    bool delres = table.Delete(9);
    bool val = table.Find(9);
    EXPECT_TRUE(val == false);
    EXPECT_TRUE(delres == true);
    count = table.GetDataCount();
    EXPECT_TRUE(count == 9);
    EXPECT_FALSE(table.IsFull());


}

TEST(TScanTable, can_delete_Record_in_mid_pos_in_TScanTable)
{
    TScanTable table(10);
    std::string str = "test";
    TRecord a(1, str);
    for (int i = 0; i < 10; i++)
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

TEST(TScanTable, can_get_size_in_TScanTable)
{
    TScanTable table(10);
   int size = table.GetSize();

   EXPECT_TRUE(size == 10);

}

TEST(TScanTable, can_get_and_set_current_in_TScanTable)
{
    TScanTable table(10);
    std::string str = "test";
    TRecord a;
    for (int i = 0; i < 10; i++)
    {
        TRecord tmp(i, str + std::to_string(i));

        table.Insert(tmp);
    }
    EXPECT_TRUE(table.GetCurrentPos() == 9);

    ASSERT_NO_THROW(table.SetCurrentPos(3));
    EXPECT_TRUE(table.GetCurrentPos() == 3);


}

TEST(TScanTable, cant_insert_the_record_with_the_same_key_in_TScanTable)
{
    std::string str1 = "test1";
    std::string str2 = "test2";
    TScanTable table(10);
    TRecord a(1, str1);
    TRecord b(1, str2);

    bool resins1 = table.Insert(a);
    bool resins2 = table.Insert(b);
    EXPECT_TRUE(resins1 == true);
    EXPECT_TRUE(resins2 == false);


}
