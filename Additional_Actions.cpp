#pragma once

#include "Additional_Actions.h"

using namespace Additional_Actions; 
 

void Add_func::Random_Cards_Players() // роздача випадкових карт, основного гравця
{

	srand(time(NULL)); // база для генерації псевдовипадкових чисел

	for (int a = 0; a < initial_number_of_cards; a++) // цикл, що випадковим чином вибирає 7 чисел,  
	{								// які будуть використані для карт на ігровому полі
		int card = rand() % 40 + 1; // діапазон карт, від 1 до 40

		if (card == 10 || card == 20 || card == 30 || card == 40) // оброка виключень, 
		{										// в разі якщо будуть згенеровані номера карт які не використовуються,
			a -= 1;								// повертаємо цикл на одну ітерацію, та повторно отримуємо число
			continue;
		}

		CreateDrawCounter.Cards_player_you.push_back(card); // після кожної ітерації, додаємо у масив номер карти
	}

}

void Add_func::Random_Cards_Players_enemy_1() // роздача випадкових карт, противника
{

	for (int a = 0; a < initial_number_of_cards; a++) // цикл, що випадковим чином вибирає 7 чисел, номера карт
	{
		int card = rand() % 40 + 1;

		if (card == 10 || card == 20 || card == 30 || card == 40)
		{
			a -= 1;
			continue;
		}

		CreateDrawCounter.Cards_player_enemy.push_back(card); // додаємо у масив номера карт
	}

}

void Add_func::Delete_MeCards(int i) // ф-ція, що видаляє з колоди основного гравця карту, та переміщає її в масив карт де зберігається відбій  
{										 
	CreateDrawCounter.Look_for_button_cards--; // зменшуємо змінну ітератор, для пошуку вибраної карти (нажатої клавіші)

	CreateDrawCounter.X_Pos_card_playerYou -= 99; // зменшення змінної з якої починається малювання карт на ігровому полі по координаті (Х)
	CreateDrawCounter.array_of_cards_You -= 1; // зменшення ітератора к-сті карт 

	int size_vector = CreateDrawCounter.player_you.size(); // взяття масиву спрайтів, де зберігаються карти
	size_vector -= (i + 1); // віднімання від к-сті карт в масиві номер ітератора карти яка буде видалена, щоб дізнатися к-сть карт,
							//яку необхідно передвинути в бік видаленої карти 


	CreateDrawCounter.NumberOfCards_YouPlayer -= 1; // зменшуємо розмір масиву карт та спрайту основного гравця
	Time_player_card_size += 1; // збільшуємо лічильник карт основного гравця, що потрапить у відбій

	 
	TIME_Cards_player_me = CreateDrawCounter.Cards_player_you[i]; // записуємо карту у тимчасову змінну 
	CreateDrawCounter.Cards_player_you.erase(CreateDrawCounter.Cards_player_you.begin() + i); // видаляємо карту з числового масиву
	 


	CreateDrawCounter.Time_player_cards.push_back(CreateDrawCounter.player_you[i]); // записуємо карту до тимчасового масиву спрайтів
	CreateDrawCounter.player_you.erase(CreateDrawCounter.player_you.begin() + i); // видаляємо карту з масиву спрайтів


	for (int iter = 0; iter < size_vector; iter++) // зміщення всіх карт після видаленої, у бік до початку колоди
	{
		CreateDrawCounter.player_you[i].setPosition(600 + (98 * (i)), 850); // 600 х-координата та у - 850 , з якої починається малювання карт
		i++;
	}

}

void Add_func::Delete_CardsEnemy(int i) // ф-ція, що приймає ітератор карти яка буде видалена з колоди противника  
{
	CreateDrawCounter.X_Pos_card_playerEnemy -= 98; // зменшення змінної з якої починається малювання карт на ігровому полі по координаті (Х)

     
	CreateDrawCounter.array_of_cards_Enemy -= 1; // зменшення ітератора к-сті карт противника 

	int size_vector = CreateDrawCounter.player_enemy.size();
	size_vector -= (i + 1); // змінна к-сті карт після видаленої, що необхідно буде перемістити в бік початку колоди

	CreateDrawCounter.NumberOfCards_EnemyPlayer -= 1; // зменшуємо розмір масиву карт та спрайту противника
	Time_EnemyPlayer_card_size += 1; // збільшуємо лічильник к-сті карт ворога, що потрапить у відбій

 
	TIME_Cards_player_enemy_1 = CreateDrawCounter.Cards_player_enemy[i];  // записуємо карту у тимчасову змінну 
	CreateDrawCounter.Cards_player_enemy.erase(CreateDrawCounter.Cards_player_enemy.begin() + i); // видаляємо карту з числового масиву


	CreateDrawCounter.Time_EnemyPlayer_cards.push_back(CreateDrawCounter.player_enemy[i]); // записуємо карту до тимчасового масиву спрайтів
	CreateDrawCounter.player_enemy.erase(CreateDrawCounter.player_enemy.begin() + i); // видаляємо карту з масиву спрайтів


	for (int iter = 0; iter < size_vector; iter++) // зміщення всіх карт після видаленої, у бік до початку колоди
	{
		CreateDrawCounter.player_enemy[i].setPosition(600 + (98 * (i)), 100);
		i++;
	}
}

int Add_func::Logic(int time) // Логіка противкника
{
	// тимчасові змінні, що будуть використані для перевірки карт
	int card_me = time; // запис карти, що була переда в якості параметра ф-ції 
	int cards_enemy;

	for (int a = 1; a < 5; a++) // Пошук карт однакових за кольором
	{
		for (int i = 0; i < CreateDrawCounter.NumberOfCards_EnemyPlayer; i++)
		{	 
			cards_enemy = CreateDrawCounter.Cards_player_enemy[i]; // запис карт ворога
	 
			if (card_me >= CreateDrawCounter.Iterator_start[a - 1] && // перевірка карт, що треба відбити з діапазоном карт  
				card_me <= CreateDrawCounter.Iterator_end[a - 1] && // в масиві який має початок та кінець карт по кольорам
				cards_enemy >= CreateDrawCounter.Iterator_start[a - 1] &&  // та карт, що є противника у колоді,якщо така карта є повертаємо її номер
				cards_enemy <= CreateDrawCounter.Iterator_end[a - 1])
			{
				return i;
			}
		}
	}


	for (int i = 0; i < CreateDrawCounter.NumberOfCards_EnemyPlayer; i++) // Перевірка карт однакових за числами
	{
		if (card_me <= 40 && CreateDrawCounter.Cards_player_enemy[i] <= 40) 
		{
			int proverka_1 = card_me % 10; 
			int proverka_2 = CreateDrawCounter.Cards_player_enemy[i] % 10;

			if (proverka_1 == proverka_2) { return i; } // порівняння залишку від ділення номера карти, 
														// що буде дорівнювати номеру карти будь-якого кольору
		}
	}

	return -1; // якщо не було знайдено карту якою можна відбити повертаємо -1
}

 