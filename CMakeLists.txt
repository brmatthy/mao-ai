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
        ai/util/GeneticSimulator.cpp
        ai/util/GeneticSimulator.h
        ai/LayCardSimulator.cpp
        ai/LayCardSimulator.h

        player/bot/Bot.cpp
        player/bot/Bot.h bench/SimpleBench.cpp bench/SimpleBench.h player/bot/ActBot.cpp player/bot/ActBot.h player/bot/PlayBot.cpp player/bot/PlayBot.h player/bot/MoveBot.cpp player/bot/MoveBot.h player/interfaces/MoveInterface.h player/interfaces/PlayInterface.h player/interfaces/ActInterface.h player/interfaces/CorrectionAccepter.h ai/ActAi/QActAI.cpp ai/ActAi/QActAI.h util/EnumToVector.cpp util/EnumToVector.h ai/q_learning/Qmodel.h util/util.cpp util/util.h)
