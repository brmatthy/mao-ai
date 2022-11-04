// Created by mats on 31/10/22.

#pragma once

class Ai {
private:
    int _faults = 0;
public:
    /**
     * Correct a mistake from the AI
     */
    void incrementFaults();

    /**
     * See the number off faults of the AI
     * @return the amount of faults
     */
    int faults() const;

    /**
     * Clean the Ai for a new simulation
     */
    void clean();
};
