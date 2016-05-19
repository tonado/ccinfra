#include "gtest/gtest.h"
#include "ccinfra/container/list/List.h"
#include "ccinfra/container/list/ListElem.h"

namespace
{
    struct Foo : ListElem<Foo>
    {
        Foo(int a) : x(a)
        {
        }

        int getValue() const
        {
            return x;
        }

    private:
        int x;
    };
}

struct ListTest : testing::Test
{
protected:
    List<Foo> elems;
};

TEST_F(ListTest, should_be_empty_when_init)
{
    ASSERT_TRUE(elems.isEmpty());
    ASSERT_EQ(0, elems.size());
}

TEST_F(ListTest, should_be_get_elem_when_list_is_not_empty)
{
    Foo elem(1);

    elems.pushBack(elem);

    ASSERT_FALSE(elems.isEmpty());
    ASSERT_EQ(1, elems.size());

    Foo* first = elems.popFront();
    ASSERT_EQ(1, first->getValue());
    ASSERT_TRUE(elems.isEmpty());
}

TEST_F(ListTest, should_travel_the_list)
{
    Foo elem1(1), elem2(2), elem3(3);

    elems.pushBack(elem1);
    elems.pushBack(elem2);
    elems.pushBack(elem3);

    int i = 1;
    LIST_FOREACH(Foo, elem, elems)
    {
        ASSERT_EQ(i++, elem->getValue());
    }
}
