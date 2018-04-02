//  Alejandro Rodriguez
//  DeRon Walker
//  Kevin Silberberg
//  Raul Sanchez
//  JaimeAdele Zuspann
//  Group 4
//
//  rpg.cpp
//  rpg
//
//  Created by Alejandro Rodriguez on 3/8/18.
//  Copyright © 2018 Alejandro Rodriguez. All rights reserved.
//

#include <iostream>
#include <string>


using namespace std;

enum rooms{SHORE, BANANATREE, TOPDECK, WHEEL, BOTTOMDECK, GALLEY, QUARTERS, CARGOHOLD, BRIG, NONE};

struct roomType{
    
    string name;
    string description;
    
    bool been;
    bool knife_existence;
    bool gorilla_existence;
    bool bananas_existence;
    bool treasure_existence;
    bool keys_existence;
    
    rooms value;
    rooms north;
    rooms east;
    rooms west;
    rooms south;
    rooms up;
    rooms down;
    
    
};

struct itemInventory{
    
    bool knife;
    bool bananas;
    bool treasure;
    bool keys;
    
};

itemInventory bag = {false, false, false, false};


void readCommand(string& verb, string& noun, char& a, char& b);
void executeCommand(string verb, string noun, char x, char y);
void itemCheck(string& word1, char& y);
void callLocation();
// Functions for verbs and actions.

void go ();
void board();
void enter();
void take();
void give();
void search();
void look();
void eat();
void cut(string& word2);
void climb();
void drop();
void unlock();
void sail();
void open();
void inventory();
void been();
// Functions for cardinal directions.

void e();
void n();
void w();
void s();
void up();
void down();

// Functions for the rooms.

void top_deck();
void shore_();
void bannana_tree();
void bottom_deck();
void galley_();
void quarters_();
void cargo_hold();
void brig_();
void wheel_();

// Structs holding values for specific rooms.

roomType currentLocation = {};

roomType shore = { "Shore ", "Your on an island no one is around you, there are bannana trees everyewhere but they look tough to cut.",false, false, false, false, false, false, SHORE, BANANATREE,  NONE, NONE, NONE, NONE, NONE};

roomType  bannanatree = {"Banana Trees",  "Youve encountered a banana tree, looks like you cant pull them off with your hands maybe you can find a knife on the ship", false, false, false, true, false, false,BANANATREE, NONE, TOPDECK, NONE, SHORE, NONE, NONE};

roomType topdeck = {"Top Deck of the Ship", "Your on the top deck of the ship, you can go down the ladder, go south to the captains quarters or north to the wheel", false, false, false, false, false, false,TOPDECK, WHEEL, NONE, BANANATREE, QUARTERS, NONE, BOTTOMDECK};

roomType wheel = {"Wheel of the Ship", "You are at the wheel of the ship but there is an angry / hungry gorilla blocking you better go back", false, false, true, false, false, false, WHEEL, NONE, NONE, NONE, TOPDECK, NONE, NONE};

roomType bottomdeck = {"Bottom Deck of the Ship", "its pretty dark in herer but you see three doors one to your east and west and one going down a trap door.", false, false, false, false, false, false,BOTTOMDECK, NONE, GALLEY, CARGOHOLD, NONE, TOPDECK, BRIG};

roomType galley = {"Galley", "This is the galley. It is mostly empty, but in a shadowy corner you see a parrot sitting on a perch.", false, false, false, false, false, false, GALLEY, NONE, NONE, BOTTOMDECK, NONE, NONE, NONE};

roomType quarters = {"Captain's Quarters", "There is a bed and a table in this room. (There is a knife on the table.)", false, false, false, false, false, false, QUARTERS, TOPDECK, NONE, NONE, NONE, NONE, NONE};

roomType cargohold = {"Cargo Hold", "You've entered the cargo hold. There are barrels, a pile of tools, and a trunk. (Treasure is in the trunk.)", false, false, false, false, false, false, CARGOHOLD, NONE, BOTTOMDECK, NONE, NONE, NONE, NONE};

roomType brig = {"Brig", "In this room there is a prisoner in a locked cell. He says, Jack, I'm so glad you're alive. The captain locked me up for cheating at cards, which is the only reason the islanders didn't capture me. They killed everyone else. Now I guess we're the only two left, which makes you captain since you were first mate. Go find the keys to unlock this door, and we can sail out of here" , false, false, false, false, false, false, BRIG, NONE, NONE, NONE, NONE, BOTTOMDECK, NONE};


int main() {
    
    
    string noun, verb;
    char a, b;
    
    currentLocation = shore;
    cout << currentLocation.description << endl;
    
    readCommand(verb, noun, a, b);
    
    while (verb != "quit"){
        executeCommand(verb, noun, a, b);
        readCommand(verb, noun, a, b);
        
    }
    
    return 0;
}


void readCommand(string& word1, string& word2, char& x, char& y){         // Reads the functions
    cout << "What do you want to do ? " << endl;
    cin >> word1 ;
    //cin.ignore(999, '\n');
    
    x = word1.at(0);
}

