#ifndef __Bullet2_AGENT__H
#define __Bullet2_AGENT__H 

#include "enviro.h"

using namespace enviro;

//! class for the Player 2 Bullet Controller
class Bullet2Controller : public Process, public AgentInterface
{

    public:
    Bullet2Controller() : Process(), AgentInterface(), counter(0) {}

    //! Watch for collisions with opposing player and their bullets
    void init()
    {
        //! If collision with opposing player bullet, remove the bullet
        notice_collisions_with("Bullet1", [&](Event &e)
        {
            remove_agent(id());
        });
        //! If collision with opposing player, remove bullet and set flag
        notice_collisions_with("Player1", [&](Event &e)
        {
            remove_agent(id());
            p1_hit = true;
        });      
    }

    void start() {}

    //! Remove bullet if no collisions
    //! Emit event if Player 1 is hit
    void update()
    {
        if ( counter++ > 8 )
        {
            remove_agent(id());
        }

        if (p1_hit = true)
        {
            emit(Event("p1_hit"));
            p1_hit = false;
        }

    }

    void stop() {}

    double counter;
    bool p1_hit = false;

};

//! Class for Player 2 Bullet
class Bullet2 : public Agent
{
    public:
    Bullet2(json spec, World& world) : Agent(spec, world)
    {
        add_process(c);
    }
    private:
    Bullet2Controller c;
};

DECLARE_INTERFACE(Bullet2)

#endif
