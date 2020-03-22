#ifndef __Bullet1_AGENT__H
#define __Bullet1_AGENT__H 

#include "enviro.h"

using namespace enviro;

class Bullet1Controller : public Process, public AgentInterface
{

    public:
    Bullet1Controller() : Process(), AgentInterface(), counter(0) {}

    void init()
    {
        notice_collisions_with("Bullet2", [&](Event &e)
        {
            remove_agent(id());
        });
        notice_collisions_with("Player2", [&](Event &e)
        {
            remove_agent(id());
        });  
    }

    void start() {}

    void update()
    {
        if ( counter++ > 15 )
        {
            remove_agent(id());
        }
    }

    void stop() {}

    double counter;

};

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
