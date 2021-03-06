/*
  Name:     RPG
  Author:   Yadok - KODAYGAMES
  Date:     27/08/15 14:49
  Web:      http://devcpp-allegro.blogspot.com/
  Description: 
         Creacion de un juego al estilo RPG
         mas informacion en la web        
*/

//Probando
#include <allegro.h>
int ax,ay;
int direccion;
int animacion;
int desplazamiento;
 

int main() 
{	
	// inicializar vbles
	ax = 10;
	ay = 10;
	direccion = 0;
	animacion = 0;
	desplazamiento = 4;
	
	allegro_init();
	install_keyboard();
	
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	
	BITMAP *buffer = create_bitmap(800, 600);
	BITMAP *prota  = load_bmp("personaje.bmp",NULL);
	
	bool salir;
	int x,y;
	
	// inicializar vbles
	ax = 10;
	ay = 10;
	direccion = 0;
	animacion = 0;
	desplazamiento = 4;
	salir = false;
			
while ( !salir )
{ 
         clear_to_color(buffer, 0xaaaaaa);
          
         masked_blit(prota, buffer, animacion*32, direccion*32, x, y, 32,32);
         ax = x;
         ay = y;
         // teclas control usuario
         
		 if ( key[KEY_UP] || key[KEY_SPACE])
         {
         	for(int i = 0; i < 30; i++){
         		if(i == 0){
         			for(int f = 0; f <30; f++){
         			clear_to_color(buffer, 0xaaaaaa);
         			masked_blit(prota, buffer, animacion*32, direccion*32, x, y, 32,32);
	              	y-=desplazamiento;
	              	x+=1;
	                direccion = 3;
	                blit(buffer, screen, 0, 0, 0, 0, 800, 600);
	                rest(10);
			    	}
				 }
				clear_to_color(buffer, 0xaaaaaa);
				masked_blit(prota, buffer, animacion*32, direccion*32, x, y, 32,32);
			    y+=desplazamiento;
			    x+=1;
                direccion = 0;
                blit(buffer, screen, 0, 0, 0, 0, 800, 600);
                rest(10);
			 }       
         }
         if ( key[KEY_DOWN] )
         {
              y+=desplazamiento;
              direccion = 0;
         }
         if ( key[KEY_LEFT] )
         {
              x-=desplazamiento;
              direccion = 1;
         }
         if ( key[KEY_RIGHT] )
         {
              x+=desplazamiento;
              direccion = 2;
         }  
         if ( ax != x || ay != y )
         {
              // entra si a cambiado alguna de las variables x,y
              animacion++;
              if ( animacion > 2 ) animacion = 0;
         }                            
          
         // limites
         if ( x < 0 ) x = 0;
         if ( x > 800 ) x = 800;
         if ( y < 0 ) y = 0;
         if ( y > 600 ) y = 600;          
          
          
      blit(buffer, screen, 0, 0, 0, 0, 800, 600);
       
      rest(60);
       
      // tecla de salida
      if ( key[KEY_ESC] ) salir = true;
              
   }  
		
	destroy_bitmap(prota);
	destroy_bitmap(buffer);
	
	return 0;
}
END_OF_MAIN();
