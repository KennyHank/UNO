#include <iostream>
#include "card.h"

Color Card::getColor() const{
    return color;
}
    
int Card::getNumber() const{
    return number;
}

void Card::setColor(Color c){
    color = c;
}

void Card::setNumber(int n){
    number = n;
}

NumberCard::NumberCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}

string NumberCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|     " <<  number << "     |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool NumberCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        return true;
    } else {
        return false;
    }
}

ReverseCard::ReverseCard(Color c) {
    setColor(c);
}

string ReverseCard::render(int line) const {
    stringstream ss;
    switch(line) {
        case 0:
            return ".___________.";
        case 1:
            return "|           |";
        case 2:
            return "|  Reverse  |";
        case 3:
            return "|           |";
        case 4:
            return "|           |";
        case 5:
            return "|           |";
        case 6:
            return "|           |";
        case 7:
            return "|___________|";
        default:
            return " ";
    }
}

bool ReverseCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor()){
        //Reverses the turn direction after evaluating the current gamestate
       if(gameState.turnDirection == LEFT)
       {
           gameState.turnDirection = RIGHT;
       }
       else {
           gameState.turnDirection = LEFT;
       }
        return true;
    } else {
        return false;
    }
}

SkipCard::SkipCard(Color c) {
    setColor(c);
}

string SkipCard::render(int line) const {
    stringstream ss;
    switch(line) {
        case 0:
            return ".___________.";
        case 1:
            return "|           |";
        case 2:
            return "|   Skip    |";
        case 3:
            return "|           |";
        case 4:
            return "|           |";
        case 5:
            return "|           |";
        case 6:
            return "|           |";
        case 7:
            return "|___________|";
        default:
            return " ";
    }
}

bool SkipCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor()){
        gameState.skipTurn = true;
        return true;
    } else {
        return false;
    }
}

Draw2Card::Draw2Card(Color c) {
    setColor(c);
}

string Draw2Card::render(int line) const {
    stringstream ss;
    switch(line) {
        case 0:
            return ".___________.";
        case 1:
            return "|           |";
        case 2:
            return "|    +2     |";
        case 3:
            return "|           |";
        case 4:
            return "|           |";
        case 5:
            return "|           |";
        case 6:
            return "|           |";
        case 7:
            return "|___________|";
        default:
            return " ";
    }
}

bool Draw2Card::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor()){
        gameState.numCardsToDraw += 2;
        return true;
    } else {
        return false;
    }
}

WildCard::WildCard() {

}


string WildCard::render(int line) const {
    stringstream ss;
    switch(line) {
        case 0:
            return ".___________.";
        case 1:
            return "|           |";
        case 2:
            return "|   WILD    |";
        case 3:
            return "|           |";
        case 4:
            return "|           |";
        case 5:
            return "|           |";
        case 6:
            return "|           |";
        case 7:
            return "|___________|";
        default:
            return " ";
    }
}

bool WildCard::play(Card* discard, GameState &gameState) {
    cout << "Please enter a color: " << endl;
    cout << "1. RED" << endl;
    cout << "2. BLUE" << endl;
    cout << "3. GREEN" << endl;
    cout << "4. YELLOW" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
        setColor(RED);
    if (choice == 2)
        setColor(BLUE);
    if (choice == 3)
        setColor(GREEN);
    if (choice == 4)
        setColor(YELLOW);
    else {
        cout << "Wrong choice" << endl;
    }
    return true;
}



