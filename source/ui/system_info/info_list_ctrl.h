//
// PROJECT:         Aspia
// FILE:            ui/system_info/info_list_ctrl.h
// LICENSE:         GNU Lesser General Public License 2.1
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_UI__SYSTEM_INFO__INFO_LIST_CTRL_H
#define _ASPIA_UI__SYSTEM_INFO__INFO_LIST_CTRL_H

#include "base/macros.h"
#include "report/report.h"

#include <atlbase.h>
#include <atlapp.h>
#include <atlwin.h>
#include <atlctrls.h>
#include <atlmisc.h>

namespace aspia {

class InfoListCtrl
    : public CWindowImpl<InfoListCtrl, CListViewCtrl>,
      public Report
{
public:
    InfoListCtrl() = default;
    ~InfoListCtrl() = default;

    void DeleteAllColumns();
    int GetColumnCount() const;
    void SortColumnItems(int column_index);

protected:
    void StartDocument() final;
    void EndDocument() final;
    void StartTableGroup(std::string_view name) final;
    void EndTableGroup() final;
    void StartTable(Category* category) final;
    void EndTable() final;
    void AddColumns(const ColumnList& column_list) final;
    void StartGroup(std::string_view name) final;
    void EndGroup() final;
    void AddParam(std::string_view param, const Value& value) final;
    void StartRow() final;
    void EndRow() final;
    void AddValue(const Value& value) final;

private:
    BEGIN_MSG_MAP(InfoListCtrl)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
    END_MSG_MAP()

    LRESULT OnCreate(UINT message, WPARAM wparam, LPARAM lparam, BOOL& handled);
    std::wstring ValueToString(const Value& value);

    struct SortingContext
    {
        InfoListCtrl* list;
        int column_index;
    };

    static int CALLBACK SortingCompare(LPARAM lparam1, LPARAM lparam2, LPARAM lparam_sort);

    enum IconIndex
    {
        ICON_INDEX_CATEGORY  = 0,
        ICON_INDEX_CHECKED   = 1,
        ICON_INDEX_UNCHECKED = 2
    };

    CSize small_icon_size_;
    CImageListManaged imagelist_;

    bool sorting_enabled_ = true;
    bool sorting_ascending_ = false;
    int item_count_ = 0;
    int column_count_ = 0;
    int current_column_ = 0;
    int indent_ = 0;

    DISALLOW_COPY_AND_ASSIGN(InfoListCtrl);
};

} // namespace aspia

#endif // _ASPIA_UI__SYSTEM_INFO__INFO_LIST_CTRL_H
