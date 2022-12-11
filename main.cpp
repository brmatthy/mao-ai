// Created by brent on 1/10/22.

#include <iostream>
#include "ai/ActAi/QActTrainer.h"
#include "ai/PlayAi/QPlayTrainer.h"
#include "ai/MoveAi/QMoveTrainer.h"
#include "ai/ComboAi/QComboTrainer.h"

int main(){
    auto trainer = QComboTrainer(0.1, 4);

    std::cout << "Starting training on 10.000 games" << std::endl;
    time_t start = time(nullptr);


    trainer.execute(10000);
    trainer.setPrintState(true);

    std::cout << "Training on 10.000 games finished after " << time(nullptr) - start << " seconds" << std::endl;
    std::cout << "Press enter to play 1 game: ";

    while (std::cin.get()){
        std::cout << std::endl;
        trainer.execute(1);
        std::cout << "Press enter to play 1 game: ";
    }
}


