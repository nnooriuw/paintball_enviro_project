#ifndef __Bullet1_AGENT__H
#define __Bullet1_AGENT__H 

#include "enviro.h"

using namespace enviro;

//! class for the Player 1 Bullet Controller
class Bullet1Controller : public Process, public AgentInterface
{

    public:
    Bullet1Controller() : Process(), AgentInterface(), counter(0) {}

    //! Watch for collisions with opposing player and their bullets
    void init()
    {
        //! If collision with opposing player bullet, remove the bullet
        notice_collisions_with("Bullet2", [&](Event &e)
        {
            remove_agent(id());
        });
        //! If collision with opposing player, remove bullet and set flag
        notice_collisions_with("Player2", [&](Event &e)
        {
            remove_agent(id());
            p2_hit = true;
        });  
    }

    void start() {}

    //! Remove bullet if no collisions
    //! Emit event if Player 2 is hit
    void update()
    {
        if ( counter++ > 8 )
        {
            remove_agent(id());
        }

        if (p2_hit = true)
        {
            emit(Event("p2_hit"));
            p2_hit = false;
        }

    }

    void stop() {}

    double counter;
    bool p2_hit = false;

};

//! Class for Player 1 Bullet
class Bullet1 : public Agent 
{
    public:
    Bullet1(json spec, World& world) : Agent(spec, world) 
    {
        add_process(c);
    }
    private:
    Bullet1Controller c;
};

DECLARE_INTERFACE(Bullet1)

#endif
