#pragma once 

#include <ctime>
#include <time.h>

#include "PlayForm.h"
#include "Logic.h"
 

void Logics::Logic_Spawn_card_MyPlayer(int i)  // функція, що по правилам з числового масиву бере числа та перетворує їх у карти, та додає до спрайту основного гравця
{
		int X_card_pos, Y_card_pos; // тимчасові змінні, для пошуку кординати карти

		X_Pos_card_playerYou += 98; // зміщення позиції спрайту на одну карту, для запису нової

		if (Cards_player_you[i] < 10) // пошук координат для карти, якщо вона менше 10 з набору карт 
		{
			X_card_pos = Cards_player_you[i] - 1; // знаходження позиції Х
			Y_card_pos = 0; // та У завжди буде 0
		}
		else // інакше, якщо ця карта з якогось іншого рядка
		{
			X_card_pos = (Cards_player_you[i] % 10) - 1; // взяття координати по Х,  остачею від ділення
			Y_card_pos = (Cards_player_you[i] / 10); // взяття координати по У
		}


		player_you[i].setTextureRect(IntRect((X_card_pos * 99), (Y_card_pos * 155), 99, 155)); // взяття з спрайту, де зберігається набір карт, 
																		// той позицій де саме зберігається нова карта
		player_you[i].setPosition(X_Pos_card_playerYou, Y_Pos_card_playerYou); // додання в ряд з вже існуючими картами, нову
}


void Logics::Logic_Spawn_card_enemy_1(int i) // функція, що за правилами з числового масиву бере числа та перетворює їх на карти, та додає до спрайту ворога
{
	int X_card_pos; // тичасові змінні, для пошуку кординати карти
	int Y_card_pos;

	X_Pos_card_playerEnemy += 98; // зміщення позиції спрайту на одну карту, для запису нової

	if (Cards_player_enemy[i] < 10)
	{
		X_card_pos = Cards_player_enemy[i] - 1;
		Y_card_pos = 0;
	}
	else
	{
		X_card_pos = (Cards_player_enemy[i] % 10) - 1; // взяття координати по Х,  остачею від ділення
		Y_card_pos = (Cards_player_enemy[i] / 10);     // взяття координати по У
	}

	player_enemy[i].setTextureRect(IntRect((X_card_pos * 99), (Y_card_pos * 155), 99, 155)); // взяття з спрайту, кординати де зберіг. нова картка
	player_enemy[i].setPosition(X_Pos_card_playerEnemy, Y_Pos_card_playerEnemy); // додання в ряд з вже існуючими картами, нову

}


int Logics::proverka_card_me_player(int time_card) // логіка основного гравця, що перевіряє та повертає якусь одну карту якою можливо відбити данну карту на полі
{													 

		for (int it = 0; it < NumberOfCards_YouPlayer; it++) // ітератор по к-сті карт в колоді
		{
			int cards_enemy = Cards_player_you[it];  // взяття карти з колоди основного гравця

			for (int a = 1; a < 5; a++)
			{
				// Перевірка карт однакових за кольором
				if (time_card >= Iterator_start[a - 1] &&
					time_card <= Iterator_end[a - 1] &&
					cards_enemy >= Iterator_start[a - 1] &&  // перевірка карти, якими можливо відбитись
					cards_enemy <= Iterator_end[a - 1])
				{
					return it; // якщо така карта э, повертаэмо її номер
				}
			}
		}


		for (int i = 0; i < NumberOfCards_YouPlayer; i++)
		{
				int proverka_1 = time_card % 10; 
				int proverka_2 = Cards_player_you[i] % 10;

				// якщо за остатком від ділення, числа однакові то карти мають однакові числа (різні за кольором)
				if (proverka_1 == proverka_2) {	return i; }
		}


	return -2; // якщо немає такої картки, повертаємо -2
}


int Logics::Enemy_Player_turn()  // ф-ція, що повертає випадкову карту, якою може походити ворог
{
	int number_card = Cards_player_enemy.size(); // взяття розміру карт колоди противника

	if (Cards_player_enemy.size() != 1) { number_card--; } // якщо розмір карт не складає 1, то зменшуємо ітератор

	number_card = rand() % number_card + 0; // вибір карти з колоди, якою можливо відбитися

	return number_card; // повернути номер цієї карти
}
