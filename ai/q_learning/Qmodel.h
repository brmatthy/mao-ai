//
// Created by brent on 20/10/22.
//

#ifndef MAO_AI_QMODEL_H
#define MAO_AI_QMODEL_H

#include <vector>
#include <algorithm>
#include "../../util/util.h"

template<class S, class A>
class Qmodel {
private:

    /**
     * The learning rate of the Q-model. In range [0,1].
     * If 0 nothing will be learned, if 1 no history will be remembered.
     */
    double _alpha;

    /**
     * Vector of states, the index of a state is used in the `_table` array as row index
     */
    const std::vector<S> _states;
    /**
     * Vector of actions, the index of an action is used in the `_table` array as column index
     */
    const std::vector<A> _actions;

    /**
     * The Q-table row and column indices match with those of `_states` and `_actions` respectively
     */
    double** _table;

    int getIndexOfState(const S& state) const;
    int getIndexOfAction(const A& action) const;

public:

    /**
     * Creates a Q-model. Takes the states and actions and allocates a 2d table for the probability's.
     * Make sure that the state and action class both overload the `operator==` for it will be used
     * when searching in the vector's.
     * @param states A vector containing all te required states
     * @param actions A vector containing all te required actions
     */
    Qmodel(std::vector<S> states, std::vector<A> actions, double alpha);

    /**
     * Deletes all the dynamically allocated space of this Q-model.
     */
    ~Qmodel();

    /**
     * Ask the Q-model if an action should be performed with a given state
     * @param state The state
     * @param action The action
     * @return `true` if the action should be performed, `false` otherwise
     */
    bool doAction(const S& state, const A& action) const;

    /**
     * Update a value in the Q-table, while neglecting any future influence
     * @see <a href="https://en.wikipedia.org/wiki/Q-learning#Algorithm">Q-learning algorithm</a>
     * @param state The state
     * @param action The action
     * @param r The reward
     */
    void valueUpdate(const S& state, const A& action, double r);

    /**
     * Update a value in the Q-table.
     * @see <a href="https://en.wikipedia.org/wiki/Q-learning#Algorithm">Q-learning algorithm</a>
     * @param state The state
     * @param action The action
     * @param r The reward
     * @param df The discount factor in range [0.1]
     * @param ofv The estimate of optimal future value
     */
    void valueUpdate(const S& state, const A& action, double r, double df, double ofv);

    /**
     * Get all the actions of this Q-table
     * @return A const reference to the action vector
     */
    const std::vector<A>& getActions();
};


/*
 * Template implementations
 */

template<class S, class A>
Qmodel<S, A>::Qmodel(std::vector<S> states, std::vector<A> actions, double alpha): _states(states), _actions(actions), _alpha(clamp(alpha, 0.0, 1.0)) {
    auto rows = states.size();
    _table = new double*[rows];
    for(int r = 0; r < rows; ++r){
        // init values at 0
        _table[r] = new double[actions.size()]{0};
    }
}

template<class S, class A>
Qmodel<S, A>::~Qmodel() {
    for(int r = 0; r < _states.size(); ++r){
        delete[] _table[r];
    }
    delete[] _table;
}



/*
 * Private functions
 */

template<class S, class A>
int Qmodel<S, A>::getIndexOfState(const S& state) const {
    auto begin = _states.begin();
    auto end = _states.end();
    auto it = std::find(begin, end, state);
    if(it == end){
        return -1;
    }
    return it - begin;
}

template<class S, class A>
int Qmodel<S, A>::getIndexOfAction(const A &action) const {
    auto begin = _states.begin();
    auto end = _states.end();
    auto it = std::find(begin, end, action);
    if(it == end){
        return -1;
    }
    return it - begin;
}


/*
 * Public functions
 */

template<class S, class A>
bool Qmodel<S, A>::doAction(const S &state, const A &action) const {
    return _table[getIndexOfState(state)][getIndexOfAction(action)] > 0;
}

template<class S, class A>
void Qmodel<S, A>::valueUpdate(const S &state, const A &action, double r) {
    valueUpdate(state, action, r, 0.0, 0.0);
}

template<class S, class A>
void Qmodel<S, A>::valueUpdate(const S &state, const A &action, double r, double df, double ofv) {
    df = clamp(df, 0.0, 0.1);
    int row = getIndexOfState(state);
    int col = getIndexOfAction(action);
    double oldVal = _table[row][col];
    _table[row][col] = oldVal + _alpha * (r + df * ofv - oldVal);
}

template<class S, class A>
const std::vector<A> &Qmodel<S, A>::getActions() {
    return _actions;
}

#endif //MAO_AI_QMODEL_H
