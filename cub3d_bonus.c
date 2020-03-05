#include "mlx.h"
#include "math.h"
#include "stdio.h"
#define mapWidth 10
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	draw_vertical2(void *mlx, void *window, int x, int drawStart, int drawEnd, int color)
{
	while (drawStart < drawEnd)
	{
		mlx_pixel_put(mlx, window, x, drawStart, color);
		drawStart++;
	}
}

int main(void)
{
  int w = 1080;
  int h = 1920;
  double posX = 5, posY = 3;  //x and y start position
  double dirX = -1, dirY = 0; //initial direction vector
  double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

  void *mlx = mlx_init();
  void *window = mlx_new_window(mlx, w, h, "Ray SkyCuber");
  while (1)
  {
    for(int x = 0; x < w; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;
      //which box of the map we're in
      int mapX = (int)posX;
      int mapY = (int)posY;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = fabs(1 / rayDirX);
      double deltaDistY = fabs(1 / rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
	printf("\nrayDirX : %f\n", rayDirX);
	printf("rayDirY : %f\n", rayDirY);
	printf("DirX : %f\n", dirX);
	printf("DirY : %f\n", dirY);
	printf("mapX : %d\n", mapX);
	printf("mapY : %d\n", mapY);
	printf("posX : %f\n", posX);
	printf("posY : %f\n", posY);
	printf("cameraX :%f\n", cameraX);
	printf("deltaDistX : %f\n", deltaDistX);
	printf("deltaDistY : %f\n", deltaDistY);
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if(worldMap[mapX][mapY] > 0) hit = 1;
		printf("sideDistX : %f\n", sideDistX);
		printf("sideDistY : %f\n", sideDistY);
      }
	
	printf("side : %d\n", side);
      //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if (side == 0)
	  	perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
      else
	  	perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
	printf("perpWallDist : %f\n", perpWallDist);
      //Calculate height of line to draw on screen
      int lineHeight = (int)(h / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + h / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + h / 2;
      if(drawEnd >= h)drawEnd = h - 1;
	printf("lineHeight : %d\n", lineHeight);
	printf("drawStart : %d, drawEnd : %d\n", drawStart, drawEnd);
      //choose wall color
      int color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = 255255;    break; //red
        case 2:  color = 255255;  break; //green
        case 3:  color = 255255;   break; //blue
        case 4:  color = 255255;  break; //white
        default: color = 255255; break; //yellow
      }

      //give x and y sides different brightness
      if(side == 1)
	  	color = color / 2;

      //draw the pixels of the stripe as a vertical line
      draw_vertical2(mlx, window, x, drawStart, drawEnd, color);
	}
	mlx_loop(mlx);
  }
}
