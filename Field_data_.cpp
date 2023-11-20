#pragma once

#include "Field_data_.h"

using namespace Field_data;

 
void Fill_field::Show_Table_Score() // лічільник карт противника
{
 
    if (array_of_cards_Enemy < 9)
    {
        score_enemy[1].setTextureRect(IntRect(array_of_cards_Enemy * 25, 0, 25, 79));

        score_enemy[0].setTextureRect(IntRect(0 * 25, 0, 25, 79));
    }
    else
    {
        score_enemy[1].setTextureRect(IntRect((array_of_cards_Enemy % 10) * 25, 0, 25, 79));    

        score_enemy[0].setTextureRect(IntRect((array_of_cards_Enemy / 10) * 25, 0, 25, 79));
    }
    
}

void Fill_field::Show_Table_Score_Player() // лічільник карт основного гравця
{

    if (array_of_cards_You < 9)
    {
        score_playerYou[1].setTextureRect(IntRect(array_of_cards_You * 25, 0, 25, 79));

        score_playerYou[0].setTextureRect(IntRect(0 * 25, 0, 25, 79));
    }
    else
    {
        score_playerYou[1].setTextureRect(IntRect((array_of_cards_You % 10) * 25, 0, 25, 79));

        score_playerYou[0].setTextureRect(IntRect((array_of_cards_You / 10) * 25, 0, 25, 79));
    }

}

void Fill_field::Play_First_Player_Me() // Початок гри, створюємо спрайт на 7 карт, заповнюємо текстурою
{
	 // основний гравець
 	player_you.resize(7); // створення масиву спрайтів на 7 елементів

	for (int i = 0; i < 7; i++)
	{
		player_you[i].setTexture(Cards); // додання зображення набору карт в масив
		Logic_Spawn_card_MyPlayer(i); // виклик ф-ції, що записує карти в правильному порядку в масиві
	}

}

void Fill_field::Play_Enemy_Player_1() // Створюємо противнику спрайт на 7 ел.
{
	player_enemy.resize(NumberOfCards_EnemyPlayer); // створення масиву спрайтів на 7 елементів

	for (int i = 0; i < 7; i++)
	{
		player_enemy[i].setTexture(Cards); // додання зображення набору карт в масив
		Logic_Spawn_card_enemy_1(i);  // виклик ф-ції, що записує карти в правильному порядку в масиві
	}
}

void Fill_field::Card_Draw() // функція додавання карти противнику у разі потреби добору
{
	NumberOfCards_EnemyPlayer += 1; // збільшення лічільника карт у колоді 

	 array_of_cards_Enemy += 1; // збільшення лічільника карт у статистичному таблі

	int card; // тимчасова змінна, для запису нової картки

	for (int i = 0; i < 1; i++) // цикл добору випадкової картки
	{
        card = rand() % 40 + 1; // діапазон карток від 1 до 40

		if (card == 10 || card == 20 || card == 30 || card == 40) // перевірка на виняткові картки
		{
			i -= 1;
			continue;
		}
	}

	Cards_player_enemy.push_back(card); // запис нового номеру картки в числовий масив

	player_enemy.resize(NumberOfCards_EnemyPlayer); // зміна розміру масиву спрайтів

	player_enemy[NumberOfCards_EnemyPlayer - 1].setTexture(Cards); // запис в новий елемент масиву, текстури

	Logic_Spawn_card_enemy_1(NumberOfCards_EnemyPlayer - 1); // виклик ф-ції, що записує карти в правильному порядку в масиві

}


void Fill_field::Card_Draw_Player_me() // добір карт основному гравцю
{
	Look_for_button_cards++; // збільшення змінної для пошуку натиснутої картки

	 array_of_cards_You += 1;  // збільшення лічільника карт у статистичному таблі

	NumberOfCards_YouPlayer++; // збільшення лічільника карт у колоді 

	int card; // тимчасова змінна, для запису нової картки

	for (int i = 0; i < 1; i++)  // цикл добору випадкової картки
	{
		card = rand() % 40 + 1;  // діапазон карток від 1 до 40

		if (card == 10 || card == 20 || card == 30 || card == 40)  // перевірка на виняткові картки
		{
			i -= 1;
			continue;
		}

	}

	Cards_player_you.push_back(card);  // запис нового номеру картки в числовий масив

	player_you.resize(NumberOfCards_YouPlayer); // зміна розміру масиву спрайтів

	player_you[NumberOfCards_YouPlayer - 1].setTexture(Cards);  // запис в новий елемент масиву, текстури

	Logic_Spawn_card_MyPlayer(NumberOfCards_YouPlayer - 1); // виклик ф-ції, що записує карти в правильному порядку в масиві
}