//
// PROJECT:         Aspia
// FILE:            report/report_creator.h
// LICENSE:         GNU Lesser General Public License 2.1
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_REPORT__REPORT_CREATOR_H
#define _ASPIA_REPORT__REPORT_CREATOR_H

#include "report/report.h"

#include <functional>
#include <stack>

namespace aspia {

class ReportCreatorProxy;

class ReportCreator
{
public:
    using RequestCallback =
        std::function<void(std::string_view guid,
                           std::shared_ptr <ReportCreatorProxy> report_creator)>;

    ReportCreator(CategoryList* list, Report* report, RequestCallback request_callback);
    ~ReportCreator();

    enum class State { REQUEST, OUTPUT };
    using StateChangeCallback =
        std::function<void(std::string_view category_name, State state)>;
    using TerminateCallback = std::function<void()>;

    void Start(StateChangeCallback state_change_callback,
               TerminateCallback terminate_callback);

private:
    friend class ReportCreatorProxy;

    void Parse(const std::string& data);

    void ProcessNextItem();
    static bool HasCheckedItems(CategoryGroup* parent_group);

    std::shared_ptr<ReportCreatorProxy> proxy_;

    RequestCallback request_callback_;
    StateChangeCallback state_change_callback_;
    TerminateCallback terminate_callback_;

    CategoryList* list_;
    Report* report_;

    std::stack<std::pair<CategoryList*, CategoryList::iterator>> iterator_stack_;

    DISALLOW_COPY_AND_ASSIGN(ReportCreator);
};

} // namespace aspia

#endif // _ASPIA_REPORT__REPORT_CREATOR_H
