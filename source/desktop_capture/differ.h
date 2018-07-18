//
// Aspia Project
// Copyright (C) 2018 Dmitry Chapyshev <dmitry@aspia.ru>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#ifndef _ASPIA_DESKTOP_CAPTURE__DIFFER_H
#define _ASPIA_DESKTOP_CAPTURE__DIFFER_H

#include <QRegion>
#include <memory>

namespace aspia {

// Class to search for changed regions of the screen.
class Differ
{
public:
    explicit Differ(const QSize& size);
    ~Differ() = default;

    void calcDirtyRegion(const quint8* prev_image,
                         const quint8* curr_image,
                         QRegion* changed_region);

private:
    void markDirtyBlocks(const quint8* prev_image, const quint8* curr_image);
    void mergeBlocks(QRegion* dirty_region);

    const QRect screen_rect_;

    const int bytes_per_row_;

    const int full_blocks_x_;
    const int full_blocks_y_;

    int partial_column_width_;
    int partial_row_height_;

    int block_stride_y_;

    const int diff_width_;
    const int diff_height_;

    std::unique_ptr<quint8[]> diff_info_;

    typedef quint8(*DiffFullBlockFunc)(const quint8*, const quint8*, int);
    DiffFullBlockFunc diff_full_block_func_;

    Q_DISABLE_COPY(Differ)
};

} // namespace aspia

#endif // _ASPIA_DESKTOP_CAPTURE___DIFFER_H
