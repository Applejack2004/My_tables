#pragma once
#include"../Tree/TTable.h"
#include "../Tree/AVLTree.h"
#include"../Tree/TArrayHash.h"
#include "../Tree/TArrayTable.h"
#include"../Tree/THashTable.h"
#include "../Tree/TListHash.h"
#include"../Tree/TSortTable.h"
#include "../Tree/AVLTree.h"
#include"../Tree/TTreeTable.h"
#include<msclr\marshal_cppstd.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
TScanTable scan_table;
		TSortTable sort_table;
		TArrayHash array_hash;
		TListHash list_hash;
		TTreeTable tree_table;
		AVLTree avl_tree;

namespace WinForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		

		int flag_scan = 0;
		int flag_sort = 0;
		int flag_ar_hash = 0;
		int flag_l_hash = 0;
		int flag_tree = 0;
		int flag_avl = 0;

	private: System::Windows::Forms::Label^ label8;
	public:
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox4;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox6;
		   
		std::string generateRandomString(int length)
		{
			const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
			std::string randomString;

			// Устанавливаем seed для генератора случайных чисел
			//std::srand(time(0));

			for (int i = 0; i < length; i++) {
				randomString += charset[std::rand() % charset.length()];
			}

			return randomString;
		}
		TRecord generateRecord(const int keys_width)
		{
			std::string value = generateRandomString(7);
			int key;

			//srand(time(0));
			key = rand() % keys_width;
			TRecord record(key, value);
			return record;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

		int records_number;
		int keys_width;
		

	public protected: System::Windows::Forms::GroupBox^ Tables;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	public protected:
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton6;
	private: System::Windows::Forms::DataGridView^ Table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Key;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Value;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;



	protected:

	protected:

	protected:

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
			this->Tables = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->Table = (gcnew System::Windows::Forms::DataGridView());
			this->Key = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Value = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->Tables->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table))->BeginInit();
			this->SuspendLayout();
			// 
			// Tables
			// 
			this->Tables->Controls->Add(this->radioButton6);
			this->Tables->Controls->Add(this->radioButton5);
			this->Tables->Controls->Add(this->radioButton4);
			this->Tables->Controls->Add(this->radioButton3);
			this->Tables->Controls->Add(this->radioButton2);
			this->Tables->Controls->Add(this->radioButton1);
			this->Tables->Location = System::Drawing::Point(326, 12);
			this->Tables->Name = L"Tables";
			this->Tables->Size = System::Drawing::Size(200, 163);
			this->Tables->TabIndex = 0;
			this->Tables->TabStop = false;
			this->Tables->Text = L"Таблицы";
			this->Tables->Enter += gcnew System::EventHandler(this, &MyForm::Таблицы_Enter);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(6, 135);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(161, 17);
			this->radioButton6->TabIndex = 5;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"Сбалансированное дерево";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(7, 112);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(64, 17);
			this->radioButton5->TabIndex = 4;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Дерево";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(6, 89);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(135, 17);
			this->radioButton4->TabIndex = 3;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Хэш-таблица (список)";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(6, 66);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(137, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Хэш-таблица (массив)";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 43);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(104, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Упорядоченная";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(7, 20);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(115, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Неупорядоченная";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// Table
			// 
			this->Table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Key, this->Value });
			this->Table->Location = System::Drawing::Point(2, 14);
			this->Table->Name = L"Table";
			this->Table->Size = System::Drawing::Size(240, 402);
			this->Table->TabIndex = 1;
			this->Table->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::Table_CellContentClick);
			// 
			// Key
			// 
			this->Key->HeaderText = L"Key";
			this->Key->Name = L"Key";
			// 
			// Value
			// 
			this->Value->HeaderText = L"Value";
			this->Value->Name = L"Value";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(725, 17);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(55, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(593, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 15);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Количество записей";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(725, 57);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(55, 20);
			this->textBox2->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(593, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 15);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Диапазон ключей";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(725, 103);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(55, 20);
			this->textBox3->TabIndex = 6;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(593, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 15);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Ключ";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoEllipsis = true;
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::Window;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->Location = System::Drawing::Point(725, 293);
			this->label4->MaximumSize = System::Drawing::Size(200, 20);
			this->label4->MinimumSize = System::Drawing::Size(160, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(160, 20);
			this->label4->TabIndex = 8;
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->UseCompatibleTextRendering = true;
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(593, 296);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Резульатат";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(816, 17);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(69, 20);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Создать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(816, 57);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(69, 20);
			this->button2->TabIndex = 11;
			this->button2->Text = L"В файл";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(816, 103);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(69, 20);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Найти";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(864, 238);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(69, 20);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Добавить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(816, 152);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(69, 20);
			this->button5->TabIndex = 14;
			this->button5->Text = L"Удалить";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 441);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(88, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Эффективность";
			// 
			// label7
			// 
			this->label7->AutoEllipsis = true;
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::Window;
			this->label7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label7->Location = System::Drawing::Point(129, 441);
			this->label7->MaximumSize = System::Drawing::Size(55, 20);
			this->label7->MinimumSize = System::Drawing::Size(55, 20);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(55, 20);
			this->label7->TabIndex = 16;
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label7->UseCompatibleTextRendering = true;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(593, 197);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(129, 15);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Параметры вставки:";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(621, 220);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(37, 15);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Ключ";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(614, 238);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(55, 20);
			this->textBox4->TabIndex = 19;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(738, 220);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(63, 15);
			this->label11->TabIndex = 21;
			this->label11->Text = L"Значение";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(593, 152);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(37, 15);
			this->label12->TabIndex = 22;
			this->label12->Text = L"Ключ";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(725, 151);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(55, 20);
			this->textBox5->TabIndex = 23;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(692, 238);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(152, 20);
			this->textBox6->TabIndex = 24;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(843, 457);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(111, 33);
			this->button6->TabIndex = 25;
			this->button6->Text = L"Удалить всё";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(956, 492);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Table);
			this->Controls->Add(this->Tables);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Tables->ResumeLayout(false);
			this->Tables->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Таблицы_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Table_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
	   //Создать
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	std::string input_str1;
	input_str1 = msclr::interop::marshal_as<std::string>(textBox1->Text);
	records_number = atoi(input_str1.c_str());
	

	for (int i = 0; i < records_number-1; i++)
	{
		Table->Rows->Add();
	}

}
	   //В файл
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {


    std::string input_str2;
	input_str2 = msclr::interop::marshal_as<std::string>(textBox2->Text);
	keys_width = atoi(input_str2.c_str());
    srand(time(0));

	//Неупорядоченная таблица
	if (radioButton1->Checked)
	{
		
		for (int i = 0; i < records_number; i++)
		{
			TRecord record = generateRecord(keys_width);
			
			bool is_insert = scan_table.Insert(record);
			if (is_insert == false) {
				i--;
			}
			
		}
		int eff = scan_table.GetEfficiency();
		std::string str=std::to_string(eff); 
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		scan_table.ClearEfficiency();
		flag_scan = 1;
	}
	
	//Упорядоченная таблица
	if (radioButton2->Checked)
	{
		for (int i = 0; i < records_number; i++)
		{
			TRecord record = generateRecord(keys_width);
			
			bool is_insert = sort_table.Insert(record);
			if (is_insert == false) {
				i--;
			}
		}

		int eff = sort_table.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		sort_table.ClearEfficiency();
		flag_sort = 1;
	}

	//Хэш таблица на массиве
	if (radioButton3->Checked)
	{
		for (int i = 0; i < records_number; i++)
		{
			TRecord record = generateRecord(keys_width);
			
			bool is_insert = array_hash.Insert(record);
			if (is_insert == false) {
				i--;
			}
		}

		int eff = array_hash.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		array_hash.ClearEfficiency();
		flag_ar_hash = 1;
	}
	
	//Хэш таблица на списке
	if (radioButton4->Checked)
	{
		//std::vector<int> keys;
		for (int i = 0; i < records_number; i++)
		{
			TRecord record = generateRecord(keys_width);
			//keys.push_back(record.key);

			bool is_insert = list_hash.Insert(record);
			if (is_insert == false) {
				i--;
			}
		}

		int eff = list_hash.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		list_hash.ClearEfficiency();
		flag_l_hash = 1;
	}

	//Таблица на дереве
	if (radioButton5->Checked)
	{
		std::vector<int> keys;
		for (int i = 0; i < records_number; i++)
		{
			TRecord record = generateRecord(keys_width);
			keys.push_back(record.key);

			bool is_insert = tree_table.Insert(record);
			if (is_insert == false) {
				i--;
			}
		}

		int eff = tree_table.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		tree_table.ClearEfficiency();
		flag_tree = 1;
		std::ofstream file("output.txt"); // Открываем файл для записи
		tree_table.PrintTable(file, tree_table.getRoot()); // Выводим содержимое дерева в файл
		file.close(); // Закрываем файл
	}

	//Таблица на сбалансированном дереве
	if (radioButton6->Checked)
	{
		std::vector<int> keys;
		for (int i = 0; i < records_number; i++)
		{
			TRecord record = generateRecord(keys_width);
			keys.push_back(record.key);

			bool is_insert = avl_tree.Insert(record);
			if (is_insert == false) {
				i--;
			}
		}

		int eff = avl_tree.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		avl_tree.ClearEfficiency();
		flag_avl = 1;
		std::ofstream file2("output.txt"); // Открываем файл для записи
		avl_tree.PrintTable(file2, avl_tree.getRoot()); // Выводим содержимое дерева в файл
		file2.close(); // Закрываем файл
	}

	if (flag_scan == 1) {
		int i = 0;
		for (scan_table.Reset(); !scan_table.IsEnd(); scan_table.GoNext())
		{

			Table->Rows[i]->Cells[0]->Value = gcnew String(std::to_string(scan_table.GetCurrentRecord().key).c_str());
			Table->Rows[i]->Cells[1]->Value = gcnew String(scan_table.GetCurrentRecord().value.c_str());
			i++;
		}
	}
	if (flag_sort == 1) {
		int i = 0;
		for (sort_table.Reset(); !sort_table.IsEnd(); sort_table.GoNext())
		{

			Table->Rows[i]->Cells[0]->Value = gcnew String(std::to_string(sort_table.GetCurrentRecord().key).c_str());
			Table->Rows[i]->Cells[1]->Value = gcnew String(sort_table.GetCurrentRecord().value.c_str());
			i++;
		}
	}
	if (flag_ar_hash == 1) {
		int i = 0;
		for (array_hash.Reset(); !array_hash.IsEnd(); array_hash.GoNext())
		{

			Table->Rows[i]->Cells[0]->Value = gcnew String(std::to_string(array_hash.GetCurrentRecord().key).c_str());
			Table->Rows[i]->Cells[1]->Value = gcnew String(array_hash.GetCurrentRecord().value.c_str());
			i++;
		}
	}
	if (flag_l_hash== 1) {
		int i = 0;
		for (list_hash.Reset(); !list_hash.IsEnd(); list_hash.GoNext())
		{

			Table->Rows[i]->Cells[0]->Value = gcnew String(std::to_string(list_hash.GetCurrentRecord().key).c_str());
			Table->Rows[i]->Cells[1]->Value = gcnew String(list_hash.GetCurrentRecord().value.c_str());
			i++;
		}
	}
	if (flag_tree == 1) {
		int i = 0;
		for (tree_table.Reset(); !tree_table.IsEnd(); tree_table.GoNext())
		{

			Table->Rows[i]->Cells[0]->Value = gcnew String(std::to_string(tree_table.GetCurrentRecord().key).c_str());
			Table->Rows[i]->Cells[1]->Value = gcnew String(tree_table.GetCurrentRecord().value.c_str());
			i++;
		}
	}
	if (flag_avl == 1) {
		int i = 0;
		for (avl_tree.Reset(); i<avl_tree.GetDataCount(); avl_tree.GoNext())
		{

			Table->Rows[i]->Cells[0]->Value = gcnew String(std::to_string(avl_tree.GetCurrentRecord().key).c_str());
			Table->Rows[i]->Cells[1]->Value = gcnew String(avl_tree.GetCurrentRecord().value.c_str());
			i++;
		}
	}
} //
       
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
	   //Найти
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string input_str = msclr::interop::marshal_as<std::string>(textBox3->Text);
	int in_key = atoi(input_str.c_str());
	bool is_find;

	if (flag_scan == 1) {
		scan_table.ClearEfficiency();
		is_find = scan_table.Find(in_key);
		int eff = scan_table.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		scan_table.ClearEfficiency();
	}
	if (flag_sort == 1) {
		sort_table.ClearEfficiency();
		is_find = sort_table.Find(in_key);
		int eff = sort_table.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		sort_table.ClearEfficiency();
	}
	if (flag_ar_hash == 1) {
		array_hash.ClearEfficiency();
		is_find = array_hash.Find(in_key);
		int eff = array_hash.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		array_hash.ClearEfficiency();
	}
	if (flag_l_hash == 1) {
		list_hash.ClearEfficiency();
		is_find = list_hash.Find(in_key);
		int eff = list_hash.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		list_hash.ClearEfficiency();
	}
	if (flag_tree == 1) {
		tree_table.ClearEfficiency();
		is_find = tree_table.Find(in_key);
		int eff = tree_table.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		tree_table.ClearEfficiency();
	}
	if (flag_avl == 1) {
		avl_tree.ClearEfficiency();
		is_find = avl_tree.Find(in_key);
		int eff = avl_tree.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		avl_tree.ClearEfficiency();
	}

	std::string str;
	if (is_find)
	{
		str = "Запись найдена";
		label4->Text = gcnew String(str.c_str());
	}
	else {
		str = "Запись не найдена";
		label4->Text = gcnew String(str.c_str());
	}
}

