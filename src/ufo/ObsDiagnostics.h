/*
 * (C) Copyright 2018  UCAR
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 */

#ifndef UFO_OBSDIAGNOSTICS_H_
#define UFO_OBSDIAGNOSTICS_H_

#include <ostream>
#include <string>
#include <vector>

#include <boost/noncopyable.hpp>

#include "oops/util/Printable.h"
#include "ufo/GeoVaLs.h"

// Forward declarations
namespace oops {
  class Variables;
}

namespace ioda {
  class ObsSpace;
}

namespace ufo {
  class Locations;

// -----------------------------------------------------------------------------

class ObsDiagnostics : public util::Printable,
                       private boost::noncopyable {
 public:
  ObsDiagnostics(const ioda::ObsSpace &, const Locations &, const oops::Variables &);
  ~ObsDiagnostics() {}

// I/O
  void save(const std::string &) const;

// Interfaces
  int & toFortran() {return gdiags_.toFortran();}
  const int & toFortran() const {return gdiags_.toFortran();}

  bool has(const std::string & var) const {return gdiags_.has(var);}
  void get(std::vector<float> &, const std::string &, const int lev = 1) const;

 private:
  void print(std::ostream &) const;
  const ioda::ObsSpace & obsdb_;

  GeoVaLs gdiags_;
};

// -----------------------------------------------------------------------------

}  // namespace ufo

#endif  // UFO_OBSDIAGNOSTICS_H_