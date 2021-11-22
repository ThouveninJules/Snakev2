#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
void CheckScore(sf::Sprite *sprite,sf::Texture *texture,int score, int *objectif, sf::Music *song)
{
  if(score<20)
    {
      texture->loadFromFile("images/LVL1.jpg");
      sprite->setTexture(*texture);
      *objectif=20;
      if(!song->openFromFile("./audio/MusicLVL1.ogg"))
	{
	  printf("La musique ne marche pas\n");
	}
    }
  else if(score<40)
    {
      if(!song->openFromFile("./audio/MusicLVL2.ogg"))
	{
	  printf("La musique ne marche pas\n");
	}
      texture->loadFromFile("images/LVL2.png");
      sprite->setTexture(*texture);
      *objectif=40;
    }
  
  else if(score==40)
    {
      if(!song->openFromFile("./audio/MusicLVL3.ogg"))
	{
	  printf("La musique ne marche pas\n");
	}
      texture->loadFromFile("images/LVL3.jpg");
      sprite->setTexture(*texture);

      *objectif = 100;
    }
}
