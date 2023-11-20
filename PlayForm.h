#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include "MenuForm.h"
#include "Basis_of_the_game.h"
#include "Game_layout.h"
#include "Logic.h"
#include <thread>
#include "Field_data_.h"
 
namespace Курсовая {
	using namespace sf;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Basis_of_the_game;
	using namespace Logic_game;
	using namespace Game_layout;
	using namespace Field_data;

	/*using namespace player_you;*/

	/// <summary>
	/// Сводка для PlayForm
	/// </summary>
	public ref class PlayForm : public System::Windows::Forms::Form
	{
	public:
		PlayForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PlayForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PlayForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Font = (gcnew System::Drawing::Font(L"Javanese Text", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(49, 172);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(282, 63);
			this->button1->TabIndex = 0;
			this->button1->Text = L" ";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &PlayForm::button1_Click);
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->Location = System::Drawing::Point(49, 269);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(282, 72);
			this->button3->TabIndex = 2;
			this->button3->Text = L" ";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &PlayForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->Location = System::Drawing::Point(49, 379);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(282, 65);
			this->button4->TabIndex = 3;
			this->button4->Text = L" ";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &PlayForm::button4_Click);
			// 
			// PlayForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1301, 637);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PlayForm";
			this->Text = L"UNO!™";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
			PlayForm::Hide(); 

			Life_cycle main_game; // (основний клас, що веде життєвий цикл гри та відповідних функцій)

			Playing_field create_delete_cards; // (створення усіх текстур та спрайтів заповнення картинками: ігрового поля, карт, к-сті карт, імен гравців і т.д)

			main_game.create_delete_cards.CreateDrawCounter.Create_First_Player_Me(); // (створення текстури та спрайту з фото-картами, що будуть використ. для колоди)	 
		 	

			main_game.create_delete_cards.Random_Cards_Players(); // (виклик функції, що вибірково заповнує колоду картами основному гравцю)
			main_game.create_delete_cards.Random_Cards_Players_enemy_1(); // (виклик функції, що вибірково заповнує колоду картами противнику)


			main_game.create_delete_cards.CreateDrawCounter.Table_Score_Enemy(); // (створення статистичної табилці противника (к-сть карт, ім'я)
			main_game.create_delete_cards.CreateDrawCounter.Table_Score_Player(); //  (створення статистичної табилці основного гравця (к-сть карт, ім'я)		
			 

			main_game.create_delete_cards.CreateDrawCounter.Play_First_Player_Me(); // (заповнення спрайту картами основного гравця, виклик фун-ції 
																					// що з масиву бере номера карт()випадкових чисел) та у спеціальному
																					// порядку заповнує спрайт з картами)
																					
			
			main_game.create_delete_cards.CreateDrawCounter.Play_Enemy_Player_1();  // (заповнення спрайту картами противника, виклик фун-ції що
																					// з масиву бере номера карт()випадкових чисел) та у спеціальному
																					// порядку заповнує спрайт з картами

			main_game.Play_Logic(); // Головний цикл гри, що відповідає за відображення 
									// ігрового поля, карт, противника, рахунок, та закінчує 
									// життєвий цикл коли гра завершується (один з гравців виграє чи програє партію)

 
			   // чекає на нажаття клавіши миші по картам, після чого в
			   // залежності від ситуації оброблює 4 основні події та відповідно викликає їхні функції.
			   // 1. основний гравець ходить
			   // 2. основний гравець
			   // 3. противник ходить
			   // 4. противник відбивається
			   // після виконня основної логіки, цикл оновлює на екарн всі данні, та переходить в стан очікування натискання клавіши.
	}



	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		 MenuForm^ form2 = gcnew MenuForm();
		 form2->Show();		 
	}
		   
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		PlayForm::Close();
	}
	  

	   
	   
 
};
}
