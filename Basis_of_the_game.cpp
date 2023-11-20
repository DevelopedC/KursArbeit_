#pragma once

#include <ctime>
#include <time.h>

#include "windows.h"

#include "Basis_of_the_game.h"


using namespace Basis_of_the_game;
		    
	void Life_cycle::Play_Logic()
	{
		VideoMode vm(1920, 1080); // �������� ������ ������
		RenderWindow window(vm, "UNO"/*,Style::Fullscreen*/); // ��������� ���� 

		 
		while (window.isOpen()) // ����, �� ������� �� �������� ����� �� ������� ����
		{
			Event event; //��������� ������� ����
			while (window.pollEvent(event)) // ���� ������� ����
			{
				if (event.type == Event::Closed) // ���� ���� �������� ����� �� ��������
				{
					window.close(); // �������� ����
					exit(0); // �� ����� � ��������
				}
			}
			 
			window.clear(); // �������� ����
            // ����������� �������� ��������� ������ ���
			window.draw(create_delete_cards.CreateDrawCounter.fon);
		    window.draw(create_delete_cards.CreateDrawCounter.Player_Enemy); 
			window.draw(create_delete_cards.CreateDrawCounter.nadscore_enemy);
			window.draw(create_delete_cards.CreateDrawCounter.Image_score_playerYou);
			window.draw(create_delete_cards.CreateDrawCounter.name_playerYou);
			
		 
            // �������� ���� ��������� ������ (�����������)
			if (me_go == true && (Mouse::isButtonPressed(Mouse::Left)))  
			{
				Vector2i mousePos = Mouse::getPosition();

                // ���� ������ ������ �����, ������� ����� �� ���� ���, 
                // ��������� ����� � ������, ��������� ����� �-�� ����, ���� ����� 
				for (int i = 1; i < create_delete_cards.CreateDrawCounter.Look_for_button_cards + 1; i++)
				{
					if (mousePos.x >= (x_start_pos + (99 * (i - 1))) && mousePos.x <= (x_start_pos + (99 * i)) && mousePos.y >= y_start_pos && mousePos.y <= y_start_pos + 154)  
					{
						Mouse::setPosition(sf::Vector2i(800, 700));
						create_delete_cards.CreateDrawCounter.player_you[i - 1].setPosition(600 + axis_offset, 460 + axis_y); 

						create_delete_cards.Delete_MeCards(i - 1);

						enemy_fair = true;
						prov_enemy_fair = false;
						me_go = false;
						axis_y = 0;

						i = create_delete_cards.CreateDrawCounter.Look_for_button_cards;
						continue;
					}
				}
			} // �������� ��������� ���� ��������� ������ (�����������)
			else if (me_fair == true && (Mouse::isButtonPressed(Mouse::Left)))  
			{
				int iter = create_delete_cards.CreateDrawCounter.Look_for_button_cards;
				Vector2i mousePos = Mouse::getPosition();

                // ���� ������ �����, ��� ������ �������� ��� ���� ��� ����� ���� ������ ���������� �����
				for (int i = 1; i < iter + 1; i++)
				{
					if (mousePos.x >= (x_start_pos + (99 * (i - 1))) && mousePos.x <= (x_start_pos + (99 * i)) && mousePos.y >= y_start_pos && mousePos.y <= y_start_pos + 154) 
					{
						Mouse::setPosition(sf::Vector2i(800, 700));

						int res;

                        // �������� ����� ���� �����, ���� ����� ������ �� ��� ��� � �� �������� ���
						if (nothing_beat == true)
						{  
							res = create_delete_cards.CreateDrawCounter.proverka_card_me_player(create_delete_cards.TIME_Cards_player_me);  
						}
						else
						{
							res = create_delete_cards.CreateDrawCounter.proverka_card_me_player(create_delete_cards.TIME_Cards_player_enemy_1);
						}

						if (res == -2)  // ���������� �� ������ ��������� � �� ���� ����� �� ���������
						{
							create_delete_cards.CreateDrawCounter.Card_Draw_Player_me();

							if (nothing_beat == true)
							{
								if (create_delete_cards.CreateDrawCounter.proverka_card_me_player(create_delete_cards.TIME_Cards_player_me) == -2)
								{
									me_fair = false;
									enemy_fair = true;
									prov_enemy_fair = false;  

									i = iter;
									continue;
								}
							}
							else
							{
								if (create_delete_cards.CreateDrawCounter.proverka_card_me_player(create_delete_cards.TIME_Cards_player_enemy_1) == -2)
								{
									me_fair = false;
									enemy_fair = true;
									prov_enemy_fair = true;

									i = iter;
									continue;
								}
							}
						}
						else if (res  == i - 1)
						{

							if (nothing_beat == true) { axis_y += 60; }

							create_delete_cards.CreateDrawCounter.player_you[i - 1].setPosition(600 + axis_offset, 460 + axis_y);  
							axis_y = 0;

							create_delete_cards.Delete_MeCards(i - 1);

							me_go = true;
							me_fair = false;

							nothing_beat = false;

							axis_offset += 100;
							i = iter;
							continue;
						}
						else
						{
							i = iter;
							continue;
						}
					}
				}
			} // �������� ���� ����������
			else if (enemy_go == true)  
			{
				int res = create_delete_cards.CreateDrawCounter.Enemy_Player_turn();

				create_delete_cards.CreateDrawCounter.player_enemy[res].setPosition(600 + axis_offset, 520); 
				create_delete_cards.Delete_CardsEnemy(res);

				enemy_go = false;
				me_fair = true;

			} // �������� ��������� ����� ���������� 
			else if (enemy_fair == true)  
			{
				int numb_card;
				int time_prov = 0;  

				if (prov_enemy_fair == false)
				{
					numb_card = create_delete_cards.Logic(create_delete_cards.TIME_Cards_player_me);
				}
				else if (prov_enemy_fair == true)
				{
					numb_card = create_delete_cards.Logic(create_delete_cards.TIME_Cards_player_enemy_1);
					time_prov = 1;
				}


				if (numb_card == -1)
				{
					create_delete_cards.CreateDrawCounter.Card_Draw(); // ��������� ����� ����������
					
                    if (time_prov == 1){
						numb_card = create_delete_cards.Logic(create_delete_cards.TIME_Cards_player_enemy_1);
					}
					else{
						numb_card = create_delete_cards.Logic(create_delete_cards.TIME_Cards_player_me);
					}

					if (numb_card == -1)
					{
						if (time_prov == 1) {nothing_beat = false;}  
						else { nothing_beat = true; }
						enemy_fair = false;
						me_fair = true;
						prov_enemy_fair = false;
					}
				}
				else if (numb_card != -1)
				{
					if (time_prov == 1){
						offset -= 60;
						time_prov = 0;
					}

					prov_enemy_fair = false;

					create_delete_cards.CreateDrawCounter.player_enemy[numb_card].setPosition(600 + axis_offset, 520 + offset);
					offset = 0;
					create_delete_cards.Delete_CardsEnemy(numb_card);

					axis_offset += 100;

					nothing_beat = false;


					enemy_fair = false;
					enemy_go = true;
				}
				else // � ��� ����, � ���������� ���� ����� �������� 
				{
					prov_enemy_fair = false;
					nothing_beat = true;

					enemy_fair = false;
					me_fair = true;
				}
			}

			create_delete_cards.CreateDrawCounter.Show_Table_Score();
			create_delete_cards.CreateDrawCounter.Show_Table_Score_Player();
			 

			for (int i = 0; i < create_delete_cards.CreateDrawCounter.NumberOfCards_YouPlayer; i++) // ������� ��� ������ (����� ������)
				window.draw(create_delete_cards.CreateDrawCounter.player_you[i]);

			for (int i = 0; i < create_delete_cards.Time_player_card_size; i++)
				window.draw(create_delete_cards.CreateDrawCounter.Time_player_cards[i]); //����������� ����, �� �������� ������� ����� � ��
			

			for (int i = 0; i < create_delete_cards.CreateDrawCounter.NumberOfCards_EnemyPlayer; i++) // ����������� ���� ������
				window.draw(create_delete_cards.CreateDrawCounter.player_enemy[i]);
			
			for (int i = 0; i < create_delete_cards.Time_EnemyPlayer_card_size; i++)
				window.draw(create_delete_cards.CreateDrawCounter.Time_EnemyPlayer_cards[i]); // ����������� ����, �� ��������� ����� � ��
		 
			for (int i = 0; i < 2; i++) // ����������� �-�� ���� � ������
			{
				window.draw(create_delete_cards.CreateDrawCounter.score_enemy[i]); 
				window.draw(create_delete_cards.CreateDrawCounter.score_playerYou[i]); 
			}
			 
			// � ��� ������� ���� ����������� �� �����
			if (create_delete_cards.CreateDrawCounter.Cards_player_you.size() == 0 && create_delete_cards.CreateDrawCounter.player_you.size() == 0)
			{

				Texture win;
				win.loadFromFile("photo/win.jpg");
				Sprite win_fon(win);
				win_fon.setTexture(win);
				 
				win_fon.setPosition(680, 250);

				window.draw(win_fon);

				window.display();

				Sleep(5000);
				window.close();
				exit(0);
			}  
            // � ��� �������� ���� ���������� ����������� �� �����
			else if(create_delete_cards.CreateDrawCounter.Cards_player_enemy.size() == 0 && create_delete_cards.CreateDrawCounter.player_enemy.size() == 0)
			{ 

				Texture lose;
				lose.loadFromFile("photo/lose.jpg");
				Sprite lose_fon(lose);
				lose_fon.setTexture(lose);

				lose_fon.setPosition(680, 250);

				window.draw(lose_fon);

				window.display();

				Sleep(5000);
				
				window.close();

				exit(0); 
			}

			window.display();
		}
	}
	 
 