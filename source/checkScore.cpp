#include <SFML/Graphics.hpp>

void CheckScore(sf::Sprite *sprite,sf::Texture *texture,int score)
{
  if(score>20)
    {
      texture->loadFromFile("images/lvl2.png");
      sprite->setTexture(*texture);
      sprite->setTextureRect(sf::IntRect(150,150,500,500));
    }
  else if(score <20)
    { 
      texture->loadFromFile("images/mariodrip.png");
      sprite->setTexture(*texture);
      sprite->setTextureRect(sf::IntRect(150,150,500,500));
    }
}
