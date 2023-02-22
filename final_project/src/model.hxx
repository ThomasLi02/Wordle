/*************************************************/
/*** DO NOT CHANGE THE PUBLIC API IN THIS FILE ***/
/*************************************************/
//
// You may add private members if you like, or even remove
// the private helper functions, but you mustn't change the
// existing public members, nor add new ones. If you do, your
// code may not build for automated tests.

#pragma once

#include <ge211.hxx>

#include <iostream>
#include <fstream>
#include <vector>

// Represents the state of the Reversi game.
class Model
{
public:
    /***************************************************/
    /*** DON'T CHANGE ANYTHING IN THE PUBLIC SECTION ***/

    Model();


    int get_row() const{
        return row;
    }

    void set_row(int to){
        row = to;
    }

    char get_char(int i , int j) const{
        return board_[i][j];
    }
    char get_color(int i, int j) const{
        return board_color[i][j];
    };

    std::string get_input() const{
        return input;
    }
    std::string
    get_answer() const{
        return answer;
    }
    void
    change_answer();

    void set_input(std::string new_input) {
        input = new_input;
    }


    bool
    evaluate_length()const;


    std::string
    evaluate_word() const;
    void
    add_boards();

    void
    restart();

    bool
    isWord(std::string x)const;

    std::string
    getString (int r) const;

    int getLevel()const{
        return level;
    }
    void levelUp(){
        level = 6;
        restart();
    }

    bool checkWin() const;





#ifdef CS211_TESTING
    // When this class is compiled for testing, members of a struct named
    // Test_access will be allowed to access private members of this class.
    friend struct Test_access;
#endif

private:
    char board_[6][6];
    char board_color[6][6];

    /**********************************************/
    /*** DO NOT CHANGE ANYTHING ABOVE THIS LINE ***/
    /**********************************************/
    //
    // You may add or change anything you like below this point.
    //

    //
    // PRIVATE HELPER FUNCTIONS
    //
    // Implementing these first is a very good idea.
    //

    std::string input = "          ";
    std::string answer = "APPLE";
    int level = 5;
    int row = 0;


    std::string
    check();

    void add_word_board();

    void add_color_board();

    void
    emptyBoards();
};