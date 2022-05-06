#include "Contessa.hpp"
using namespace coup;
using std::move; using std::runtime_error;

//Constructor
Contessa::Contessa(Game& game, string name)
:Player(game, move(name), "Contessa")
{}

void Contessa::block(Player& target) {
    if (target.getCurrState() != State::COUP) {throw runtime_error("ERR: cannot block coup - targeted player's turn has already reached.");}
    if (!target.isAssassinated()) {throw runtime_error("ERR: player didn't assassinate!");}
    target.setCoupBlock(true);
    target.getPlayer_ptr().setAlive(true);
    _game.setPlayers(target.getPlayers());
    _game.fixCurrPosAdd(target.getPlayer_ptr().name());
}
