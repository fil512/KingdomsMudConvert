#pragma save_binary
#include "/areas/Bird/Aviary/o/include/defs.h"

inherit "/std/room/parse_room";

void create_object(void);

void create_object(void)
{
  setuid();

  seteuid(getuid(TO));

  set_new_light(10);
  set_short("Dinner Room");
  set_long("This is where Fil hangs out when he is eating dinner.  There's not much to see, just a simple stove, an icebox, and a few pots and pans.  If he's here, He'll probably be finished his dinner within 20 minutes.\n");
  add_item("pots","They are all very clean");
  add_item("stove","It is warm, Fil seems to be cooking some dinner on it");
  add_item("icebox","This is stuffed full of various cheeses, and frozen casseroles");
  add_exit("/areas/Bird/Aviary/o/workroom", "east");
}
