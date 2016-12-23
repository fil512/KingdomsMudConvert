// comment 1
// comment 2

#pragma save_binary
#include "/areas/Bird/Aviary/o/include/defs.h"

inherit "/std/room/room";

/*
multi line
comment
*/

object slug;

reset(arg)
{
    ::reset(arg);

    if(arg) return;

    set_light(1);
    short_desc = "Dinner Room";
    long_desc = "This is where Fil hangs out when he is eating dinner.  There's not much to see, just a simple stove, an icebox, and a few pots and pans.  If he's here, He'll probably be finished his dinner within 20 minutes.\n";
    items =
      ({
	"pots","They are all very clean",
	"stove","It is warm, Fil seems to be cooking some dinner on it",
	"icebox","This is stuffed full of various cheeses, and frozen casseroles"
	});
    dest_dir =
    ({"/areas/Bird/Aviary/o/workroom", "east"});
}
