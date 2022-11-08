#include <LabelFilter.hpp>
#include <LabelGroupList.hpp>
#include <new> //For std::nothrow

class LabelFilter{
    public:
    LabelFilter();
    LabelFilter(const LabelGroupList newList);

    void                setList(const LabelGroupList newList);
    LabelGroupList      getList();
    LabelGroupList      getFilteredList();

    private:
    LabelGroupList      list;
};

LabelGroupList LabelFilter::getFilteredList()
{
    return this->list;
}

LabelFilter::LabelFilter()
{
}

LabelFilter::LabelFilter(const LabelGroupList newList)
{
    this->list = newList;
}

void LabelFilter::setList(const LabelGroupList newList)
{
    this->list = newList;
}

LabelGroupList LabelFilter::getList()
{
    return this->list;
}

