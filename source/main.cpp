#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include "../include/main.hpp"
#include "../include/checkScore.hpp"


int		main()
{
  

  sf::RenderWindow window(sf::VideoMode(500,550),"LUIGI KART DELUXE TAH LES ANCIENS");
  sf::Sprite snake;
  snake.setPosition(250,250);
  sf::Sprite fruit;
  fruit.setPosition(300,100);
  window.setFramerateLimit(10);
  int var = 1;
  int size = 2;
  int speed = 10;
  int score = 0;
  int objectif = 20;
  int pause = 0;
  int debut = 0;
  char aff[50]="";
  char off[50]="";
  int size_snk = 20;//taille du snake
  srand(time(NULL));
  bool mort = false;
  sf::Texture texture, textureFruit, textureHead;
  sf::Music song;
  sf::Sprite sprite; 
  sf::Text text;
  sf::Text obj;
  sf::Font font;
  font.loadFromFile("include/arial.ttf");
  sprintf(aff, "Score : %d", score);
  text.setString(aff);
  text.setFont(font);
  text.setCharacterSize(45);
  text.setFillColor(sf::Color::White);
  text.setPosition(5,495);
  sprintf(off, "Objectif : %d", objectif);
  obj.setString(off);
  obj.setFont(font);
  obj.setCharacterSize(40);
  obj.setFillColor(sf::Color::White);
  obj.setPosition(255,500);
  
  struct snake	       s[100];
  struct food	       f;

  s[0].x = 0;
  s[0].y = 0;
  
  f.x = 300;
  f.y = 100;

  if(!textureHead.loadFromFile("./images/champi.png"))
    {
      printf("L'image  ne marche pas\n");
      return -1;
    }
  snake.setTexture(textureHead);
  snake.setScale(sf::Vector2f(1,1));

  if(!textureFruit.loadFromFile("./images/champi.png"))
    {
      printf("L'image  ne marche pas\n");
      return -1;
    }
  fruit.setTexture(textureFruit);
  fruit.setScale(sf::Vector2f(1,1));

  CheckScore(&sprite, &texture,score, &objectif, &song, &debut);
  song.setVolume(50);
  song.setLoop(true);
  //song.play();
  
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

      // GESTION MENU
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || debut == 0)
	{
	  if(debut == 0)
	    {
	      pause = 2;
	      debut = 1;
	    }else{
	    pause = 0;
	  }
	  while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	    {
	      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pause != 1 && pause !=3)
		{
		  //printf("pause = 1");
		  pause++;
		}
	      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pause != 0 && pause != 2)
		{
		  //printf("pause = 0");
		  pause--;
	        }
	      
	      window.clear();
	      
	      switch(pause)
		{
		case 0 :
		  //printf("img cont 0");
		  texture.loadFromFile("images/menu_pause_cont.png");
		  window.draw(text);
		  window.draw(obj);
		  break; 
		case 1 :
		  //printf("img quit 1");
		  texture.loadFromFile("images/menu_pause_quit.png");
		  window.draw(text);
		  window.draw(obj);
		  break;
	        case 2 :
		  //printf("img comm 2");
		  texture.loadFromFile("images/menu_deb_comm.png");
		  break;
		case 3 :
		  //printf("img quit 3");
		  texture.loadFromFile("images/menu_deb_quit.png");
		  break;
		default :
		  //printf("img cont def");
		  texture.loadFromFile("images/menu_deb_comm.png");
		  break;
		}
	      sprite.setTexture(texture);
	      sprite.setTextureRect(sf::IntRect(0,0,500,500));
	      window.draw(sprite);
	      window.display();
	    }
	  switch(pause)
	    {
	    case 0 :
	      CheckScore(&sprite, &texture, score, &objectif, &song, &debut);
	      break;
	    case 1 :
	      window.close();
	      break;
	    case 2 :
	      CheckScore(&sprite, &texture, score, &objectif, &song, &debut);
	      break;
	    case 3 :
	      window.close();
	      break;
	    default :
	      CheckScore(&sprite,&texture,score, &objectif, &song, &debut);
	      break;
	    }
	}
      // FIN GESTION MENU


      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& var != 2){var = 0;}
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& var != 3){var = 1;}
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& var != 0){var = 2;}
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& var != 1){ var = 3;}

      CheckScore(&sprite,&texture,score, &objectif, &song, &debut);
      
      if (var == 0)
	{
	  //textureHead.loadFromFile("images/luigi.png");
	  //snake.setTexture(textureHead);
	  snake.move(0,-size_snk);
	  s[0].y = s[0].y - size_snk;
	}
      if (var == 1)
	{
	  //textureHead.loadFromFile("images/luigiDrt.png");
          //snake.setTexture(textureHead);
	  snake.move(size_snk,0);
	  s[0].x = s[0].x + size_snk;
	}
      if (var == 3)
	{
	  //textureHead.loadFromFile("images/luigiGch.png");
          //snake.setTexture(textureHead);
	  snake.move(-size_snk,0);
	  s[0].x = s[0].x - size_snk;
	}
      if (var == 2)
	{
	  //textureHead.loadFromFile("images/luigiBas.png");
          //snake.setTexture(textureHead);
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
	
	//score
	score++;
	
	//vitesse +1 tous les 5 points
	if(score % 5 == 0)
	      {
		speed++;
		window.setFramerateLimit(speed);
	      }
	
	//position du fruit
	fruit.setPosition(f.x, f.y);
	
	//vérification de f par rapport à s
	for(int i = 0; i < size; i++)
	  {
	    if(s[i].x == f.x && s[i].y == f.y)
	      {
		f.x = rand()% (500/size_snk);
		f.y = rand()% (500/size_snk);
		f.x = f.x*size_snk;
		f.y = f.y*size_snk;
		fruit.setPosition(f.x, f.y);
	      }
	  }
      }
      //Collision Serpent Mur
      if(s[0].x == 500 || s[0].x < 0 || s[0].y == 500 || s[0].y < 0)
	{
	  mort = true;
	  //printf("Votre score est : %d\n", score);
	  //window.close();
	}
      // Collision tete corps
      
      for(int i = 2; i < size; i++)
	{
	  if (s[0].x == s[i].x && s[0].y == s[i].y)
	    {
	      mort = true;
	    }
	}
      
      // déplacement du serpent
      sprintf(aff, "Score : %d", score);
      text.setString(aff);
      sprintf(off, "Objectif : %d", objectif);
      obj.setString(off);
      window.clear();
      window.draw(sprite);
      window.draw(text);
      window.draw(obj);

      // Gestion Mort 
      if (mort == true)
	{
	  song.openFromFile("./audio/MusicMort.ogg");
	  song.setLoop(false);
	  song.setVolume(50);
	  song.play();
	  printf("vous avez perdu \n");
	  printf("Votre score est : %d\n", score);

	  while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	    {
	      window.clear();
	      texture.loadFromFile("./images/GameOver.png");
	      sprite.setTexture(texture);
	      window.draw(sprite);
	      window.display();
	      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
		  window.close();
		}
	    }
	  CheckScore(&sprite,&texture,score, &objectif, &song, &debut);
	  snake.setPosition(250,250);
	  fruit.setPosition(300,100);
	  var = 1;
	  s[0].x = 0;
	  s[0].y = 0;
	  size = 2;
	  speed = 10;
	  score = 0;
	  objectif = 20;
	  pause = 0;
	  debut = 0;
	  f.x = 300;
	  f.y = 100;
	  size_snk = 20;
	  mort = false;
	}
	  for (int i = 0 ; i < size ; i++)
	    {
	      if(i==0)
		{
		  if(var==0)
		    {
		      if(!textureHead.loadFromFile("./images/luigi.png"))
			{
			  printf("L'image  ne marche pas\n");
			  return -1;
			}
		      snake.setTexture(textureHead);
		      snake.setScale(sf::Vector2f(1,1));
		    }
		  else if(var==1)
		    {
		      if(!textureHead.loadFromFile("./images/luigiDrt.png"))
			{
			  printf("L'image  ne marche pas\n");
			  return -1;
			}
		      snake.setTexture(textureHead);
		      snake.setScale(sf::Vector2f(1,1));
		    }
		  else if(var==2)
		    {
		      if(!textureHead.loadFromFile("./images/luigiBas.png"))
			{
			  printf("L'image  ne marche pas\n");
			  return -1;
			}
		      snake.setTexture(textureHead);
		      snake.setScale(sf::Vector2f(1,1));
		    }
		  else if(var==3)
		    {
		      if(!textureHead.loadFromFile("./images/luigiGch.png"))
			{
			  printf("L'image  ne marche pas\n");
			  return -1;
			}
		      snake.setTexture(textureHead);
		      snake.setScale(sf::Vector2f(1,1));
		    }
		}
	      else if(i==2)
		{
		  if(score<20)
		    {
		      if(!textureHead.loadFromFile("./images/carapVrt.png"))
			{
			  printf("L'image  ne marche pas\n");
			  return -1;
			}
		      snake.setTexture(textureHead);
		      snake.setScale(sf::Vector2f(1,1));
		    }
		  else if(score>=20 && score<40)
		    {
		      if(!textureHead.loadFromFile("./images/carapRge.png"))
			{
			  printf("L'image  ne marche pas\n");
			  return -1;
			}
		      snake.setTexture(textureHead);
		      snake.setScale(sf::Vector2f(1,1));
		    }
		  else if(score>=40)
		    {
		      if(!textureHead.loadFromFile("./images/carapBle.png"))
			{
			  printf("L'image  ne marche pas\n");
			  return -1;
			}
		      snake.setTexture(textureHead);
		      snake.setScale(sf::Vector2f(1,1));
		    }
		}
	      snake.setPosition(s[i].x , s[i].y);
	      window.draw(fruit);
	      window.draw(snake);
	    }
	  window.display();
	
    }
  return (0);
}
  
