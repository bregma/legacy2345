/**
 * @file legacy/world/maplayer.h
 * @brief Public interface for the Legacy world MapLayer class.
 */

/*
 * Copyright 2016 Stephen M. Webb <stephen.webb@bregmasoft.ca>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LEGACY_WORLD_MAPLAYER_H_
#define LEGACY_WORLD_MAPLAYER_H_

#include <iosfwd>
#include <vector>


namespace Legacy {
namespace World {

/**
 * An ordered collection of Cell indexes that make up a single map layer.
 */
class MapLayer
{
public:
  MapLayer(unsigned length, unsigned width);

  MapLayer(MapLayer const& rhs) = default;

  /** The east-west extent of the map layer. */
  unsigned
  length() const;

  /** The north-south extent of the map layer. */
  unsigned
  width() const;

  /** Gets the cache index of the cell at given coordinates. */
  int
  cell_index_at(unsigned x, unsigned y) const;

  /** Sets the cache index of the cell at given coordinates. */
  void
  set_cell_index_at(unsigned x, unsigned y, int index);

private:
  unsigned 
  cell_offset_of(unsigned x, unsigned y) const;

private:
  unsigned         length_;
  unsigned         width_;
  std::vector<int> cells_;
};


std::ostream&
operator<<(std::ostream& ostr, MapLayer const& layer);

bool
operator==(MapLayer const& lhs, MapLayer const& rhs);

bool inline
operator!=(MapLayer const& lhs, MapLayer const& rhs)
{ return !(lhs == rhs); }

} // namespace World
} // namespace Legacy

#endif // LEGACY_WORLD_MAPLAYER_H_
