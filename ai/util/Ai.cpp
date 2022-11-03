// Created by mats on 31/10/22.

#include "Ai.h"

void Ai::clean()
{
    _faults = 0;
}

void Ai::correct()
{
    ++_faults;
}

int Ai::faults() const
{
    return _faults;
}
