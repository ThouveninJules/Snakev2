#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
void CheckScore(sf::Sprite *sprite,sf::Texture *texture,int score, int *objectif, sf::Music *song, int *debut, int *speed)
{
  if(score<20)
    {
      texture->loadFromFile("images/LVL1.jpg");
      sprite->setTexture(*texture);
      *objectif=20;
      if(*debut==1)
	{
	  *debut = 2;
	  if(!song->openFromFile("./audio/MusicLVL1.ogg"))
	    {
	      printf("La musique ne marche pas\n");
	    }
	  else
	    {
	      printf("La musique marche\n");
	      song->play();
	    }
	}
    }
  else if(score<40 && score>=20)
    {
      if(*debut==2)
	{
	  *debut = 3;
	  if(!song->openFromFile("./audio/MusicLVL2.ogg"))
	    {
	      printf("La musique ne marche pas\n");
	    }
	  else
	    {
	      song->play();
	    }
	}
      texture->loadFromFile("images/LVL2.png");
      sprite->setTexture(*texture);
      *objectif=40;
    }
  
  else if(score<100 && score>=40)
    {
      if(*debut==3)
	{
	  *debut = 4;
	  if(!song->openFromFile("./audio/MusicLVL3.ogg"))
	    {
	      printf("La musique ne marche pas\n");
	    }
	  else
	    {
	      printf("le song fonctionne");
	      song->play();
	    }
	}
      texture->loadFromFile("images/LVL3.jpg");
      sprite->setTexture(*texture);

      *objectif = 100;
    }
  else if(score>=100)
    {
      if(*debut==4)
	{
	  printf("La vitesse est à : %d\n", *speed);
	  *debut = 5;
	  if(!song->openFromFile("./audio/mscLVL4.ogg"))
	    {
	      printf("La musique ne marche pas\n");
	    }
	  else
	    {
	      //printf("le song fonctionne");
	      song->play();
	    }
	  *speed = 50;
	  printf("La vitesse change : %d\n", *speed);
	}
      texture->loadFromFile("images/LVL4.png");
      sprite->setTexture(*texture);

      *objectif = 625;
    }
}
