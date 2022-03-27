#pragma once
#include "FormDb.h"

namespace SheduleCollageNew {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
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
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ConnrctionBtn;
	protected:

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
			this->ConnrctionBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ConnrctionBtn
			// 
			this->ConnrctionBtn->Location = System::Drawing::Point(39, 107);
			this->ConnrctionBtn->Name = L"ConnrctionBtn";
			this->ConnrctionBtn->Size = System::Drawing::Size(217, 63);
			this->ConnrctionBtn->TabIndex = 0;
			this->ConnrctionBtn->Text = L"Connect to DB";
			this->ConnrctionBtn->UseVisualStyleBackColor = true;
			this->ConnrctionBtn->Click += gcnew System::EventHandler(this, &mainForm::ConnrctionBtn_Click);
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Controls->Add(this->ConnrctionBtn);
			this->Name = L"mainForm";
			this->Text = L"mainForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ConnrctionBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		FormDb^ mf = gcnew FormDb();
		mf->Show();
		mainForm::Hide();
	}
	};
}
