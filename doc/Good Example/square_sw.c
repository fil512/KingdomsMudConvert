//=============================================================================
// /areas/WestLars/Harbour/o/Town/Room/square_sw.c
//=============================================================================
// Modified: 00 950703 Shyan
//           01 951025 Case (cfstd + Engcorr)
//           02 951216 Case (xpl + pathch)
//=============================================================================

#pragma strict_types

#include "../../../def.h"

inherit "/std/room/parse_room";

void create_object(void);  //03

//03---------------------------------------------------------------------------
void create_object(void)
{
  setuid();

  seteuid(getuid(TO));

  set_short("Southwest corner of square");

  set_long("You are in the southwest corner of the village square. The port "+
	   "office is west from here. A road begins to the south. To the "+
	   "north and east the square stretches out and to the northeast "+
	   "you see a well of some sort. All around you are houses.\n");

   set_new_light(10);

  add_exit(TOWN_ROOM + "square_nw","north");
  add_exit(TOWN_ROOM + "square_well","northeast");
  add_exit(TOWN_ROOM + "square_se","east");
  add_exit(TOWN_ROOM + "t_crossing","south");
  add_exit(TOWN_ROOM + "port_office","west");

  add_item("ground",
	   "It's ground all right, and you are standing on it");
  add_item("road",
	   "A small road begines to the south");
  add_item("port office|office",
	   "You will enter it if you go west");
  add_item("well",
	   "It's to the northeast. You'll have to go there if you would like"+
	   "to have a closer look");
  add_item("houses",
	   "All around you. People in this village probably use them to "+
	   "live in");
}

//EOF==========================================================================
