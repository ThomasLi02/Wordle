#include "model.hxx"
#include <catch.hxx>

TEST_CASE("example test (TODO: replace this)")
{
    CHECK(1 + 1 == 2);
}

//Testing to see if model.isWord works properly for "today" (line 15) and
// "happy"(line 16), but not for a space (line 18). Then upon level up (line
// 19), check 6 letter words.
TEST_CASE("CHECK ENGLISH WORD"){

    Model model;
    CHECK(model.isWord("today"));
    CHECK(model.isWord("happy"));
    CHECK(model.isWord(""));
    CHECK_FALSE(model.isWord(" "));
    model.levelUp();
    CHECK(model.isWord("coding"));
    CHECK(model.isWord("breach"));
    CHECK_FALSE(model.isWord("aaaaa"));
    CHECK_FALSE(model.isWord("aaaaaa"));
    CHECK_FALSE(model.isWord("aaa"));
    CHECK_FALSE(model.isWord("yesterday"));
}

//Check to see if model.evaluate_length is working properly. First,
//evaluate_length should be false (line 37) until the input is set to a 5
// letter word(line 38-40). Then, levelup (line 42) and check for 6 letter
// words (44-5).


TEST_CASE("Evaluate Length"){

    Model model;
    CHECK_FALSE(model.evaluate_length());
    model.set_input("today");
    CHECK(model.evaluate_length());
    model.set_input("today     ");
    CHECK(model.evaluate_length());
    model.levelUp();
    CHECK_FALSE(model.evaluate_length());
    model.set_input("coding     ");
    CHECK(model.evaluate_length());
    model.set_input("coding");
    CHECK(model.evaluate_length());
}

// Testing evaluate_word function for various test cases, including 5 or 4
// blank spaces at the end. This function should return y for letters in the
// wrong spot, g for letters in the right spot, and blank for wrong letters.
//

TEST_CASE("Evaluate Word"){

    Model model;
    model.set_input("fight     ");
    CHECK(model.evaluate_word() == "          ");
    model.set_input("          ");
    CHECK(model.evaluate_word() == "          ");
    model.set_input("APPLY     ");
    CHECK_FALSE(model.get_answer() == "apple     ");
    CHECK(model.evaluate_word() == "gggg      ");
    model.set_input("PLATE     ");
    CHECK(model.evaluate_word() == "yyy g     ");
}

//Testing a game that wins on the first try. Input is set to the correct
// answer (line 75), then add_boards is called (line 76) which will add
// input to color and word board. Then, check_win is called (line 77).

TEST_CASE("Run game that wins on first try"){
    Model model;
    model.set_input("APPLE     ");
    model.add_boards();
    CHECK(model.checkWin());
}

//Testing a game that wins on the third try. Input is set to the wrong answer
// twice(line 88 and 91), then add_boards is called (line 88 and 91), then,
// checkWin is called incorrectly twice. The correct answer is then called
// between lines 93-5.

TEST_CASE("Run game that wins on 3rd try"){
    Model model;
    model.set_input("APPLY     ");
    model.add_boards();
    CHECK_FALSE(model.checkWin());
    model.set_input("PAPER     ");
    model.add_boards();
    CHECK_FALSE(model.checkWin());
    model.set_input("APPLE     ");
    model.add_boards();
    CHECK(model.checkWin());
}


//Same test as previous, except this game calls the correct input on the last
// try (lines 119-22).

TEST_CASE("Run game that wins on Last try"){
    Model model;
    model.set_input("APPLY     ");
    model.add_boards();
    CHECK_FALSE(model.checkWin());
    model.set_input("APPLY     ");
    model.add_boards();
    CHECK_FALSE(model.checkWin());
    model.set_input("APPLY     ");
    model.add_boards();
    CHECK_FALSE(model.checkWin());
    model.set_input("APPLY     ");
    model.add_boards();
    CHECK_FALSE(model.checkWin());
    model.set_input("APPLY     ");
    model.add_boards();
    CHECK_FALSE(model.checkWin());
    model.set_input("APPLE     ");
    model.add_boards();
    CHECK(model.checkWin());
}

//Testing to see if checkWin is correctly FALSE (line 146) if all 6 tries are
// unsuccessful (lines 129-145).

TEST_CASE("Run game that Lose Game"){
    Model model;
    model.set_input("APPLY     ");
    model.add_boards();
    CHECK_FALSE(model.checkWin());
    model.set_input("APPLY     ");
    model.add_boards();
    CHECK_FALSE(model.checkWin());
    model.set_input("APPLY     ");
    model.add_boards();
    CHECK_FALSE(model.checkWin());
    model.set_input("APPLY     ");
    model.add_boards();
    CHECK_FALSE(model.checkWin());
    model.set_input("APPLY     ");
    model.add_boards();
    CHECK_FALSE(model.checkWin());
    model.set_input("APPLY     ");
    model.add_boards();
    CHECK_FALSE(model.checkWin());
}

//Testing the restart function in model (line 159). First, game is won (line
// 160), then restarted (161), then checks the answer is switched and input
// is set to empty and that the game is not won

TEST_CASE("Run game that wins and restarts and change answer"){
    Model model;
    model.set_input("APPLE     ");
    model.add_boards();
    CHECK(model.checkWin());
    model.restart();
    CHECK(model.get_answer() == "TODAY");
    CHECK(model.get_input() == "          ");
    CHECK_FALSE(model.checkWin());
}

//Check levelup function in model, levelUp is called (line 173) after a
// correct input (170-2). getLevel check (174) if set to 6, answer + input
// + checkWin checks (lines 177-9).

TEST_CASE("Run game that level up after correct guess"){
    Model model;
    model.set_input("APPLE     ");
    model.add_boards();
    CHECK(model.checkWin());
    model.levelUp();
    CHECK(model.getLevel() == 6);
    CHECK(model.get_answer() == "CODING");
    CHECK(model.get_input() == "          ");
    CHECK_FALSE(model.checkWin());
}





