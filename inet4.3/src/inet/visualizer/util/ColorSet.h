//
// Copyright (C) 2020 OpenSim Ltd.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#ifndef __INET_COLORSET_H
#define __INET_COLORSET_H

#include "inet/common/INETDefs.h"

namespace inet {

namespace visualizer {

class INET_API ColorSet
{
  protected:
    std::vector<cFigure::Color> colors;

  public:
    void parseColors(const char *colorNames);
    size_t getSize() const { return colors.size(); }
    cFigure::Color getColor(int index) const;
};

} // namespace visualizer

} // namespace inet

#endif
