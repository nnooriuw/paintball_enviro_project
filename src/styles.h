#ifndef __BULLET_STYLES__H
#define __BULLET_STYLES__H

#include "enviro.h"

using namespace enviro;

//! Define the Bullet styles for Player 1 and 2
const json  BULLET_STYLE1 = { 
                {"fill", "red"}, 
                {"stroke", "#888"}, 
                {"strokeWidth", "5px"},
                {"strokeOpacity", "0.25"}
            },           
            BULLET_STYLE2 = { 
                   {"fill", "blue"}, 
                   {"stroke", "#888"}, 
                   {"strokeWidth", "5px"},
                   {"strokeOpacity", "0.25"}
               };

#endif
