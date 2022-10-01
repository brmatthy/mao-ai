cmake_minimum_required(VERSION 3.23)
project(mao_ai)

set(CMAKE_CXX_STANDARD 14)

add_executable(mao_ai
        main.cpp game/card/ImmutableCard.cpp game/card/ImmutableCard.h game/card/CardDetail.cpp game/card/CardDetail.h)