private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
	   //Удалить
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string str_key = msclr::interop::marshal_as<std::string>(textBox5->Text);
	int in_key = atoi(str_key.c_str());
	bool is_find;

	if (flag_scan == 1) {
		scan_table.ClearEfficiency();
		is_find = scan_table.Delete(in_key);
		int eff = scan_table.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		scan_table.ClearEfficiency();
	}
	if (flag_sort == 1) {
		sort_table.ClearEfficiency();
		is_find = sort_table.Delete(in_key);
		int eff = sort_table.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		sort_table.ClearEfficiency();
	}
	if (flag_ar_hash == 1) {
		array_hash.ClearEfficiency();
		is_find = array_hash.Delete(in_key);
		int eff = array_hash.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		array_hash.ClearEfficiency();
	}
	if (flag_l_hash == 1) {
		list_hash.ClearEfficiency();
		is_find = list_hash.Delete(in_key);
		int eff = list_hash.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		list_hash.ClearEfficiency();
	}
	if (flag_tree == 1) {
		tree_table.ClearEfficiency();
		is_find = tree_table.Delete(in_key);
		int eff = tree_table.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		tree_table.ClearEfficiency();
		std::ofstream file3("output.txt"); // Открываем файл для записи
		tree_table.PrintTable(file3, tree_table.getRoot()); // Выводим содержимое дерева в файл
		file3.close(); // Закрываем файл
	}
	if (flag_avl == 1) {
		avl_tree.ClearEfficiency();
		is_find = avl_tree.Delete(in_key);
		int eff = avl_tree.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		avl_tree.ClearEfficiency();
		std::ofstream file4("output.txt"); // Открываем файл для записи
		avl_tree.PrintTable(file4, avl_tree.getRoot()); // Выводим содержимое дерева в файл
		file4.close(); // Закрываем файл
	}

	std::string str;
	if (is_find)
	{
		for (int i = 0; i < Table->Rows->Count; i++)
		{
			std::string row_value = msclr::interop::marshal_as<std::string>(Table->Rows[i]->Cells[0]->Value->ToString());
			if (row_value == str_key)
			{
				if (i == Table->Rows->Count - 1) {
					std::string clear = " ";
					Table->Rows[i]->Cells[0]->Value = gcnew String(clear.c_str());
					Table->Rows[i]->Cells[1]->Value = gcnew String(clear.c_str());
				}
				else {
					Table->Rows->RemoveAt(i);
					break;
				}
				
			}
		}
		str = "Запись удалена";
		label4->Text = gcnew String(str.c_str());
	}
	else {
		str = "Записи не существует";
		label4->Text = gcnew String(str.c_str());
	}
}
	   //Вставить
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	
	std::string input_key = msclr::interop::marshal_as<std::string>(textBox4->Text);
	int new_key = atoi(input_key.c_str());
	std::string input_value = msclr::interop::marshal_as<std::string>(textBox6->Text);
	TRecord new_record(new_key, input_value);
	bool not_is_find;

	if (flag_scan == 1) {
		scan_table.ClearEfficiency();
		not_is_find = scan_table.Insert(new_record);
		int eff = scan_table.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		scan_table.ClearEfficiency();
	}
	if (flag_sort == 1) {
		sort_table.ClearEfficiency();
		not_is_find = sort_table.Insert(new_record);
		int eff = sort_table.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		sort_table.ClearEfficiency();
	}
	if (flag_ar_hash == 1) {
		array_hash.ClearEfficiency();
		not_is_find = array_hash.Insert(new_record);
		int eff = array_hash.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		array_hash.ClearEfficiency();
	}
	if (flag_l_hash == 1) {
		list_hash.ClearEfficiency();
		not_is_find = list_hash.Insert(new_record);
		int eff = list_hash.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		list_hash.ClearEfficiency();
	}
	if (flag_tree == 1) {
		tree_table.ClearEfficiency();
		not_is_find = tree_table.Insert(new_record);
		int eff = tree_table.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		tree_table.ClearEfficiency();
		std::ofstream file5("output.txt"); // Открываем файл для записи
		tree_table.PrintTable(file5, tree_table.getRoot()); // Выводим содержимое дерева в файл
		file5.close(); // Закрываем файл
	}
	if (flag_avl == 1) {
		avl_tree.ClearEfficiency();
		not_is_find = avl_tree.Insert(new_record);
		int eff = avl_tree.GetEfficiency();
		std::string str = std::to_string(eff);
		String^ strange_str = gcnew String(str.c_str());
		label7->Text = strange_str;
		avl_tree.ClearEfficiency();
		std::ofstream file6("output.txt"); // Открываем файл для записи
		avl_tree.PrintTable(file6, avl_tree.getRoot()); // Выводим содержимое дерева в файл
		file6.close(); // Закрываем файл
	}

	std::string str;
	if (not_is_find)
	{
		Table->Rows->Clear();
		if (flag_scan == 1) {
			for (int k = 0; k < scan_table.GetDataCount() - 1; k++)
			{
				Table->Rows->Add();
			}
			int i = 0;
			for (scan_table.Reset(); !scan_table.IsEnd(); scan_table.GoNext())
			{

				Table->Rows[i]->Cells[0]->Value = gcnew String(std::to_string(scan_table.GetCurrentRecord().key).c_str());
				Table->Rows[i]->Cells[1]->Value = gcnew String(scan_table.GetCurrentRecord().value.c_str());
				i++;
			}
		}
		if (flag_sort == 1) {

			int i = 0;
			for (sort_table.Reset(); !sort_table.IsEnd(); sort_table.GoNext())
			{
				for (int k = 0; k < sort_table.GetDataCount() - 1; k++)
				{
					Table->Rows->Add();
				}
				Table->Rows[i]->Cells[0]->Value = gcnew String(std::to_string(sort_table.GetCurrentRecord().key).c_str());
				Table->Rows[i]->Cells[1]->Value = gcnew String(sort_table.GetCurrentRecord().value.c_str());
				i++;
			}
		}
		if (flag_ar_hash == 1) {
			for (int k = 0; k < array_hash.GetDataCount() - 1; k++)
			{
				Table->Rows->Add();
			}
			int i = 0;
			for (array_hash.Reset(); !array_hash.IsEnd(); array_hash.GoNext())
			{

				Table->Rows[i]->Cells[0]->Value = gcnew String(std::to_string(array_hash.GetCurrentRecord().key).c_str());
				Table->Rows[i]->Cells[1]->Value = gcnew String(array_hash.GetCurrentRecord().value.c_str());
				i++;
			}
		}
		if (flag_l_hash == 1) {
			for (int k = 0; k < list_hash.GetDataCount() - 1; k++)
			{
				Table->Rows->Add();
			}
			int i = 0;
			for (list_hash.Reset(); !list_hash.IsEnd(); list_hash.GoNext())
			{

				Table->Rows[i]->Cells[0]->Value = gcnew String(std::to_string(list_hash.GetCurrentRecord().key).c_str());
				Table->Rows[i]->Cells[1]->Value = gcnew String(list_hash.GetCurrentRecord().value.c_str());
				i++;
			}
		}
		if (flag_tree == 1) {
			for (int k = 0; k < tree_table.GetDataCount() - 1; k++)
			{
				Table->Rows->Add();
			}
			int i = 0;
			for (tree_table.Reset(); !tree_table.IsEnd(); tree_table.GoNext())
			{

				Table->Rows[i]->Cells[0]->Value = gcnew String(std::to_string(tree_table.GetCurrentRecord().key).c_str());
				Table->Rows[i]->Cells[1]->Value = gcnew String(tree_table.GetCurrentRecord().value.c_str());
				i++;
			}
		}
		if (flag_avl == 1) {
			for (int k = 0; k < avl_tree.GetDataCount() - 1; k++)
			{
				Table->Rows->Add();
			}
			int i = 0;
			for (avl_tree.Reset(); i < avl_tree.GetDataCount(); avl_tree.GoNext())
			{

				Table->Rows[i]->Cells[0]->Value = gcnew String(std::to_string(avl_tree.GetCurrentRecord().key).c_str());
				Table->Rows[i]->Cells[1]->Value = gcnew String(avl_tree.GetCurrentRecord().value.c_str());
				i++;
			}
		}
		str = "Запись добавлена";
		label4->Text = gcnew String(str.c_str());
	}
	else {
		str = "Записи уже существует";
		label4->Text = gcnew String(str.c_str());
	}
}
       //Удалить всё
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	
	//Неупорядоченная таблица
	if (flag_scan==1)
	{
		TScanTable scan_table_new;
		scan_table = scan_table_new;
		scan_table.ClearEfficiency();
		flag_scan = 0;
	}

	//Упорядоченная таблица
	if (flag_sort==1)
	{
		TSortTable sort_table_new;
		sort_table = sort_table_new;
		sort_table.ClearEfficiency();
		flag_sort = 0;
	}

	//Хэш таблица на массиве
	if (flag_ar_hash==1)
	{
		TArrayHash array_hash_new;
		array_hash = array_hash_new;
		array_hash.ClearEfficiency();
		flag_ar_hash = 0;
	}

	//Хэш таблица на списке
	if (flag_l_hash==1)
	{
		TListHash list_hash_new;
		list_hash =list_hash_new;
		list_hash.ClearEfficiency();
		flag_l_hash = 0;
	}

	//Таблица на дереве
	if (flag_tree==1)
	{
		TTreeTable tree_table_new;
		tree_table = tree_table_new;
		tree_table.ClearEfficiency();
		flag_tree = 0;
	}

	//Таблица на сбалансированном дереве
	if (flag_avl==1)
	{
		AVLTree avl_tree_new;
		avl_tree = avl_tree_new;
		avl_tree.ClearEfficiency();
		flag_avl = 0;
	}

	Table->Rows->Clear();
	std::string clear;
	String^ empty = gcnew String(clear.c_str());
	textBox1->Text = empty;
	textBox2->Text = empty;
	textBox3->Text = empty;
	textBox4->Text = empty;
	textBox5->Text = empty;
	textBox6->Text = empty;
	label7->Text = empty;
	label4->Text = empty;
}
};


}
