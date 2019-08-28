/*
 * (C) Copyright 2019 UCAR
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 */

#include "ufo/obsfunctions/ObsFunction.h"

#include "ioda/ObsDataVector.h"
#include "oops/base/Variables.h"

namespace ufo {

// -----------------------------------------------------------------------------

ObsFunction::ObsFunction(const std::string & id)
  : obsfct_(ObsFunctionFactory::create(id))
{}

// -----------------------------------------------------------------------------

ObsFunction::~ObsFunction() {}

// -----------------------------------------------------------------------------

void ObsFunction::compute(const ioda::ObsDataVector<float> & metadata,
                      const ioda::ObsDataVector<float> & obs,
                      ioda::ObsDataVector<float> & out) const {
  obsfct_->compute(metadata, obs, out);
}

// -----------------------------------------------------------------------------

const oops::Variables & ObsFunction::requiredObsData() const {
  return obsfct_->requiredObsData();
}

// -----------------------------------------------------------------------------

const oops::Variables & ObsFunction::requiredMetaData() const {
  return obsfct_->requiredMetaData();
}

// -----------------------------------------------------------------------------

}  // namespace ufo