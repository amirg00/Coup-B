#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#define WINNER 1                 /*The last player lasted = 1 players remained*/
#define MIN_PLAYERS_AMOUNT 2     /*The minimum amount of players allowed*/
#define MAX_PLAYERS_AMOUNT 6     /*The maximum amount of players allowed*/


using std::string; using std::vector; using std::remove; using std::cout; using std::endl; using std::transform;



namespace coup{
    class Game {
    private:
        string _winner;               /* Winner's name*/
        int _curr_turn;               /* Index for player's position*/
        vector<string> _players;      /* Players name vector*/
        bool _game_started;           /* Flag indicates if the game has started*/
    public:
        Game();                    /*Constructor*/
        string turn();
        void next_turn();
        vector<string> players();
        string winner();
        void addPlayer(const string& name);
        void remPlayer(const string& name);
        void fixCurrPos(const string& remPlayerName);
        void fixCurrPosAdd(const string& addPlayerName);
        int findPlayerPos(const string& PlayerName);
        void setPlayers(const vector<string>& players);
        void setWinner(const string& winnerName);
        bool started() const;
        void setGameStatus(bool status);
    };
}
