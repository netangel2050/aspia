//
// PROJECT:         Aspia
// FILE:            category/category_optical_drive.h
// LICENSE:         GNU Lesser General Public License 2.1
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_CATEGORY__CATEGORY_OPTICAL_DRIVE_H
#define _ASPIA_CATEGORY__CATEGORY_OPTICAL_DRIVE_H

#include "category/category.h"

namespace aspia {

class CategoryOpticalDrive : public CategoryInfo
{
public:
    CategoryOpticalDrive();

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Table& table, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryOpticalDrive);
};

} // namespace aspia

#endif // _ASPIA_CATEGORY__CATEGORY_OPTICAL_DRIVE_H
