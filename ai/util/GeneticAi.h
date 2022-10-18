//
// Created by mats on 12/10/22.
//

#ifndef MAO_AI_GENETICAI_H
#define MAO_AI_GENETICAI_H

#include <string>
#include "../../game/validation/Correction.h"

class GeneticAi {
protected:
    int _faults;
    double* _weights;
    int _size;
public:
    /**
     * Create a new geneticAi, weights are set randomly
     * @param size the size of the weights array
     */
    GeneticAi(int size);

    /**
     * Create a new genetic AI with starting weights
     * @param weights starting weights (do not need to delete)
     * @param size the weights size
     */
    GeneticAi(double* weights, int size);

    /**
     * Delete the geneticAI
     */
    ~GeneticAi();

    /**
     * Correct a mistake from the AI
     */
    virtual void correct(Correction* correction);

    /**
     * See the number off faults of the AI
     * @return the amount of faults
     */
    virtual int faults();

    /**
     * Clean the Ai for a new simulation
     */
    virtual void clean();

    /**
     * Crossover with another AI
     * @param other the other AI to crossover with
     * @return a new GeneticAI
     */
    GeneticAi* crossover(GeneticAi* other);

     /**
      * Mutate the AI slightly
      */
     virtual void mutate();

     /**
      * Get the Ai weights
      * @return the weights as a double array
      */
     virtual double* getWeights();

     /**
      * Get the Ai weight size
      * @return the ai weight size
      */
     virtual int getSize();

     /**
      * Prints the AI state (weights) as a string representing the weights array
      * @param out the output stream to write to.
      */
     virtual void print(std::ostream& out);
};


#endif //MAO_AI_GENETICAI_H
