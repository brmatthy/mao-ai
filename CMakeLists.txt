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

        ai/util/NeuralNetworkSimulator.h
        ai/PlayAi/StaticLayCardSimulator.cpp
        ai/PlayAi/StaticLayCardSimulator.h
        
        ai/util/Algorithm.h
        ai/PlayAi/GameLayCardSimulator.cpp
        ai/PlayAi/GameLayCardSimulator.h
        ai/util/Ai.cpp
        ai/util/Ai.h
        ai/util/NeuralNetworkAi.cpp
        ai/util/NeuralNetworkAi.h
        player/bot/Bot.cpp
        player/bot/Bot.h
        bench/SimpleBench.cpp
        bench/SimpleBench.h
        player/bot/ActBot.cpp
        player/bot/ActBot.h
        player/bot/PlayBot.cpp
        player/bot/PlayBot.h
        player/bot/MoveBot.cpp
        player/bot/MoveBot.h
        player/interfaces/MoveInterface.h
        player/interfaces/PlayInterface.h
        player/interfaces/ActInterface.h
        player/interfaces/CorrectionAccepter.h
        ai/ActAi/QActAI.cpp
        ai/ActAi/QActAI.h
        util/EnumToVector.cpp
        util/EnumToVector.h
        ai/q_learning/Qmodel.h
        util/util.cpp
        util/util.h
        game/action/Act.cpp

        ai/q_learning/states/NCards.cpp
        ai/q_learning/states/NCards.h
        ai/q_learning/states/GlobalNstate.cpp
        ai/q_learning/states/GlobalNstate.h
        ai/q_learning/states/AllStatesFactory.cpp
        ai/q_learning/states/AllStatesFactory.h

        player/bot/neverfinish/NeverFinishMoveBot.cpp
        player/bot/neverfinish/NeverFinishMoveBot.h
        player/bot/neverfinish/NeverFinishBot.cpp
        player/bot/neverfinish/NeverFinishBot.h

        ai/util/Simulator.h
        ai/PlayAi/NeuralNetworkPlayAi.cpp
        ai/PlayAi/NeuralNetworkPlayAi.h
        ai/ActAi/QActTrainer.cpp
        ai/ActAi/QActTrainer.h
        ai/PlayAi/QPlayAI.cpp
        ai/PlayAi/QPlayAI.h
        ai/PlayAi/QPlayTrainer.cpp
        ai/PlayAi/QPlayTrainer.h
        data/FaultsToJson.cpp
        data/FaultsToJson.h
        ai/MoveAi/QMoveTrainer.h
        ai/MoveAi/QMoveAi.cpp
        ai/MoveAi/QMoveTrainer.cpp
        ai/ActAi/NeuralNetworkActAi.h
        ai/ActAi/NeuralNetworkActAi.cpp
        ai/ActAi/GameActSimulator.h
        ai/ActAi/GameActSimulator.cpp
        ai/PlayAi/StateActPredictQPlayAI.cpp
        ai/PlayAi/StateActPredictQPlayAI.h
        ai/PlayAi/CombinedQPlayAI.cpp
        ai/PlayAi/CombinedQPlayAI.h
        ai/PlayAi/ActPredictQPlayAI.cpp
        ai/PlayAi/ActPredictQPlayAI.h
        ai/ComboAi/QComboTrainer.h ai/ComboAi/QComboTrainer.cpp util/Color.h)
