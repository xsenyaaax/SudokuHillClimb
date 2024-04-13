//
// Created by senyaaa on 4/12/2024.
//
#include "HillClimb.hpp"

/**
 * @param state filled sudoku board
 * @return number of collision in this state
 */
int HillClimb::calculateScore(const SudokuBoard &state) const{
    int score = 0;
    size_t boardSize = state.board.size();

    for (size_t i = 0; i < boardSize; ++i){
        std::vector<bool> rowCheck(boardSize + 1, false);
        std::vector<bool> colCheck(boardSize + 1, false);

        for (size_t j = 0; j < boardSize; ++j) {
            // rows
            if (state.board[i][j] != 0 && rowCheck[state.board[i][j]]) {
                score++;
            }
            rowCheck[state.board[i][j]] = true;

            // columns
            if (state.board[j][i] != 0 && colCheck[state.board[j][i]]) {
                score++;
            }
            colCheck[state.board[j][i]] = true;
        }
    }

    // check subgrids
    int subgridSize = std::sqrt(boardSize);
    for (size_t i = 0; i < boardSize; i += subgridSize) {
        for (size_t j = 0; j < boardSize; j += subgridSize) {
            std::vector<bool> subgridCheck(boardSize + 1, false);

            for (size_t k = i; k < i + subgridSize; ++k) {
                for (size_t l = j; l < j + subgridSize; ++l) {
                    if (state.board[k][l] != 0 && subgridCheck[state.board[k][l]]) {
                        score++;
                    }
                    subgridCheck[state.board[k][l]] = true;
                }
            }
        }
    }

    return score;
}

bool operator<(const std::pair<int, SudokuBoard>& lhs, const std::pair<int, SudokuBoard>& rhs) {
    return lhs.first > rhs.first;
}

/**
 * Initiliazes games with some random solution in the beginning, then iterates through neighbors, calculates score and restarts if neccesary
 * @return return true, idk why, function could be void
 */
bool HillClimb::climb() {
    SudokuBoard currentState = board;
    generateStartingState(currentState);
    int currentScore = calculateScore(currentState);

    int numberOfRestarts = 0;
    int iterations = 0;
    const int maxIterations = 10000;

    while (true){
        SudokuBoard neighbor = currentState;
        neighborGenerator->generatorNeighbor(neighbor);

        int neighborScore = calculateScore(neighbor);

        if (neighborScore == 0){
            std::cout<< "Solved: "<< numberOfRestarts << " restarts" << std::endl;
            return true;
        }

        if (neighborScore < currentScore){
            currentState  = neighbor;
            currentScore = neighborScore;
        }else {
            iterations++;
            if (iterations >= maxIterations) {
                currentState = board;
                generateStartingState(currentState);
                currentScore = calculateScore(currentState);
                numberOfRestarts++;
                iterations = 0;
            }
        }
    }
}
/**
 * Generates random starting game state, does not take into account same numbers in row/columns
 * @param sudokuBoard
 */
void HillClimb::generateStartingState(SudokuBoard & sudokuBoard) {
    size_t boardSize = board.getBoardSize();
    std::random_device rd;
    std::mt19937 gen(rd());

    for (size_t i = 0; i < boardSize; ++i) {
        for (size_t j = 0; j < boardSize; ++j) {
            if (sudokuBoard.board[i][j] != 0) continue;
            std::uniform_int_distribution<int> dist(1, boardSize);
            int num = dist(gen);
            sudokuBoard.board[i][j] = num;
        }
    }
}
/*
 * Constructor. NeighborGenerator is using polymorphism so it could be easily called by one function.
 */
HillClimb::HillClimb(SudokuBoard &sudokuBoard, int neighborGenChoice) : board(sudokuBoard){
    switch(neighborGenChoice){
        case 0:
            neighborGenerator = std::make_unique<RandPosFill>();
            break;
        case 1:
            neighborGenerator = std::make_unique<BestPosFill>();
            break;
        case 2:
            neighborGenerator = std::make_unique<SwapTwoRandom>();
            break;
        default:
            throw std::invalid_argument("Wrong input");
    }
}


