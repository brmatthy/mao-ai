//
// Created by brent on 21/10/22.
//

#ifndef MAO_AI_UTIL_H
#define MAO_AI_UTIL_H

template<class T>
constexpr T clamp( const T& v, const T& lo, const T& hi );

template<class T>
constexpr T clamp( const T& v, const T& lo, const T& hi )
{
    if(v < lo){ // too low
        return lo;
    }
    if(v <= hi){ // in range
        return v;
    } // too high
    return hi;
}

#endif //MAO_AI_UTIL_H
