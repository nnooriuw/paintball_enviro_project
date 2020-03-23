#ifndef __Player1_AGENT__H
#define __Player1_AGENT__H 

#include <math.h>
#include "enviro.h"
#include "styles.h"

using namespace enviro;

//! class for the Player 1 Model Controller
class Player1Controller : public Process, public AgentInterface
{

    public:
    Player1Controller() : Process(), AgentInterface(), LEFT(false), RIGHT(false), FIRING(false) {}

    //! Initialize physical attributes and Events to watch for
    void init()
    {
        //! Only allows Left and Right movement
        prevent_rotation();

        //! Watch for Player 1 key presses
        watch("keydown", [&](Event &e)
        {
            //! Fire bullet when space key press detected
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
            //! Move Left if 'a' key pressed
            else if ( k == "a" ) 
            {
                LEFT = true;
                STOP = false;
            }
            //! Move Right if 'd' key pressed
            else if ( k == "d" ) 
            {
                RIGHT = true;
                STOP = false;
            }
        });

        //! Switch flag states when keyup detected from Player 1
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

    //! Update movement of Player 1 model based on flag events
    //! Use physics formulas from Dr. Klavin's enviro examples
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

        //! Watch for Player 2 hit emit event
        watch("p2_hit", [&](Event &e)
        {
            p2_hit = true;
        });

        //! Increment Player 1 score if Player 2 was hit by Player 1 bullet
        if (p2_hit)
        {
            p1_score = p1_score + 1;
            p2_hit = false;
        }

        //! Display Player 1's score
        label("Player 1 Score: " + std::to_string(p1_score), -50, -40);

    }

    void stop() {}

    bool LEFT, RIGHT, STOP, FIRING;
    bool p2_hit = false;
    double vx;
    int p1_score = 0;

    const double VEL_X = 20;
    const double K_X = 15;
    const double G = 500;

};

//! Class for Player 1 Agent
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
