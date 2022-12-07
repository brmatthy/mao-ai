// Created by mats on 31/10/22.

#pragma once

class Ai {
private:
    int _faults = 0;
    int _turns = 0;
public:
    /**
     * Correct a mistake from the AI
     */
    void incrementFaults();

    /**
     * Count the amount of actions of an ai
     */
    void incrementTurns();

    /**
     * See the number off faults of the AI
     * @return the amount of faults
     */
    int faults() const;

    /**
     * See the number of turns of the AI
     * @return The amount of turns
     */
    int turns() const;

    /**
     * Get the faults relative to the amount of turns
     * @return _faults/_turns
     */
    double relativeFaults() const;

    /**
     * Clean the Ai for a new simulation
     */
    void clean();
};
