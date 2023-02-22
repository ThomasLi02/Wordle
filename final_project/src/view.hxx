#pragma once

#include "model.hxx"

#include <string>

class View
{
public:
    /// View dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

    /// View positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    /// Constructs a view that knows about the given model.
    explicit View(Model const&);
    void draw(ge211::Sprite_set& set);



    Dimensions initial_window_dimensions() const;

    std::string initial_window_title() const;


private:
    Model const& model_;


    ge211::Rectangle_sprite const square_sprite_, yellow_square_,green_square_,
    rect_sprite_;
    ge211::Font sans30{"sans.ttf", 30};
    ge211:: Text_sprite inputString, enterString, loseString, continueString1,
    continueString2, quitString, notEnough, notWord;
    ge211:: Text_sprite character[6][6];

    void
    setInput(std::string x);
};
