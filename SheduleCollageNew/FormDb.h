#pragma once

namespace SheduleCollageNew {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SQLite;
	using namespace System::Data::SQLite::Linq;
	using namespace System::Data::SQLite::Generic;
	

	/// <summary>
	/// —водка дл€ FormDb
	/// </summary>
	public ref class FormDb : public System::Windows::Forms::Form
	
	{
	public:
		FormDb(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~FormDb()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ FirstColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SrcondColumn;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->FirstColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SrcondColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->FirstColumn,
					this->SrcondColumn
			});
			this->dataGridView1->Location = System::Drawing::Point(0, 32);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(270, 150);
			this->dataGridView1->TabIndex = 0;
			// 
			// FirstColumn
			// 
			this->FirstColumn->HeaderText = L"First Column";
			this->FirstColumn->MinimumWidth = 6;
			this->FirstColumn->Name = L"FirstColumn";
			this->FirstColumn->Width = 125;
			// 
			// SrcondColumn
			// 
			this->SrcondColumn->HeaderText = L"Srcond Column";
			this->SrcondColumn->MinimumWidth = 6;
			this->SrcondColumn->Name = L"SrcondColumn";
			this->SrcondColumn->Width = 125;
			// 
			// FormDb
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"FormDb";
			this->Text = L"FormDb";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormDb1(System::Object^ sender, System::EventArgs^ e) {
		SQLiteConnection^ sqlite_con;
		SQLiteCommand^ sqlite_cmd;
		SQLiteDataReader^ sqlite_datareader;
		DataTable^ sqlDt = gcnew DataTable();
		//SQLite^ sqlDtA = gcnew SQLiteAdapter();
		//sqlite_datareader^ sqlRd;
		sqlite_con = gcnew SQLiteConnection("Data Source = mydb.db; Version=3; New=False; Compress=True;");
		sqlite_con->Open();
		sqlite_cmd = sqlite_con->CreateCommand();
		sqlite_cmd->CommandText = ("SELECT * FROM firstTable");
		sqlite_cmd->ExecuteNonQuery();

		sqlite_datareader = sqlite_cmd->ExecuteReader();
		sqlDt->Load(sqlite_datareader);
		sqlite_datareader->Close();
		sqlite_con->Close();
		dataGridView1->DataSource = sqlDt;
		//Success
	}
	};
}
