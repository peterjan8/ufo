/*
 * (C) Copyright 2017 UCAR
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 */

#ifndef UFO_ATMOSPHERE_CRTM_OBSAODTLAD_INTERFACE_H_
#define UFO_ATMOSPHERE_CRTM_OBSAODTLAD_INTERFACE_H_

#include "ioda/ObsSpace.h"

#include "ufo/Fortran.h"

namespace ufo {

/// Interface to Fortran UFO routines
/*!
 * The core of the UFO is coded in Fortran.
 * Here we define the interfaces to the Fortran code.
 */

extern "C" {

// -----------------------------------------------------------------------------
//  AOD tl/ad observation operator
// -----------------------------------------------------------------------------
  void ufo_aod_tlad_setup_f90(F90hop &, const eckit::Configuration * const *);
  void ufo_aod_tlad_delete_f90(F90hop &);
  void ufo_aod_tlad_settraj_f90(const F90hop &, const F90goms &, const ioda::ObsSpace &);
  void ufo_aod_simobs_tl_f90(const F90hop &, const F90goms &, const ioda::ObsSpace &,
                             const int &, double &);
  void ufo_aod_simobs_ad_f90(const F90hop &, const F90goms &, const ioda::ObsSpace &,
                             const int &, const double &);
// -----------------------------------------------------------------------------

}  // extern C

}  // namespace ufo
#endif  // UFO_ATMOSPHERE_CRTM_OBSAODTLAD_INTERFACE_H_
