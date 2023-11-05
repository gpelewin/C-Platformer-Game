////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "camera.h"
#include <Windows.h>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

void readSave()
{
	std::ifstream reading;
	int r;
	reading.open("save.txt", std::ios_base::in);
	reading >> r;
	std::cout << r;
}
void save(int a, int b)
{
	std::ofstream saving;
	saving.open("save.txt");
	saving << a;
	saving.close();
	saving.open("save.txt", std::ios_base::app);
	saving << b;
	saving.close();
}
/////////////////////////////////////////////////////////////////Меню настроек//////////////////////////////////////////////////////////////////////////////
//void Settings(RenderWindow& window2) {
//	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
//	menuTexture1.loadFromFile("resources/buttonSave.png");
//	menuTexture2.loadFromFile("resources/buttonSettings.png");
//	menuTexture3.loadFromFile("resources/buttonExit.png");
//	menuBackground.loadFromFile("resources/pauseBG.png");
//	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuBg(menuBackground);
//	bool isPause = 1;
//	int menuNum = 0;
//	menu1.setPosition(650, 450);
//	menu2.setPosition(650, 660);
//	menu3.setPosition(650, 870);
//	//-----------------------Шрифт----------------------------------//
//	sf::Font preview;
//	preview.loadFromFile("resources/MISTRAL.TTF"); //подключение шрифта
//	sf::Text pause;
//	{
//		pause.setFont(preview);
//		pause.setCharacterSize(85); //размер
//		pause.setPosition(850, 300); //расположение
//		pause.setFillColor(sf::Color(34, 53, 42)); //заливка
//		pause.setString("Настройки");
//	}
//	//-----------------------Шрифт----------------------------------//
//
//	//////////////////////////////МЕНЮ///////////////////
//	while (isPause)
//	{
//		menu1.setColor(Color::White);
//		menu2.setColor(Color::White);
//		menu3.setColor(Color::White);
//		menuNum = 0;
//		window2.clear(sf::Color(0, 0, 0));
//		if (IntRect(650, 450, 600, 150).contains(Mouse::getPosition(window2))) { menu1.setColor(sf::Color(201, 170, 185)); menuNum = 1; }
//		if (IntRect(650, 660, 600, 150).contains(Mouse::getPosition(window2))) { menu2.setColor(sf::Color(201, 170, 185)); menuNum = 2; }
//		if (IntRect(650, 870, 600, 150).contains(Mouse::getPosition(window2))) { menu3.setColor(sf::Color(201, 170, 185)); menuNum = 3; }
//
//		if (Mouse::isButtonPressed(Mouse::Left))
//		{
//			if (menuNum == 1)//если нажали первую кнопку, то выходим из меню 
//			{
//				isPause = false;
//				save(1, 6);
//			}
//			if (menuNum == 2) { window2.display(); while (!Keyboard::isKeyPressed(Keyboard::BackSpace)); }
//			if (menuNum == 3) { menu(window2); }
//
//		}
//		window2.draw(menuBg);
//		window2.draw(menu1);
//		window2.draw(menu2);
//		window2.draw(menu3);
//		window2.draw(pause);
//		window2.display();
//		if (Keyboard::isKeyPressed(Keyboard::Escape))
//		{
//			isPause = false;
//		};
//	}
//
//
//	//////////////////////////////////////////////////// МЕНЮ НАСТРОЕК *************************************************************
//}
//Начальное Меню

