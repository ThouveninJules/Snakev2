#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "../include/main.hpp"

int		main()
{
  

  sf::RenderWindow window(sf::VideoMode(500,500),"SFML rks");
  sf::RectangleShape snake(sf::Vector2f(20,20));
  snake.setPosition(250,250);
  snake.setFillColor(sf::Color::Green);
  sf::RectangleShape fruit(sf::Vector2f(20,20));
  fruit.setFillColor(sf::Color::Red);
  fruit.setPosition(300,100);
  window.setFramerateLimit(10);
  int var = 1;
  int size = 2;
  int size_snk = 20;//taille du snake
  srand(time(NULL));


  struct snake	       s[100];
  struct food	       f;

  s[0].x = 0;
  s[0].y = 0;
  
  f.x = 300;
  f.y = 100;
  while(window.isOpen())
    {
      
      sf::Event event;
      while(window.pollEvent(event))
	{
	  if (event.type ==sf::Event::Closed)
	    {
	      window.close();
	    }
	} 
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& var != 2){var = 0;}
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& var != 3){var = 1;}
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& var != 0){var = 2;}
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& var != 1){ var = 3;}

      if (var == 0)
	{
	  snake.move(0,-size_snk);
	  s[0].y = s[0].y - size_snk;
	}
      if (var == 1)
	{
	  snake.move(size_snk,0);
	  s[0].x = s[0].x + size_snk;
	}
      if (var == 3)
	{
	  snake.move(-size_snk,0);
	  s[0].x = s[0].x - size_snk;
	}
      if (var == 2)
	{
	  snake.move(0,size_snk);
	  s[0].y = s[0].y + size_snk;
	}

      for(int i = size ; i>0 ; i--)
	{
	  s[i].x = s[i-1].x;
	  s[i].y = s[i-1].y;
	}

      // Snake mange la pomme 
      if(s[0].x == f.x && s[0].y == f.y )	{
	  size++;
	  f.x = rand()% (500/size_snk);
	  f.y = rand()% (500/size_snk);
	  f.x = f.x*size_snk;
	  f.y = f.y*size_snk;
	  fruit.setPosition(f.x, f.y);
	}
      //Collision Serpent Mur
      if(s[0].x == 500 || s[0].x < 0 || s[0].y == 500 || s[0].y < 0)
	{
	  window.close();
	}
      // Collision tete corps

      for(int i = 2; i < size; i++)
	{
	  if (s[0].x == s[i].x && s[0].y == s[i].y)
	    {
	      // window.close();
	      printf("contact !");
	    }
	}
      
      // déplacement du serpent
      window.clear();
      for (int i = 0 ; i < size ; i++)
	{

	  snake.setPosition(s[i].x , s[i].y);
	  window.draw(fruit);
	  window.draw(snake);
	}
      window.display();
    }
  return (0);
}
