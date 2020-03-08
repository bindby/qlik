#include "Tester.h"

Tester::Tester()
{

}

void Tester::testSingleEvaulator(string sample, Evaluator::DIFFICULTY expectedDifficulty) {
    Sudoku sudoku;
    Evaluator evaluator(sudoku);
    NcursesPresenter presenter("testSingleEvaulator");
    if (!sudoku.fromString(sample)) {
        presenter.printError("could not parse sudoku");
        exit(1);
    }
    if ( evaluator.getDifficulty() != expectedDifficulty) {
        presenter.printError("changed evaluation");
        exit(1);
    }
    presenter.printSudoku(sudoku);
    presenter.waitForKeyPress();
}

void Tester::testEvaulator() {
    testSingleEvaulator(EASY_SAMPLE, Evaluator::Easy);
    testSingleEvaulator(MEDIUM_SAMPLE, Evaluator::Medium);
    testSingleEvaulator(SAMURAI_SAMPLE, Evaluator::Samurai);
}

void Tester::testSingleCandidate(string sample, int expectedIterations) {
    Sudoku sudoku;
    Evaluator evaluator(sudoku);
    NcursesPresenter presenter("testSingleCandidate");
    if (!sudoku.fromString(sample)) {
        presenter.printError("could not parse sudoku");
        exit(1);
    }
    CandidateSolver solver(sudoku, evaluator, presenter);
    solver.solve(true);
    if ( solver.getIterations() != expectedIterations) {
        presenter.printError("changed performance");
        exit(1);
    }
    presenter.waitForKeyPress();
}

void Tester::testSingleBrute(string sample, int expectedIterations) {
    Sudoku sudoku;
    Evaluator evaluator(sudoku);
    NcursesPresenter presenter("testSingleBrute");
    if (!sudoku.fromString(sample)) {
        presenter.printError("could not parse sudoku");
        exit(1);
    }
    BruteSolver solver(sudoku, evaluator, presenter);
    solver.solve(true);
    if ( solver.getIterations() != expectedIterations) {
        presenter.printError("changed performance");
        exit(1);
    }
    presenter.waitForKeyPress();
}

void Tester::testSolve() {
    testSingleCandidate(EASY_SAMPLE, 0);
    testSingleCandidate(MEDIUM_SAMPLE, 101380);
    testSingleCandidate(HARD_SAMPLE, 2020011);
    testSingleCandidate(SAMURAI_SAMPLE, 300688);
    testSingleBrute(EASY_SAMPLE, 180955);
    testSingleBrute(MEDIUM_SAMPLE, 1466722);
    testSingleBrute(HARD_SAMPLE, 11589484);
    testSingleBrute(SAMURAI_SAMPLE, 4688707);
}

void Tester::testFromFile() {
    Sudoku sudoku;
    Evaluator evaluator(sudoku);
    NcursesPresenter presenter("testFromFile");
    if (!sudoku.fromFile("./fixtures/sudoku2.sud")) {
        presenter.printError("could not read sudoku file");
        exit(1);
    }
    CandidateSolver solver(sudoku, evaluator, presenter);
    if (!solver.solve(true)) {
        presenter.printError("could not solve sudoku");
        exit(1);
    }
    presenter.waitForKeyPress();
}

void Tester::testCreate() {
    Sudoku sudoku;
    Evaluator evaluator(sudoku);
    NcursesPresenter presenter("testCreate");
    CandidateSolver solver(sudoku, evaluator, presenter);
    SeedCreator creator(sudoku, evaluator, presenter, solver);
    creator.create(Evaluator::Samurai);
    presenter.waitForKeyPress();
}
