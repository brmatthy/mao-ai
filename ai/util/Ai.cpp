// Created by mats on 31/10/22.

#include "Ai.h"

void Ai::clean()
{
    _faults = 0;
    _turns = 0;
}

void Ai::incrementFaults()
{
    ++_faults;
}

int Ai::faults() const
{
    return _faults;
}

void Ai::incrementTurns() {
    ++_turns;
}

double Ai::relativeFaults() const {
    return ((double) _faults)/ ((double)_turns);
}

int Ai::turns() const {
    return _turns;
}
