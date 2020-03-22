#ifndef __Player1_AGENT__H
#define __Player1_AGENT__H 

#include <math.h>
#include "enviro.h"
#include "styles.h"

using namespace enviro;

class Player1Controller : public Process, public AgentInterface
{

    public:
    Player1Controller() : Process(), AgentInterface(), LEFT(false), RIGHT(false), FIRING(false) {}

    void init()
    {
        prevent_rotation();
        watch("keydown", [&](Event &e)
        {
            auto k = e.value()["key"].get<std::string>();
            if ( k == " " && !FIRING )
            {
                  Agent& bullet1 = add_agent("Bullet1",
                    x() + 17*cos(angle()) * -0.001, 
                    y() + 17*sin(angle()) + 25.0, 
                    angle() + 1.5708, 
                    BULLET_STYLE1);
                    bullet1.apply_force(100,0);
                  FIRING = true;
            }
            else if ( k == "a" ) 
            {
                LEFT = true;
                STOP = false;
            }
            else if ( k == "d" ) 
            {
                RIGHT = true;
                STOP = false;
            }
        });

        watch("keyup", [&](Event &e)
        {
            auto k = e.value()["key"].get<std::string>();
            if ( k == " " )
            {
                FIRING = false;
            }
            else if ( k == "a" ) 
            {
                LEFT = false;
                STOP = true;
            }
            else if ( k == "d" ) 
            {
                RIGHT = false;
                STOP = true;
            }
        });
    }

    void start() {}

    void update() 
    {
        double fx;

        if (RIGHT)
        {
            vx = VEL_X;
            fx = 0;
            fx = -K_X*(velocity().x-vx);
            omni_apply_force(fx,-G);
        }
        else if (LEFT)
        {
            vx = -1 * VEL_X;
            fx = 0;
            fx = -K_X*(velocity().x-vx);
            omni_apply_force(fx,-G);
        }
        else if (STOP)
        {
            damp_movement();
        }

    }

    void stop() {}

    bool LEFT, RIGHT, STOP, FIRING;
    double vx;

    const double VEL_X = 20;
    const double K_X = 15;
    const double G = 500;

};

class Player1 : public Agent
{
    public:
    Player1(json spec, World& world) : Agent(spec, world)
    {
        add_process(c);
    }
    private:
    Player1Controller c;
};

DECLARE_INTERFACE(Player1)

#endif
