/*
  Name:     RPG
  Author:   Yadok - KODAYGAMES
  Date:     27/08/15 14:49
  Web:      http://devcpp-allegro.blogspot.com/
  Description: 
         Creacion de un juego al estilo RPG
         mas informacion en la web        
*/


#include <allegro.h>

int main() 
{	
	allegro_init();
	install_keyboard();
	
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	
	BITMAP *buffer = create_bitmap(800, 600);
	BITMAP *prota  = load_bmp("personaje.bmp",NULL);
	
	bool salir;
	int x,y;
	
	// inicializar vbles
	x = 10;
	y = 10;
	salir = false;
			
	while ( !salir )
	{	
          clear_to_color(buffer, 0xaaaaaa);
          
          masked_blit(prota, buffer, 0,0, x, y, 32,32);
          
          // teclas control usuario
          if ( key[KEY_UP] )
          {
               y--;
          }
          if ( key[KEY_DOWN] )
          {
               y++;
          }
          if ( key[KEY_LEFT] )
          {
               x--;
          }
          if ( key[KEY_RIGHT] )
          {
               x++;
          }                              
          
          // limites
          if ( x < 0 ) x = 0;
          if ( x > 800 ) x = 800;
          if ( y < 0 ) y = 0;
          if ( y > 600 ) y = 600;          
          
          
    	  blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    	  
    	  rest(10);
    	  
    	  // tecla de salida
    	  if ( key[KEY_ESC] ) salir = true;
    	      	  
    }  
		
	destroy_bitmap(prota);
	destroy_bitmap(buffer);
	
	return 0;
}
END_OF_MAIN();