void executeCommand(string word1, string word2, char x, char y){        // Execute commands
    
    switch(x){
        case 'g': if (word1 == "go"){
            go();
        } else if (word1 == "give"){
            give();
        }
            break;
        case 'b': if (word1 == "board"){
            board();
        }
            break;
        case 'e': if (word1 == "enter"){
            enter();
        } else if (word1 == "eat"){
            eat();
        } else if (word1 == "east"){
            e();
        }
            break;
        case 't': if (word1 == "take"){
            take();
        }
            break;
        case 's': if (word1 == "search"){
            search();
        }else if (word1 == "sail" ){
            sail();
        }
            break;
        case 'n': if (word1 == "north"){
            n();
        }
        case 'c': if (word1 == "cut"){
            cut(word2);
        }else if (word1 == "climb"){
            climb ();
        }else if (word1 == "call"){
            callLocation();
        }
            break;
        case 'l': if (word1 == "look"){
            look();
        }
            break;
        case 'd': if (word1 == "drop"){
            drop();
        }
            break;
        case 'u' : if (word1 == "unlock"){
            unlock();
        }
            break;
        case 'o': if (word1 == "open"){
            open();
        }
            break;
        case 'i': if (word1 == "inventory"){
            inventory();
        }
            break;
            
        default: cout << "Talk correctly " << endl;
            
    }
}

// Functions for navigation the map ..

void go (){
    string direction;
    cin >> direction;
    
    if (direction == "north"){
        n();
    }else if (direction == "south"){
        s();
    }else if (direction == "west"){
        w();
    }else if (direction == "east"){
        e();
    }else if (direction == "down" ){
        down();
    }else if (direction == "up"){
        up();
    }
    
}

void n(){
    if (currentLocation.north == NONE){
        cout << "You cant go that way" << endl;
    }else if (currentLocation.north == TOPDECK) {
        top_deck();
    }else if (currentLocation.north == SHORE) {
        shore_();
    }else if (currentLocation.north == BOTTOMDECK) {
        bottom_deck();
    }else if (currentLocation.north == GALLEY){
        galley_();
    }else if (currentLocation.north == BRIG){
        brig_();
    }else if (currentLocation.north == WHEEL){
        wheel_();
    }else if (currentLocation.north == QUARTERS){
        quarters_();
    }else if (currentLocation.north == CARGOHOLD){
        cargo_hold();
    }else if (currentLocation.north == BANANATREE){
        bannana_tree();
    }
    
}

void e(){
    if (currentLocation.east == NONE){
        cout << "You cant go that way" << endl;
    }else if (currentLocation.east == TOPDECK) {
        top_deck();
    }else if (currentLocation.east == SHORE) {
        shore_();
    }else if (currentLocation.east == BOTTOMDECK) {
        bottom_deck();
    }else if (currentLocation.east == GALLEY){
        galley_();
    }else if (currentLocation.east == BRIG){
        brig_();
    }else if (currentLocation.east == WHEEL){
        wheel_();
    }else if (currentLocation.east == QUARTERS){
        quarters_();
    }else if (currentLocation.east == CARGOHOLD){
        cargo_hold();
    }else if (currentLocation.east == BANANATREE){
        bannana_tree();
    }
    
}
void w(){
    if (currentLocation.west == NONE){
        cout << "You cant go that way" << endl;
    }else if (currentLocation.west == TOPDECK) {
        top_deck();
    }else if (currentLocation.west == SHORE) {
        shore_();
    }else if (currentLocation.west == BOTTOMDECK) {
        bottom_deck();
    }else if (currentLocation.west == GALLEY){
        galley_();
    }else if (currentLocation.west == BRIG){
        brig_();
    }else if (currentLocation.west == WHEEL){
        wheel_();
    }else if (currentLocation.west == QUARTERS){
        quarters_();
    }else if (currentLocation.west == CARGOHOLD){
        cargo_hold();
    }else if (currentLocation.west == BANANATREE){
        bannana_tree();
    }
    
}
void s(){
    if (currentLocation.south == NONE){
        cout << "You cant go that way" << endl;
    }else if (currentLocation.south == TOPDECK) {
        top_deck();
    }else if (currentLocation.south == SHORE) {
        shore_();
    }else if (currentLocation.south == BOTTOMDECK) {
        bottom_deck();
    }else if (currentLocation.south == GALLEY){
        galley_();
    }else if (currentLocation.south == BRIG){
        brig_();
    }else if (currentLocation.south == WHEEL){
        wheel_();
    }else if (currentLocation.south == QUARTERS){
        quarters_();
    }else if (currentLocation.south == CARGOHOLD){
        cargo_hold();
    }else if (currentLocation.south == BANANATREE){
        bannana_tree();
    }
    
}
void up(){
    if (currentLocation.up == NONE){
        cout << "You cant go that way" << endl;
    }else if (currentLocation.up == TOPDECK) {
        top_deck();
    }else if (currentLocation.up == BOTTOMDECK) {
        bottom_deck();
    }
}

