#include "model.hxx"

using namespace ge211;


Model::Model()
        : board_ {
                {' ',' ',' ',' ',' ', ' '},
                {' ',' ',' ',' ',' ', ' '},
                {' ',' ',' ',' ',' ', ' '},
                {' ',' ',' ',' ',' ', ' '},
                {' ',' ',' ',' ',' ', ' '},
                {' ',' ',' ',' ',' ', ' '}
                },
          board_color {
                  {' ',' ',' ',' ',' ', ' '},
                  {' ',' ',' ',' ',' ', ' '},
                  {' ',' ',' ',' ',' ', ' '},
                  {' ',' ',' ',' ',' ', ' '},
                  {' ',' ',' ',' ',' ', ' '},
                  {' ',' ',' ',' ',' ', ' '}
          }

{}


//update input to color board and board and increment row
void
Model::add_boards(){
    add_color_board();
    add_word_board();
    set_row(get_row()+1);
}


//resets all boards, input, row, and changes the answer
void
Model:: restart() {
    set_input("          ");
    emptyBoards();
    set_row(0);
    change_answer();
}


//checks if the input is an actual English word
bool
Model::isWord(std::string x) const
{
    if(level == 5){
        std::ifstream words;
        words = ge211::open_resource_file("words.txt");
        std::string line;
        while(getline(words, line ))
        {
            if(line.find(x) != std::string::npos)
            {
                words.close();
                return true;
            }
        }
        words.close();
        return false;
    }
    else{
        std::ifstream words;
        words = ge211::open_resource_file("newwords.txt");
        std::string line;
        while(getline(words, line ))
        {
            if(line.find(x) != std::string::npos)
            {
                words.close();
                return true;
            }
        }
        words.close();
        return false;

    }

}


//given row, return the string corresponding to that row
std::string
Model:: getString (int r) const{
    int i;
    std::string s = "";
    for (i = 0; i < level; i++) {
        s = s + board_[r][i];
    }
    return s;
}


//changes the answer to another word
void
Model::change_answer(){
    if(level == 5){
        answer = "TODAY";
    }
    else{
        if(answer == "CODING"){
            answer = "PLAYER";
        }
        else{
            answer = "CODING";
        }
    }

}


//finds the length of our input
//because we need input to be string of length 10
//we subtract the number of empty space from the lenght of the string
bool
Model::evaluate_length()const{
    int count = 0;
    for (int i =0; i <int(input.length()); i++){
        if (input[i] == ' '){
            count += 1;
        }
    }
    return int(input.length()) - count ==level;
}

//Returns the 'gy ' string of a word
std::string
Model:: evaluate_word() const{
    std::string ret= "";
    for (int i = 0; i < int(input.length()); i++) {
        if (input[i] == answer[i]) {
            ret += 'g';
        }
        //check whether the letter is in the answer
        else if(answer.find(input[i]) != std::string::npos) {
            ret+='y';
        }
        else{
            ret +=' ';
        }
    }
    return ret;
}

//check the player has won, by checking latest input and matching with
// the answer
bool
Model:: checkWin() const {
    return getString(row-1) == answer.substr(0, level);
}

//EVERYTHING BELOW IS PRIVATE

//if length is correct return the 'gy ' string else, return an erro
std::string
Model:: check(){
    if (!evaluate_length()){
        return "Not 5 characters";
    }
    else{
        return evaluate_word();
    }
}

//add input to board
void
Model:: add_word_board(){
    std::string x = check();
    if (x.compare("Not 5 characters") == 0){
        return ;
    }
    std::string the_word = get_input();
    for (int j = 0; j < level; ++j){
        board_[row][j] = the_word[j];
    }

}

//add input to color board
void
Model:: add_color_board(){
    std::string x = check();
    if (x.compare("Not 5 characters") == 0){
        set_row(get_row()-1);
        return ;
    }
    for (int j = 0; j < level; j++){
        board_color[row][j] = x[j];
    }

}

//reset the boards to space string
void
Model:: emptyBoards(){
    for (int i = 0; i<6;i++){
        for (int j = 0; j < level; j++){
            board_[i][j] = ' ';
            board_color[i][j] = ' ';
        }
    }
}

