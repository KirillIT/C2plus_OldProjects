#pragma once

namespace Project1 {

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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			this->chart1->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 12);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Color = System::Drawing::Color::Red;
			series1->Legend = L"Legend1";
			series1->Name = L"x^3 + y^3 - 3Fxy = 0";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(1278, 929);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1296, 52);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(402, 76);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Построить график";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1296, 134);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(402, 76);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Стереть всё";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1296, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Чему будет равно F\?";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1296, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"F = 2 по умолчанию";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(1415, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(283, 20);
			this->textBox1->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1710, 953);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	
private: double a, b, h, x, y, F;
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	a = -9.999;
	b = 10;
	h = 0.001;
	x = a;
	double Q, R, t, sign, A, B;

	if (textBox1->Text == "") { F = 2; }
	else {


		F = Convert::ToDouble(textBox1->Text);

	}
	while (x <= b) {
		Q = -3 * -3 * x * F / 9;
		R = 27 * Math::Pow(x, 3)/54;


		if (Math::Pow(R, 2) < Math::Pow(Q, 3)) {
			t = Math::Acos(R / Math::Sqrt(Math::Pow(Q, 3))) / 3;
			this->chart1->Series[0]->Points->AddXY(x, -2 * Math::Sqrt(Q) * Math::Cos(t));
			this->chart1->Series[0]->Points->AddXY(x, -2 * Math::Sqrt(Q) * Math::Cos(t + 2 * Math::PI / 3));
			this->chart1->Series[0]->Points->AddXY(x, -2 * Math::Sqrt(Q) * Math::Cos(t - 2 * Math::PI / 3));
		}


		else {

			if (R >= 0) { sign = 1; }
			else { sign = -1; }
			A = -sign * Math::Pow(Math::Abs(R) + Math::Sqrt(Math::Pow(R, 2) - Math::Pow(Q, 3)), 1 / 3.0);
			if (A == 0) {
				B = 0;
			}
			else {

				B = Q / A;
			}
			this->chart1->Series[0]->Points->AddXY(x, A + B);


			if (A == B) {

				this->chart1->Series[0]->Points->AddXY(x, -A);

			}


		}
		x += h;
	}

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->chart1->Series[0]->Points->Clear();

}

};
}
