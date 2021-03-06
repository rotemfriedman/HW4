#ifndef HW4_GAME_H
#define HW4_GAME_H

#include "Weapon.h"
#include "Player.h"

enum GameStatus{
 NAME_ALREADY_EXSISTS,
    GAME_FULL,
    SUCCESS,
    NAME_DOES_NOT_EXIST,
    INVALID_PARAM,
    FIGHT_FAILED
};


class Game {
    int maxPlayer;
    Player** array_player;
    int last_player_in_the_array;


    /**
     * the function find the max index, sort by the playerName
     * @return - the max index
     */
    int index_of_max()const;

/**
 * the function sort the array of the player by the playerName
 */
    void max_sort();

public:
/**
 * the functuin create a new classe game
 * @param maxPlayer
 */
    Game(int maxPlayer);
/**
 * the function delete the Game(free him)
 */

    ~Game();


    //copy constractor
    Game(const Game& game);



/**
 *
 * @param playerName
 * @param weaponName
 * @param target
 * @param hit_strength
 * @return
 */
    GameStatus addPlayer(const char * playerName, const char * weaponName,
    Target target,int hit_strength);

    /**
     * the metoda get name of a player, and increase his level
     * @param playerName- the name of the player
     * @return- if the player does not exist return - NAME_DOES_NOT_EXIST
     */
    GameStatus nextLevel(const char *playerName);
/**
 *the function
 * @param playerName1
 * @param playerNamr1
 * @return
 */
    GameStatus fight(const char * playerName1, const char * playerName2);




/**
 * get a playerName and increase the position of the player
 * @param playerName- the name of the player
 * @return- NAME_DOES_NOT_EXIST if the name doesn't exist or SUCCESS
 */
    GameStatus makeStep(const char* playerName);


/**
 * get a playerName and increase his life
 * @param playerName - the name of the player
 * @return- NAME_DOES_NOT_EXIST if the name doesn't exist or SUCCESS
 */
    GameStatus addLife(const char* playerName);



/**
 * add the strength to the player
 * @param playerName - the player name
 * @param strengthToAdd - the strength that we need to add
 * @return- INVALID_PARAM if the strengthToAdd is minos, or NAME_DOES_NOT_EXIST
 * or SUCCESS
 */
    GameStatus addStrength (const char* playerName, int strengthToAdd);

/**
 * remove all the players that thier weapon is weaker than the weaponStrangth.
 * @param weaponStrangth - the weaponStrangth to compare
 * @return true- if the players removed. else false
 */
bool removeAllPlayersWIthWeakWeapon(int weaponStrangth);

    /**
 * this function print all the players sorted by the lexikografi name
 * @param os
 * @param game-the game that we want to print the players from him
 */
    friend ostream& operator<<(ostream& os,Game& game);

    /**
     * operator hasama for the game class
     * @param game - the game that we want to give to "this"
     * @return - reference of the new game
     */
    Game& operator=(const Game& game);

};



#endif //HW4_GAME_H
