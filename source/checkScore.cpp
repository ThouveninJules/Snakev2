#include <SFML/Graphics.hpp>

void CheckScore(sf::Sprite *sprite,sf::Texture *texture,int score, int *objectif)
{
  if(score>=20)
    {
      texture->loadFromFile("images/lvl2.png");
      sprite->setTexture(*texture);
      sprite->setTextureRect(sf::IntRect(100,100,500,500));
      *objectif=30;
    }
  else if(score <20)
    { 
      texture->loadFromFile("images/mariodrip.png");
      sprite->setTexture(*texture);
      sprite->setTextureRect(sf::IntRect(150,150,500,500));
    }
}
