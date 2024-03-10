#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <allegro.h>

#include "main.h"

void my_timer_handler(void)
{
   counter++;
}
END_OF_FUNCTION(my_timer_handler);

int inicia_allegro(int max_x, int max_y, int prof)
{
	allegro_init(); install_keyboard();
	install_mouse(); install_timer();

	if (install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL) < 0)
	{
		printf("Erro no som!\n");
		return(FALSE);
	}

	set_volume(vol_som,vol_musica);
	set_color_depth(prof);
	if (set_gfx_mode(GFX_AUTODETECT,max_x,max_y,0,0) < 0)
	{
		printf("Erro no video!\n");
		return(FALSE);
	}

   LOCK_VARIABLE(counter);
   LOCK_FUNCTION(my_timer_handler);
   install_int_ex(my_timer_handler,BPS_TO_TIMER(FRAME_RATE));

	return(TRUE);
}

int main(int argc, char **argv)
{
   inicia_allegro(RES_X,RES_Y,(modo_16_bits) ? 16 : 8);


    counter = 0;
    lacos = 1;

   while(!key[KEY_ESC])
   {
      if (counter)
      {
         counter = 0;
         lacos++;
      }
   }
   allegro_exit();
	return(0);
}
END_OF_MAIN();