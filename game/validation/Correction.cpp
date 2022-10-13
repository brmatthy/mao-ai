//
// Created by brent on 5/10/22.
//

#include "Correction.h"

#include <utility>

Correction::Correction(CorrectionStatus status, const Action *action) :_status(status), _action(action) {}
