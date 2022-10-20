//
// Created by brent on 20/10/22.
//

#ifndef MAO_AI_QMODEL_H
#define MAO_AI_QMODEL_H

#include <vector>
#include <algorithm>

template<class S, class A>
class Qmodel {
private:
    /**
     * Vector of states, the index of a state is used in the `_table` array as row index
     */
    std::vector<S> _states;
    /**
     * Vector of actions, the index of an action is used in the `_table` array as column index
     */
    std::vector<A> _actions;

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
    Qmodel(std::vector<S> states, std::vector<A> actions);

    /**
     * Deletes all the dynamically allocated space of this Q-model.
     */
    ~Qmodel();

};


/*
 * Template implementations
 */

template<class S, class A>
Qmodel<S, A>::Qmodel(std::vector<S> states, std::vector<A> actions): _states(states), _actions(actions) {
    int rows = states.size();
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

#endif //MAO_AI_QMODEL_H
