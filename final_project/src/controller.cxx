#include "controller.hxx"


Controller::Controller()
        : model_(),
          view_(model_)
{ }


void
Controller::on_key(ge211::Key key)
{

    //quit on 0
    if (key == ge211::Key::code('0')) {
        quit();
    }

    //restart on 1
    if (key == ge211::Key::code('1')) {
        //set everything to default
        model_.restart();
    }

    //level up on 2
    if (key == ge211::Key::code('2')) {
        //make the board 6 by 6
        model_.levelUp();

    }

    // \r is enter key we think
    // add to board on enter
    if (key == ge211::Key::code('\r')) {
        std::string data = model_.get_input();
        for (int i =0; i < int(data.length()); i++){
            data[i] = tolower(data[i]);
        }
        if(model_.isWord(data.substr(0,model_.getLevel())) ){
            model_.add_boards();
            model_.set_input("          ");
        }

    }
    //change the input on any alphabetical key
    if (isalpha(key.code()))
    {
        //add the key to model string
        std::string s = "          ";
        std::string inp = model_.get_input();
        int count = 0;
        for (int i =0; i <int(inp.length()); i++){
            if (inp[i] == ' '){
                count += 1;
            }
        }
        int num = inp.length() - count;
        std::string r = inp.substr(0, num);
        char letter = char(toupper(key.code()));
        r += letter;
        r.append(s.substr(num+1));
        model_.set_input(r);

    }

    //pops last character on backspace
    if (key == ge211::Key::code('\b')){
        // delete previous key, making new string excluding last character
        // and setting model equal to new string s
        std::string s = "          ";
        std::string inp = model_.get_input();
        int count = 0;
        for (int i =0; i <int(inp.length()); i++){
            if (inp[i] == ' '){
                count += 1;
            }
        }
        int num = inp.length() - count;
        if (num == 0){
            return ;
        }
        std::string r = inp.substr(0, num - 1);
        r.append(s.substr(num-1));
        model_.set_input(r);
    }
}

void
Controller::draw(ge211::Sprite_set& sprites )
{
    view_.draw(sprites);
}

View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string
Controller::initial_window_title() const
{
    return view_.initial_window_title();
}

