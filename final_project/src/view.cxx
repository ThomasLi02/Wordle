#include "view.hxx"

// Convenient type aliases:
using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;
static int const grid_size = 36;
static Color const square_color =
        Color::white().blend(0.5,Color::black());
static Color const green_color = Color::medium_green();
static Color const yellow_color = Color::medium_yellow();
static Color const rect_color = Color::medium_cyan();
static int const square_side = 40;

View::View(Model const& model)
        : model_(model),
        square_sprite_ {{square_side, square_side}, square_color},
        yellow_square_ {{square_side, square_side}, yellow_color},
        green_square_ {{square_side, square_side}, green_color},
        rect_sprite_{{square_side*5, square_side}, rect_color},
        inputString{"", sans30},
        enterString{"Your answer", sans30},
        loseString{"Lose:( Press 1 to restart", sans30},
        continueString1{"Win! Press 1 to restart", sans30},
        continueString2{"press 2 to level up",sans30},
        quitString{"Press 0 to quit", sans30},
        notEnough{"Wrong # of Characters", sans30},
        notWord{"Not English Word", sans30}
{ }

void View::draw(Sprite_set& set)
{

    //position for input box
    Position playerInput (70,450);
    //position for the phrase above input box
    Position enter (70, 400);
    //position for "press 1 to restart"
    Position cont (10, 300);
    //position for "press 2 to level up"
    Position cont2 (10, 350);

    set.add_sprite(rect_sprite_, playerInput, 1);
    setInput(model_.get_input().c_str());
    set.add_sprite(inputString ,playerInput, 2);
    set.add_sprite(enterString ,enter, 2);

    //position of top left box; initial box
    int boxX = 15;
    int boxY = 40;

    //loop through board
    for(int i = 0; i < 6; i++)
    {
        for (int j = 0; j < model_.getLevel(); j++) {
            //move downwards by 50 per letter
            int y = boxX + 50 * i;
            //move right by 60 per letter
            int x = boxY + 60 * j;
            Position boxPos (x,y);
            //first add empty box sprites
            set.add_sprite(square_sprite_, boxPos, 0);
            if (model_.get_color(i, j) == 'g'){
                //if color board is g, make box green
                set.add_sprite(green_square_, boxPos, 1);
            }
            else if(model_.get_color(i, j) == 'y'){
                //make box yellow if yellow
                set.add_sprite(yellow_square_, boxPos, 1);
            }
            //this block will add all characters in our board matrix
            //and put it on the boxes in UI
            //got it from the Tic Tac source code
            ge211::Text_sprite::Builder letter_builder(sans30);
            letter_builder << model_.get_char(i, j);
            character[i][j].reconfigure(letter_builder);
            set.add_sprite(character[i][j], boxPos,2);

            //getString returns the string of the given row
            //this if checks the string == answer
            if (model_.checkWin()){
                //if equal, add the continue text Sprite that asks
                //if the user wants to restart again
                set.add_sprite(continueString1, cont, 2);
                if (model_.getLevel() == 5){
                    //if the level is for 5-letter words, then will prompt
                    //user if he wants to try 6-letter word
                    set.add_sprite(continueString2, cont2, 2);
                }
                if (model_.getLevel() == 6){
                    set.add_sprite(quitString, cont2, 2);
                }
            }
            else{
                //Checks if string satisfies length and english word
                std::string data = model_.get_input();
                //this line changes data (the input) to lower case to test
                // against words.txt
                for (int i =0; i < int(data.length()); i++){
                    data[i] = tolower(data[i]);
                }
                //check length
                if(data.length()>0 && model_.get_row()!=6 && !model_
                .evaluate_length()){
                    set.add_sprite(notEnough, cont, 1);
                }
                else if (model_.get_row()!=6 &&
                !model_.isWord(data.substr(0,model_.getLevel()))){
                    //check english word
                    set.add_sprite(notWord, cont, 1);
                }
            }
            //if the user reached the end and didn't pass
            if (model_.get_row()==6 && !model_.checkWin()){
                set.add_sprite(loseString, cont, 2);
                set.add_sprite(quitString, cont2, 2);
            }
        }
    }

}


View::Dimensions
View::initial_window_dimensions() const
{
    // You can change this if you want:
    return grid_size * Dimensions(12,15);

}

std::string
View::initial_window_title() const
{
    // You can change this if you want:
    return "Wordle";
}
//changes the inputString Text sprite
void
View:: setInput(std::string x){
    inputString = {x, sans30};
}


