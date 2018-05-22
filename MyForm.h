#pragma once
#include"Plex.h"
namespace Plex_new {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Graphics ^gr;
		TChart *plex;
		TChart *pCurr;
		TPoint *p1, *p2,*currentPoint;
		int x1, x2, y1, y2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	public:
		bool flag;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	public:
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button4;
			 bool mouse;

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			flag = false;
			mouse = false;
			plex = NULL;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(745, 495);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			this->pictureBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDoubleClick);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 513);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 51);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Show curr line";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(119, 513);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 51);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Show curr point";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(234, 514);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(101, 50);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Deletion Mode";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(384, 513);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 4;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(384, 541);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 22);
			this->numericUpDown2->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(342, 513);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"dX:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(342, 541);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"dY:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(511, 513);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(78, 45);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Move";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(769, 565);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
	/*	if (mouseDown) {
			x1 = e->Location.X;
			y1 = e->Location.Y;
			p1 = new TPoint(x1, y1);
			p1->Show(gr);
			mouseDown = false;
		}
		else
		{
			x2 = e->Location.X;
			y2 = e->Location.Y;
			p2 = new TPoint(x2, y2);
			p2->SetActive(true);
			TChart tc(p1, p2);
			tc.Show(gr);
			mouseDown = true;
		}*/
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		gr = pictureBox1->CreateGraphics();
	}
	private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
		
	}
	private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		flag = true;
		x1 = x2 = e->X;
		y1 = y2 = e->Y;
	}
private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (flag)
	{
		gr->DrawLine(Pens::White, x1, y1, x2, y2);
		x2 = e->X;
		y2 = e->Y;
		gr->DrawLine(Pens::Black, x1, y1, x2, y2);
		}
}
private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	flag = false;
	if (plex == NULL)
	{		
		p1 = new TPoint(x1, y1);
		p2 = new TPoint(x2, y2);
		plex = new TChart;
		plex->SetBegin(p1);
		plex->SetEnd(p2);
		plex->Show(gr);
		currentPoint = p2;
		currentPoint->SetActive(1);
	}
	else {
		p1->SetActive(0);
		p2->SetActive(0);
		bool find1 = plex->Find(x1, y1), find2 = plex->Find(x2, y2);
		
		if (find1 && find2) {

			p1 = plex->FindPoint(x1, y1);
			p2 = plex->FindPoint(x2, y2);

			TChart *tmp = new TChart();
			TPoint *tmp1 = (TPoint *)(plex->findRes->GetBegin());
			TPoint *tmp2 = (TPoint *)(plex->findRes->GetEnd());

			if (plex->findFlag)
			{
				if ((p1->x == tmp1->x) && (p1->y == tmp1->y)) {
					tmp->SetEnd(p1);
					tmp->SetBegin(p2);
				}
				else if ((p2->x == tmp1->x) && (p2->y == tmp1->y)) {
					tmp->SetEnd(p2);
					tmp->SetBegin(p1);
				}
				plex->findRes->SetBegin(tmp);
			}
			else {
				if ((p1->x == tmp2->x) && (p1->y == tmp2->y)) {
					tmp->SetEnd(p1);
					tmp->SetBegin(p2);
				}
				else if ((p2->x == tmp2->x) && (p2->y == tmp2->y)) {
					tmp->SetEnd(p2);
					tmp->SetBegin(p1);
				}
				plex->findRes->SetEnd(tmp);
			}
			p1->SetActive(0);
			p2->SetActive(1);
		}
		else if (find1)
		{
			p2 = new TPoint(x2, y2);

			if (plex->findFlag) {
				p1 = (TPoint *)plex->findRes->GetBegin();
			}
			else {
				p1 = (TPoint *)plex->findRes->GetEnd();
			}

			TChart *tmp = new TChart();
			tmp->SetBegin(p2);
			tmp->SetEnd(p1);

			if (plex->findFlag) {
				plex->findRes->SetBegin(tmp);
			}
			else {
				plex->findRes->SetEnd(tmp);
			}
			p1->SetActive(0);
			p2->SetActive(1);
		}
		else if (find2) 
		{
			p1 = new TPoint(x1, y1);

			if (plex->findFlag) {
				p2 = (TPoint *)plex->findRes->GetBegin();
			}
			else {
				p2 = (TPoint *)plex->findRes->GetEnd();
			}

			TChart *tmp = new TChart();
			tmp->SetBegin(p1);
			tmp->SetEnd(p2);

			if (plex->findFlag) {
				plex->findRes->SetBegin(tmp);
			}
			else {
				plex->findRes->SetEnd(tmp);
			}
		}
		p2->SetActive(0);
		p1->SetActive(1);
	}
	gr->DrawLine(Pens::White, x1, y1, x2, y2);
	plex->Hide(gr);
	plex->Show(gr);
}
	private: System::Void pictureBox1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (mouse) {

			if (currentPoint != nullptr) currentPoint->SetActive(0);
			currentPoint = nullptr;
			currentPoint = plex->HitPoint(e->X, e->Y);
			if (currentPoint == nullptr) {
				if (pCurr != nullptr) pCurr->SetActive(0);
				pCurr = plex->Hit(e->X, e->Y);
				pCurr->SetActive(1);
				pCurr->SetVisible(0);
			}
			else
			{
				currentPoint->SetVisible(0);
				currentPoint->SetActive(1);
			}



			/*if (pCurr != nullptr) pCurr->SetActive(0);
			pCurr = plex->Hit(e->X, e->Y);
			if (pCurr != nullptr) {
				pCurr->SetVisible(0);
				pCurr->SetActive(1);
			}
			if (currentPoint != nullptr) currentPoint->SetActive(0);
			currentPoint = plex->HitPoint(e->X, e->Y);
			if (currentPoint != nullptr) {
				currentPoint->SetVisible(0);
				pCurr->SetActive(1);
			}*/
		}
			else
			{
				if (currentPoint != nullptr) currentPoint->SetActive(0);
				currentPoint = nullptr;
				currentPoint = plex->HitPoint(e->X, e->Y);
				if (currentPoint == nullptr) {
					if (pCurr != nullptr) pCurr->SetActive(0);
					pCurr = plex->Hit(e->X, e->Y);
					pCurr->SetActive(1);
				}
			}
		
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (pCurr != nullptr && !pCurr->GetVisible())
	{
		pCurr->SetVisible(1);
		plex->Hide(gr);
		plex->Show(gr);
		button1->Text = "Hide curr line";
	}
	else if (pCurr != nullptr && pCurr->GetVisible())
	{
		pCurr->SetVisible(0);
		plex->Hide(gr);
		plex->Show(gr);
		button1->Text = "Show curr line";
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (currentPoint != nullptr && !currentPoint->GetVisible())
	{
		currentPoint->SetVisible(1);
		plex->Hide(gr);
		plex->Show(gr);
		button2->Text = "Hide curr point";
	}
	else if (currentPoint != nullptr && currentPoint->GetVisible())
	{
		currentPoint->SetVisible(0);
		plex->Hide(gr);
		plex->Show(gr);
		button2->Text = "Show curr point";
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	mouse = 1 - mouse;
	if (mouse)
		button3->Text = "Selection Mode";
	else
		button3->Text = "Deletion Mode";
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	if (plex != NULL)
		plex->Move(gr, (int)numericUpDown1->Value, (int)numericUpDown2->Value);

}
};
};

