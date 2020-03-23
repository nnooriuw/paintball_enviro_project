#ifndef __Bullet2_AGENT__H
#define __Bullet2_AGENT__H 

#include "enviro.h"

using namespace enviro;

class Bullet2Controller : public Process, public AgentInterface
{

    public:
    Bullet2Controller() : Process(), AgentInterface(), counter(0) {}

    void init()
    {
        notice_collisions_with("Bullet1", [&](Event &e)
        {
            remove_agent(id());
        });
        notice_collisions_with("Player1", [&](Event &e)
        {
            remove_agent(id());
            p1_hit = true;
        });      
    }

    void start() {}

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
