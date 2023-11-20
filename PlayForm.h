#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include "MenuForm.h"
#include "Basis_of_the_game.h"
#include "Game_layout.h"
#include "Logic.h"
#include <thread>
#include "Field_data_.h"
 
namespace �������� {
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
	/// ������ ��� PlayForm
	/// </summary>
	public ref class PlayForm : public System::Windows::Forms::Form
	{
	public:
		PlayForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
			this->Text = L"UNO!�";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
			PlayForm::Hide(); 

			Life_cycle main_game; // (�������� ����, �� ���� ������� ���� ��� �� ��������� �������)

			Playing_field create_delete_cards; // (��������� ��� ������� �� ������� ���������� ����������: �������� ����, ����, �-�� ����, ���� ������� � �.�)

			main_game.create_delete_cards.CreateDrawCounter.Create_First_Player_Me(); // (��������� �������� �� ������� � ����-�������, �� ������ ��������. ��� ������)	 
		 	

			main_game.create_delete_cards.Random_Cards_Players(); // (������ �������, �� �������� ������� ������ ������� ��������� ������)
			main_game.create_delete_cards.Random_Cards_Players_enemy_1(); // (������ �������, �� �������� ������� ������ ������� ����������)


			main_game.create_delete_cards.CreateDrawCounter.Table_Score_Enemy(); // (��������� ����������� ������� ���������� (�-��� ����, ��'�)
			main_game.create_delete_cards.CreateDrawCounter.Table_Score_Player(); //  (��������� ����������� ������� ��������� ������ (�-��� ����, ��'�)		
			 

			main_game.create_delete_cards.CreateDrawCounter.Play_First_Player_Me(); // (���������� ������� ������� ��������� ������, ������ ���-��� 
																					// �� � ������ ���� ������ ����()���������� �����) �� � ������������
																					// ������� ������� ������ � �������)
																					
			
			main_game.create_delete_cards.CreateDrawCounter.Play_Enemy_Player_1();  // (���������� ������� ������� ����������, ������ ���-��� ��
																					// � ������ ���� ������ ����()���������� �����) �� � ������������
																					// ������� ������� ������ � �������

			main_game.Play_Logic(); // �������� ���� ���, �� ������� �� ����������� 
									// �������� ����, ����, ����������, �������, �� ������ 
									// ������� ���� ���� ��� ����������� (���� � ������� ����� �� ������ �����)

 
			   // ���� �� ������� ������ ���� �� ������, ���� ���� �
			   // ��������� �� �������� �������� 4 ������ ��䳿 �� �������� ������� ��� �������.
			   // 1. �������� ������� ������
			   // 2. �������� �������
			   // 3. ��������� ������
			   // 4. ��������� ����������
			   // ���� ������� ������� �����, ���� ������� �� ����� �� ����, �� ���������� � ���� ���������� ���������� ������.
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
