// Created by mats on 03/11/22.

#pragma once

template <class T>
class Simulator {
public:
    /**
     * Creat a Simulator to simulate games for a single Ai
     */
    Simulator() = default;

    virtual ~Simulator() = default;

    /**
     * Simulate a game for a single AI, and do the incrementFaults corrections
     * @param ai the ai for which to simulate.
     */
    virtual void simulate(T* ai) = 0;
};
