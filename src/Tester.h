#ifndef TESTER_H
#define TESTER_H

#include "Sudoku.h"
#include "AbstractPresenter.h"
#include "Evaluator.h"
#include "BruteSolver.h"
#include "CandidateSolver.h"
#include "Ncursespresenter.h"
#include "SeedCreator.h"

#define EASY_SAMPLE "51.....838..416..5..........985.461....9.1....642.357..........6..157..478.....96"
#define MEDIUM_SAMPLE "7...9...32..468..1..8...6...4..2..9....3.4....8..1..3...9...7..5..142..68...5...2"
#define HARD_SAMPLE ".523..6..6...4...3............63..1.47.....35.2..58............1...9...6..5..172."
#define SAMURAI_SAMPLE "5.....1.7..43..5.....2...8..9.4.2...4.......6...1.3.5..8...4.....2..67..3.9.....1"

class Tester
{
private:
    static void testSingleCandidate(string sample, int expectedIterations);
    static void testSingleBrute(string sample, int expectedIterations);
    static void testSingleEvaulator(string sample, Evaluator::DIFFICULTY expectedDifficulty);

public:
    Tester();
    static void testSolve();
    static void testCreate();
    static void testEvaulator();
    static void testFromFile();
};

#endif // TESTER_H
