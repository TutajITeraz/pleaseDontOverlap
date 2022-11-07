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


//C interface for calling from the python tester
extern "C"
{
    //Note: The interface this linkage region needs to use C only.  
    void * CreateInstanceOfLabelFilter( void )
    {
        return new(std::nothrow) LabelFilter;
    }

    void DeleteInstanceOfLabelFilter(void *ptr)
    {
         delete ptr; 
    }

    int CallLabelFilterSetList(void *ptr, const LabelGroupList newList)
    {
        // we should avoid throwing exceptions for outside  
        try
        {
            LabelFilter * ref = reinterpret_cast<LabelFilter *>(ptr);
            ref->setList(newList);
            return 0;
        }
        catch(...)
        {
           return -1; //assuming -1 is an error condition. 
        }
    }

} //End C linkage scope.