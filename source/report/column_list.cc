//
// PROJECT:         Aspia
// FILE:            report/column_list.cc
// LICENSE:         GNU Lesser General Public License 2.1
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#include "report/column_list.h"

namespace aspia {

ColumnList::ColumnList() = default;

ColumnList::ColumnList(ColumnList&& other)
    : list_(std::move(other.list_))
{
    // Nothing
}

ColumnList& ColumnList::operator=(ColumnList&& other)
{
    list_ = std::move(other.list_);
    return *this;
}

// static
ColumnList ColumnList::Create()
{
    return ColumnList();
}

ColumnList& ColumnList::AddColumn(std::string_view name, int width)
{
    list_.emplace_back(name, width);
    return *this;
}

ColumnList::ConstIterator ColumnList::begin() const
{
    return list_.begin();
}

ColumnList::ConstIterator ColumnList::end() const
{
    return list_.end();
}

} // namespace aspia
