#include "Game.hpp"
using namespace coup;

using std::runtime_error;

Game::Game() {
    _winner = "";
    _curr_turn = 0;
    _game_started = false;
}

vector<string> Game::players() {
    return _players;
}

string Game::turn() {
    return _players[(unsigned long)_curr_turn];
}

void Game::next_turn() {
    ++_curr_turn;
    _curr_turn %= (int)_players.size();
}

string Game::winner() {
    if (!_game_started) {throw runtime_error("ERR: can't find a winner yet!");}
    if (_players.size() > WINNER){throw runtime_error("ERR: can't find a winner yet!");}
    return _winner;
}

void Game::addPlayer(const string &name) {
    if (_game_started) {throw runtime_error("ERR: can't find a winner yet!");}
    if (_players.size() == MAX_PLAYERS_AMOUNT) {throw runtime_error("ERR: players amount has reached its limit.");}
    _players.push_back(name);
}

void Game::remPlayer(const string &name) {
    _players.erase(remove(_players.begin(), _players.end(), name), _players.end());
}

/**
 * Fixes the current position after removing the player with the given name.
 * @param remPlayerName
 */
void Game::fixCurrPos(const string &remPlayerName) {
    int pos = findPlayerPos(remPlayerName);
    if (pos < _curr_turn){_curr_turn--;}
}

/**
 * Fixes the current position after returning player with given name back to the game.
 * @param addPlayerName
 */
void Game::fixCurrPosAdd(const string &addPlayerName) {
    int pos = findPlayerPos(addPlayerName);
    cout << "name: " << addPlayerName << ", " << "position: " << pos << endl;
    if (pos < _curr_turn){_curr_turn++;}

}


void Game::setPlayers(const vector<string>& players) {
    _players.clear();
    for(const string& player: players){_players.push_back(player);}
}

int Game::findPlayerPos(const string &PlayerName) {
    for (size_t i = 0; i < _players.size(); ++i) {
        if (_players[i] == PlayerName){
            return (int) i;
        }
    }
    return -1;
}

void Game::setWinner(const string& winnerName) {
    _winner = winnerName;
}


bool Game::started() const{
    return _game_started;
}
void Game::setGameStatus(bool status){
    _game_started = status;
}