void down(){
    if (currentLocation.down == NONE){
        cout << "You cant go that way" << endl;
    }else if (currentLocation.down == BRIG) {
        brig_();
    }else if (currentLocation.down == BOTTOMDECK) {
        bottom_deck();
    }
}
// Function for item assignment.
void itemCheck(string& word2){
    
}

// Functions for verbs and actions.

void unlock(){}
void sail(){
    
}
void open(){}
void take(){
    string word2;
    cin >> word2;
    
    if (currentLocation.value == BRIG){
        if (word2 == "treasure"){
            bag.treasure = true;
            cout << "You have grabbed the treasure" << endl;
            cargohold.treasure_existence = false;
        }
    }
}
void give(){
    
    string word2;
    cin >> word2;
    if (currentLocation.value == WHEEL){
        if (word2 == "bananas" && bag.bananas == true){
            cout << "The gorilla has left and the wheel is now available" << endl;
            currentLocation.gorilla_existence = false;
            wheel.gorilla_existence = false;
        }
    }
    if (currentLocation.value == TOPDECK ){
        if (word2 == "treasure " && bag.treasure == true){
            bag.treasure = false;
            cout << "you have given the indians the treasure and can now access the bananas" << endl;
        }
        
    }
}

void search(){
    cout << currentLocation.description << endl;
    cout << "Actionable Items In Current Location:" << endl;
    if (currentLocation.knife_existence == true){
        cout << "Knife" << endl;
    }
    if (currentLocation.gorilla_existence == true){
        cout << "Gorilla" << endl;
    }
    if (currentLocation.bananas_existence == true){
        cout << "Bananas" << endl;
    }
    if (currentLocation.treasure_existence == true){
        cout << "Treasure" << endl;
    }
    if (currentLocation.keys_existence == true){
        cout << "Keys" << endl;
    }
    
}
void look(){}
void eat(){
    if (bag.bananas == true){
        bag.bananas = false;
        cout << "You ate all your bananas" << endl;
    }
}
void cut(string& word2){
    cin >> word2;
    if (currentLocation.value == BANANATREE){
        if (bag.knife == true && word2 == "bananas") {
            bag.bananas = true;
            
            cout << "You have recieved some bannanas, lets put them in your bag" << endl;
        }
    }
}
void climb(){
    
    if (currentLocation.value == BOTTOMDECK){
        top_deck();
    }
}
void drop(){
    string item;
    cin >> item;
    
    if (item == "knife"){
        bag.knife = false;
        
    }
    if (item == "treasure "){
        bag.treasure = false;
    }
    if (item == "keys"){
        bag.keys = false;
    }
    if (item == " bananas"){
        bag.bananas = true;
    }
}
void board(){
    if (currentLocation.value == BANANATREE){
        top_deck();
    }
    
    
}
void enter(){}

// Functions for the rooms.

void shore_ (){
    currentLocation = shore;
    if(currentLocation.been)
        cout << currentLocation.name << endl;
    else
        cout << currentLocation.description << endl;
    currentLocation.been = true;
}
void bannana_tree (){
    currentLocation = bannanatree;
    if(currentLocation.been)
        cout << currentLocation.name << endl;
    else
        cout << currentLocation.description << endl;
    currentLocation.been = true;
    
}
void top_deck (){
    currentLocation = topdeck;
    if(currentLocation.been)
        cout << currentLocation.name << endl;
    else
        cout << currentLocation.description << endl;
    currentLocation.been = true;
}
void wheel_ (){
    currentLocation = wheel;
    if(currentLocation.been)
        cout << currentLocation.name << endl;
    else
        cout << currentLocation.description << endl;
    currentLocation.been = true;
}
void bottom_deck (){
    currentLocation = bottomdeck;
    if(currentLocation.been)
        cout << currentLocation.name << endl;
    else
        cout << currentLocation.description << endl;
    currentLocation.been = true;
}
void galley_ (){
    currentLocation = galley;
    if(currentLocation.been)
        cout << currentLocation.name << endl;
    else
        cout << currentLocation.description << endl;
    currentLocation.been = true;
}
void quarters_ () {
    currentLocation = quarters;
    if(currentLocation.been)
        cout << currentLocation.name << endl;
    else
        cout << currentLocation.description << endl;
    currentLocation.been = true;
}
void cargo_hold () {
    currentLocation = cargohold;
    if(currentLocation.been)
        cout << currentLocation.name << endl;
    else
        cout << currentLocation.description << endl;
    currentLocation.been = true;
}
void brig_ () {
    currentLocation = brig;
    if(currentLocation.been)
        cout << currentLocation.name << endl;
    else
        cout << currentLocation.description << endl;
    currentLocation.been = true;
}
void none_ () {
    
}
void callLocation (){
    cout << currentLocation.name << endl;
}
void inventory (){
    if (bag.knife == true) {
        cout << "Knife" << endl;
    }
    if (bag.treasure == true){
        cout << "Treasure" << endl;
        cargohold.treasure_existence = true;
    }
    if (bag.keys == true){
        cout << "Keys" << endl;
    }
    if (bag.bananas == true){
        cout << "Bananas" << endl;
    }
}





