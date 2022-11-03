//
// Created by mats on 19/10/22.
//

#ifndef MAO_AI_ALGORITHM_H
#define MAO_AI_ALGORITHM_H

class Algorithm {
public:
    virtual ~Algorithm() = default;
    /**
     * Simulate n iterations of the network
     * @param iterations number of iterations
     */
    virtual void execute(int iterations) = 0;
};

#endif //MAO_AI_ALGORITHM_H
