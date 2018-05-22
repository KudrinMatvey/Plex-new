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
		TChart *pFirst;
		TPoint *p1, *p2,*currentPoint;
		int x1, x2, y1, y2;
		bool flag;


		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			flag = false;
			pFirst = NULL;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(769, 557);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

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
};
};

