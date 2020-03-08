#include "globals.h"
#include "Tester.h"
#include <map>

void usage() {
    string usage =
      "Usage: qlik_sudoku test<scope>\n"
      "       where scope in [solve,create,file,all]\n"
      "or:    qlik_sudoku solve <filepath>\n"
      "or:    qlik_sudoku create <difficulty>\n"
      "       where difficulty in [easy,medium,hard,samurai]\n"
      "\n"
      "Examples:\n"
      "\n"
      "./qlik_sudoku testAll\n"
      "./qlik_sudoku solve ./fixtures/sudoku1.sud\n"
      "./qlik_sudoku create hard\n";

    cout << usage << endl;
}

void test(string scope) {
    if (0 == scope.compare("testEvaluator")) {
        Tester::testEvaulator();
    } else if (0 == scope.compare("testSolve")) {
        Tester::testSolve();
    } else if (0 == scope.compare("testCreate")) {
        Tester::testCreate();
    } else if (0 == scope.compare("testFile")) {
        Tester::testFromFile();
    } else if (0 == scope.compare("testAll")) {
        Tester::testEvaulator();
        Tester::testSolve();
        Tester::testCreate();
        Tester::testFromFile();
    }
}

void solve(string file) {
    map<Evaluator::DIFFICULTY, string> difficulties = {{ Evaluator::Easy, "easy"},
                                                       {Evaluator::Medium, "medium"},
                                                       {Evaluator::Hard, "hard"},
                                                       {Evaluator::Samurai, "samurai"}};
    Sudoku sudoku;
    Evaluator evaluator(sudoku);
    string title = "Solving sudoku from file: ";
    title.append(file);
    NcursesPresenter presenter(title);
    if (!sudoku.fromFile(file)) {
        presenter.printError("could not read sudoku file");
        exit(1);
    }
    CandidateSolver solver(sudoku, evaluator, presenter);
    if (!solver.solve(true)) {
        presenter.printError("could not solve sudoku with unique solution");
        exit(1);
    } else {
        string info = "Approximate difficulty level: ";
        info.append(difficulties[evaluator.getDifficulty()]);
        presenter.extraInfo(info);
    }
    presenter.waitForKeyPress();

}

void create(string difficulty) {
    map<string, Evaluator::DIFFICULTY> difficulties = {{"easy", Evaluator::Easy},
                                                       {"medium", Evaluator::Medium},
                                                       {"hard", Evaluator::Hard},
                                                       {"samurai", Evaluator::Samurai}};
    Sudoku sudoku;
    Evaluator evaluator(sudoku);
    string title = "Creating a sudoku with difficulty level: ";
    title.append(difficulty);
    NcursesPresenter presenter(title);
    CandidateSolver solver(sudoku, evaluator, presenter);
    SeedCreator creator(sudoku, evaluator, presenter, solver);
    creator.create(difficulties[difficulty]);
    presenter.waitForKeyPress();
}

int main(int argc,char* argv[])
{
    cout << "Qlik Sudoku assignment, implmentation by John Bindby" << endl << endl;
    if(1==argc) {
        usage();
    } else if (2==argc){
        test(argv[1]);
    } else if (3==argc){
        if (0 == strcmp(argv[1], "solve")) {
            solve(argv[2]);
        }
        if (0 == strcmp(argv[1], "create")) {
            create(argv[2]);
        }
    }
    cout << endl;
    return 0;
}

