//
// Created by brent on 5/10/22.
//

#include "Correction.h"

#include <utility>

Correction::Correction(CorrectionStatus status, const Action *action, std::vector<Act> correctActs) :_status(status), _action(action), _correctActs(std::move(correctActs)){}