void menu(RenderWindow& window1) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("resources/buttonPlay.png");
	menuTexture2.loadFromFile("resources/buttonAbout.png");
	menuTexture3.loadFromFile("resources/buttonExit.png");
	aboutTexture.loadFromFile("resources/about.png");
	menuBackground.loadFromFile("resources/menuBackground.png");
	sf::View cameraMenu;
	cameraMenu.setCenter(960, 540);
	cameraMenu.setSize(1920, 1080);
	window1.setView(cameraMenu);
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(750, 450);
	menu2.setPosition(750, 660);
	menu3.setPosition(750, 870);
	menuBg.setPosition(0, 0);
	//-----------------------Шрифт----------------------------------//
	sf::Font preview;
	preview.loadFromFile("resources/preview.ttf"); //подключение шрифта
	sf::Text pauseMessage;
	{
		pauseMessage.setFont(preview);
		pauseMessage.setCharacterSize(85); //размер
		pauseMessage.setPosition(900,100); //расположение
		pauseMessage.setFillColor(sf::Color::White); //заливка
		pauseMessage.setString("game");
	}
	//-----------------------Шрифт----------------------------------//

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;


		if (IntRect(750, 450, 600, 150).contains(Mouse::getPosition(window1))) { menu1.setColor(sf::Color(232, 228, 217)); menuNum = 1; }
		if (IntRect(750, 660, 600, 150).contains(Mouse::getPosition(window1))) { menu2.setColor(sf::Color(232, 228, 217)); menuNum = 2; }
		if (IntRect(750, 870, 600, 150).contains(Mouse::getPosition(window1))) { menu3.setColor(sf::Color(232, 228, 217)); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window1.draw(about); window1.display(); while (!Keyboard::isKeyPressed(Keyboard::BackSpace)); }
			if (menuNum == 3) { window1.close(); isMenu = false; }

		}

		window1.draw(menuBg);
		window1.draw(menu1);
		window1.draw(menu2);
		window1.draw(menu3);
		window1.draw(pauseMessage);

		window1.display();
	}
	////////////////////////////////////////////////////начальное меню///////////////////////////
}
//////////////////////////////////////////////////// МЕНЮ ПАУЗЫ *************************************************************
void Pause (RenderWindow& window2) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("resources/buttonSave.png");
	menuTexture2.loadFromFile("resources/buttonSettings.png");
	menuTexture3.loadFromFile("resources/buttonExit.png");
	menuBackground.loadFromFile("resources/pauseBG.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuBg(menuBackground);
	bool isPause = 1;
	int menuNum = 0;
	sf::View cameraMenu;
	cameraMenu.setCenter(960, 540);
	cameraMenu.setSize(1920, 1080);
	window2.setView(cameraMenu);
	menu1.setPosition(650, 450);
	menu2.setPosition(650, 660);
	menu3.setPosition(650, 870);
	//-----------------------Шрифт----------------------------------//
	sf::Font preview;
	preview.loadFromFile("resources/MISTRAL.TTF"); //подключение шрифта
	sf::Text pause;
	{
		pause.setFont(preview);
		pause.setCharacterSize(85); //размер
		pause.setPosition(850, 300); //расположение
		pause.setFillColor(sf::Color(34,53,42)); //заливка
		pause.setString("PAUSE");
	}
	//-----------------------Шрифт----------------------------------//

	//////////////////////////////МЕНЮ///////////////////
	while (isPause)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window2.clear(sf::Color(0, 0, 0));
		if (IntRect(650, 450, 600, 150).contains(Mouse::getPosition(window2))) { menu1.setColor(sf::Color(201, 170, 185)); menuNum = 1; }
		if (IntRect(650, 660, 600, 150).contains(Mouse::getPosition(window2))) { menu2.setColor(sf::Color(201, 170, 185)); menuNum = 2; }
		if (IntRect(650, 870, 600, 150).contains(Mouse::getPosition(window2))) { menu3.setColor(sf::Color(201, 170, 185)); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1)//если нажали первую кнопку, то выходим из меню 
			{
				isPause = false;
				save(1,6);
			}
			if (menuNum == 2) { window2.display(); while (!Keyboard::isKeyPressed(Keyboard::BackSpace)); }
			if (menuNum == 3) { menu(window2); }

		}
		window2.draw(menuBg);
		window2.draw(menu1);
		window2.draw(menu2);
		window2.draw(menu3);
		window2.draw(pause);
		window2.display();
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			isPause = false;
		};
	}


	//////////////////////////////////////////////////// МЕНЮ ПАУЗЫ *************************************************************
}





int main()
{
	sf::RenderWindow window(sf::VideoMode(1920,1080), "Eva Game", sf::Style::Fullscreen); //отображение на полный экран
	readSave();
	view.reset(sf::FloatRect(0, 0, 640, 480));
	window.setPosition(sf::Vector2i(10, 50));
	window.setFramerateLimit(30);
	menu(window);
	sf::Music music;//создаем объект музыки
	music.openFromFile("resources/213.ogg");//загружаем файл
	music.setVolume(0); //---------------------------------------------------Громкость музыки--------------------------------------
	music.play();//воспроизводим музыку
	///////////////////////////////////////////////////////////////////Карта//////////////////////////
	sf::Image map_image;//объект изображения для карты
	map_image.loadFromFile("resources/mapLVL1.png");//загружаем файл для карты
	sf::Texture map;//текстура карты
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	sf::Sprite s_map;//создаём спрайт для карты
	s_map.setTexture(map);//заливаем текстуру спрайтом
	///////////////////////////////////////////////////////////////////Карта//////////////////////////
	//-----------------------Шрифт----------------------------------//
	sf::Font lvl1font;
	lvl1font.loadFromFile("resources/BarcadeBrawlRegular.ttf"); //подключение шрифта
	sf::Text f1;
	{
		f1.setFont(lvl1font);
		f1.setCharacterSize(36); //размер
		f1.setPosition(5, 5); //расположение
		f1.setFillColor(sf::Color::White); //заливка
		f1.setString("lvl1");
	}
	//-----------------------Шрифт----------------------------------//
	sf::Texture texture;
	if (!texture.loadFromFile("resources/ср.png"))
	{
		window.close();
		printf("Couldn't open texture");
	}
	texture.setSmooth(true);
	sf::Sprite player1;
	{
	player1.setTexture(texture);
	player1.setScale(1.15f, 1.15f);
	player1.setPosition(window.getSize().x / 2, window.getSize().y / 2);
}
	float heroteleporttimer = 0; //создаем для примера телепортации героя через 3 секунды
	sf::Clock clock; //создаем переменную времени, т.о. привязка ко времени(а не мощности/загруженности процессора). 
	sf::View camera;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		window.clear(sf::Color::Black); 
		sf::Event event;
			if (Keyboard::isKeyPressed(sf::Keyboard::Tab))
			{
				Pause(window);
			};
		clock.restart(); //перезагружает время
		time = time / 800; //скорость игры
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			sf::Vector2f pos = player1.getPosition();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // Вправо
			{
				player1.move(0.1*time, 0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //Влево
			{
				player1.move(-0.1 *time, 0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) //Вверх
			{
				player1.move(0, -0.1*time);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) //Вниз
			{
				player1.move(0, 0.1*time);
			}
			camera.setCenter(player1.getPosition().x, player1.getPosition().y);
			window.setView(camera);
			
		}
		window.draw(s_map);
		window.draw(f1);
		window.draw(player1);
		window.display();

	}
	return 0;
}
