#include <SFML/Graphics.hpp>

void CheckScore(sf::Sprite *sprite,sf::Texture *texture,int score, int *objectif)
{
  if(score<20)
    {
      texture->loadFromFile("images/LVL1.jpg");
      sprite->setTexture(*texture);
      *objectif=20;
    }
  else if(score<40)
    {
      texture->loadFromFile("images/LVL2.png");
      sprite->setTexture(*texture);
      *objectif=40;
    }
  else if(score==100)
    { 
      texture->loadFromFile("images/LVL3.jpg");
      sprite->setTexture(*texture);

      *objectif = 100;
    }
}
