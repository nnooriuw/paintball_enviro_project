#ifndef __Player2_AGENT__H
#define __Player2_AGENT__H 

#include <math.h>
#include "enviro.h"
#include "styles.h"

using namespace enviro;

//! class for the Player 2 Model Controller
class Player2Controller : public Process, public AgentInterface
{

    public:
    Player2Controller() : Process(), AgentInterface(), LEFT(false), RIGHT(false), FIRING(false) {}
    
    //! Initialize physical attributes and Events to watch for
    void init()
    {
        //! Only allows Left and Right movement
        prevent_rotation();

        //! Watch for Player 2 key presses
        watch("keydown", [&](Event &e)
        {
            //! Fire bullet when shift key press detected
            auto k = e.value()["key"].get<std::string>();
            if ( k == "Shift" && !FIRING )
            {
                  Agent& bullet2 = add_agent("Bullet2",
                    x() + 17*cos(angle()) * -0.001,
                    y() + 17*sin(angle())-25.0,
                    angle() - 1.5708,
                    BULLET_STYLE2);
                    bullet2.apply_force(100,0);
                  FIRING = true;
            }
            //! Move Left if Left Arrow key pressed
            else if ( k == "ArrowLeft" ) 
            {
                LEFT = true;
                STOP = false;
            }
            //! Move Right if Right Arrow key pressed
            else if ( k == "ArrowRight" ) 
            {
                RIGHT = true;
                STOP = false;
            }
        });

        //! Switch flag states when keyup detected from Player 2
        watch("keyup", [&](Event &e)
        {
            auto k = e.value()["key"].get<std::string>();
            if ( k == "Shift" )
            {
                FIRING = false;
            }
            else if ( k == "ArrowLeft" ) 
            {
                LEFT = false;
                STOP = true;
            }
            else if ( k == "ArrowRight" ) 
            {
                RIGHT = false;
                STOP = true;
            }
        });
    }

    void start() {}

    //! Update movement of Player 2 model based on flag events
    //! Use physics formulas from Dr. Klavin's enviro examples
    void update()
    {
        double fx;

        if (RIGHT)
        {
            vx = VEL_X;
            fx = 0;
            fx = -K_X*(velocity().x-vx);
            omni_apply_force(fx,G);
        }
        else if (LEFT)
        {
            vx = -1 * VEL_X;
            fx = 0;
            fx = -K_X*(velocity().x-vx);
            omni_apply_force(fx,G);
        }
        else if (STOP)
        {
            damp_movement();
        }

        //! Watch for Player 1 hit emit event
        watch("p1_hit", [&](Event &e)
        {
            p1_hit = true;
        });

        //! Increment Player 2 score if Player 1 was hit by Player 2 bullet
        if (p1_hit == true)
        {
            p2_score = p2_score + 1;
            p1_hit = false;
        }

        //! Display Player 2's score
        label("Player 2 Score: " + std::to_string((int)p2_score), -50, 50);

    }

    void stop() {}

    bool LEFT, RIGHT, STOP, FIRING;
    bool p1_hit = false;
    double vx;
    double p2_score = 0;

    const double VEL_X = 20;
    const double K_X = 15;
    const double G = 500;

};

//! Class for Player 2 Agent
class Player2 : public Agent
{
    public:
    Player2(json spec, World& world) : Agent(spec, world)
    {
        add_process(c);
    }
    private:
    Player2Controller c;
};

DECLARE_INTERFACE(Player2)

#endif
