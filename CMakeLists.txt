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
        game/action/Act.h game/validation/Correction.cpp game/validation/Correction.h game/validation/CorrectionStatus.h game/validation/PlayValidation.cpp game/validation/PlayValidation.h game/validation/ActValidation.cpp game/validation/ActValidation.h player/bot.cpp player/bot.h)
