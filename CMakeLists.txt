cmake_minimum_required(VERSION 3.23)
project(mao_ai)

set(CMAKE_CXX_STANDARD 14)

add_executable(mao_ai
        main.cpp game/card/ImmutableCard.cpp
        game/card/ImmutableCard.h
        game/card/CardDetail.cpp
        game/card/CardDetail.h
        game/action/Action.cpp
        game/action/Action.h
        player/Player.cpp
        player/Player.h
        game/Game.cpp
        game/Game.h

        game/action/Act.h
        game/validation/Correction.cpp
        game/validation/Correction.h
        game/validation/CorrectionStatus.h
        game/validation/PlayValidation.cpp
        game/validation/PlayValidation.h
        game/validation/ActValidation.cpp
        game/validation/ActValidation.h

        ai/util/NeuralNetwork.cpp
        ai/util/NeuralNetwork.h
        ai/util/GeneticAlgorithm.cpp
        ai/util/GeneticAlgorithm.h
        ai/util/GeneticAi.cpp
        ai/util/GeneticAi.h
        ai/util/Simulator.h
        ai/StaticLayCardSimulator.cpp
        ai/StaticLayCardSimulator.h
        
        player/bot.cpp
        player/bot.h ai/util/Algorithm.h ai/GameLayCardSimulator.cpp ai/GameLayCardSimulator.h ai/util/Ai.cpp ai/util/Ai.h ai/util/NeuralNetworkAi.cpp ai/util/NeuralNetworkAi.h)
