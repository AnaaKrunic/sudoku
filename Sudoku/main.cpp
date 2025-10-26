#include "game.h"
#include <ctime>

int main(int argc, char* argv[]) {
    srand(static_cast<unsigned>(time(0)));
    if (argc < 3) {
        std::cerr << "Nije uneto dovoljno argumenata" << std::endl;
        return 1;
    }
    
    SudokuGame game(9, 35);

    game.setInputFileName(argv[2]);
    game.setOutputFileName(argv[1]);

    game.playGame();

    return 0;
}