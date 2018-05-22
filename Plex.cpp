#include"Plex.h"

void TPoint::Show(Graphics ^gr)
{
	if (visible)
	{
		if (active)
			gr->FillEllipse(Brushes::Turquoise, x - 2, y - 2, 5, 5);
		else
			gr->FillEllipse(Brushes::Black, x - 2, y - 2, 5, 5);
	}
}

void TPoint::Hide(Graphics ^gr)
{
	if (active)
	{
		visible = false;
		gr->FillEllipse(Brushes::White, x - 2, y - 2, 5, 5);
	}
}

void TPoint::Move(Graphics ^gr, int dx, int dy)
{
	Hide(gr);
	x += dx;
	y += dy;
	Show(gr);
}

//----------------------------------------------------------------------//

TChart::TChart(TRoot *pb, TRoot *pe)
{
	pBegin = pb;
	pEnd = pe;
}

void TChart::SetBegin(TRoot *pb)
{
	TPoint *tp = dynamic_cast<TPoint *>(pb);
	TChart *tc = dynamic_cast<TChart *>(pb);
	if (tc || tp)
		pBegin = pb;
}

void TChart::SetEnd(TRoot *pe)
{
	TPoint *tp = dynamic_cast<TPoint *>(pe);
	TChart *tc = dynamic_cast<TChart *>(pe);
	if (tc || tp)
		pEnd = pe;
}

TRoot * TChart::Show(Graphics ^ gr, TRoot * curr)
{
	return nullptr;
}

TRoot *TChart::Hide(Graphics ^gr, TRoot *curr)
{
	TPoint *tp, *pb, *pe;
	TChart *tc;

	tp = dynamic_cast<TPoint*>(curr);
	tc = dynamic_cast<TChart *>(curr);

	if (tp)
	{
		tp->Hide(gr);
		return(curr);
	}
	if (tc)
	{
		pb = dynamic_cast<TPoint *>(Show(gr, tc->pBegin));
		pe = dynamic_cast<TPoint *>(Show(gr, tc->pBegin));

		if (pb&&pe)
		{
			gr->DrawLine(Pens::White, pb->x, pb->y, pe->x, pe->y);
			return tc->pEnd;
		}
	}
	return nullptr;
}

void TChart::Show(Graphics ^gr)
{
	TCurrLine curr;
	TPoint *tmp;

	curr.tc = this;
	curr.pb = curr.pe = nullptr;

	while (!st.empty())
		st.pop();
	st.push(curr);

	while (!st.empty()) {
		curr = st.top();
		st.pop();

		while (!curr.pb)
		{
			tmp = dynamic_cast<TPoint *>(curr.tc->pBegin);
			if (tmp)
				curr.pb = tmp;
			else
			{
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pBegin;
			}
		}
		if (!curr.pe)
		{
			tmp = dynamic_cast<TPoint *>(curr.tc->pEnd);
			if (tmp)
				curr.pe = tmp;
			else
			{
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pEnd;
				curr.pb = nullptr;
				st.push(curr);
			}
		}
		if (curr.pb&&curr.pe) {
			if (curr.tc->visible)
			{
				if (curr.tc->active)
					gr->DrawLine(Pens::Turquoise, curr.pb->x, curr.pb->y, curr.pe->x, curr.pe->y);
				else
					gr->DrawLine(Pens::Black, curr.pb->x, curr.pb->y, curr.pe->x, curr.pe->y);
			}
			curr.pb->Show(gr);
			curr.pe->Show(gr);

			tmp = curr.pe;

			if (!st.empty())
			{
				curr = st.top();
				st.pop();

				if (!curr.pb)
					curr.pb = tmp;
				else
					curr.pe = tmp;
				st.push(curr);
			}
		}
	}
}

void TChart::Hide(Graphics ^gr) {
	TCurrLine curr;
	TPoint *tmp;

	curr.tc = this;
	curr.pb = curr.pe = nullptr;

	while (!st.empty()) {
		st.pop();
	}
	st.push(curr);

	while (!st.empty()) {
		curr = st.top();
		st.pop();

		while (!curr.pb) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pBegin);
			if (tmp) {
				curr.pb = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pBegin;
			}
		}

		if (!curr.pe) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pEnd);
			if (tmp) {
				curr.pe = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pEnd;
				curr.pb = nullptr;
				st.push(curr);
			}
		}

		if (curr.pb && curr.pe) {
			gr->DrawLine(Pens::White, curr.pb->x, curr.pb->y, curr.pe->x, curr.pe->y);
			gr->FillEllipse(Brushes::White, curr.pb->x - 2, curr.pb->y - 2, 5, 5);
			gr->FillEllipse(Brushes::White, curr.pe->x - 2, curr.pe->y - 2, 5, 5);

			tmp = curr.pe;

			if (!st.empty()) {
				curr = st.top();
				st.pop();

				if (!curr.pb) {
					curr.pb = tmp;
				}
				else {
					curr.pe = tmp;
				}

				st.push(curr);
			}
		}
	}
}

void TChart::Move(Graphics ^gr, int dx, int dy) {
	Hide(gr);

	pBegin->Move(gr, dx, dy);
	pEnd->Move(gr, dx, dy);

	Show(gr);
}

//---------------------------------------------------------------------------------------------------------------------
bool TChart::Find(int targetX, int targetY) {
	TCurrLine curr;
	TPoint *tmp;

	curr.tc = this;
	curr.pb = curr.pe = nullptr;

	while (!st.empty()) {
		st.pop();
	}
	st.push(curr);

	while (!st.empty()) {
		curr = st.top();
		st.pop();

		while (!curr.pb) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pBegin);
			if (tmp) {
				curr.pb = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pBegin;
			}
		}

		if (!curr.pe) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pEnd);
			if (tmp) {
				curr.pe = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pEnd;
				curr.pb = nullptr;
				st.push(curr);
			}
		}

		if (curr.pb && curr.pe) {
			if ((abs(curr.pb->x - targetX) < 10) && (abs(curr.pb->y - targetY) < 10)) {
				findRes = curr.tc;
				findFlag = true;
				return true;
			}

			if ((abs(curr.pe->x - targetX) < 10) && (abs(curr.pe->y - targetY) < 10)) {
				findRes = curr.tc;
				findFlag = false;
				return true;
			}

			tmp = curr.pe;

			if (!st.empty()) {
				curr = st.top();
				st.pop();

				if (!curr.pb) {
					curr.pb = tmp;
				}
				else {
					curr.pe = tmp;
				}

				st.push(curr);
			}
		}
	}
	return false;
}

TPoint *TChart::FindPoint(int targetX, int targetY) {
	TCurrLine curr;
	TPoint *tmp;

	curr.tc = this;
	curr.pb = curr.pe = nullptr;

	while (!st.empty()) {
		st.pop();
	}
	st.push(curr);

	while (!st.empty()) {
		curr = st.top();
		st.pop();

		while (!curr.pb) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pBegin);
			if (tmp) {
				curr.pb = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pBegin;
			}
		}

		if (!curr.pe) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pEnd);
			if (tmp) {
				curr.pe = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pEnd;
				curr.pb = nullptr;
				st.push(curr);
			}
		}

		if (curr.pb && curr.pe) {
			if (sqrt((curr.pb->x - targetX) * (curr.pb->x - targetX) + (curr.pb->y - targetY) * (curr.pb->y - targetY)) < 10) {
				/*TPoint *tmp = new TPoint(curr.pb->x, curr.pb->y);
				return tmp;*/
				return curr.pb;
			}

			if (sqrt((curr.pe->x - targetX) * (curr.pe->x - targetX) + (curr.pe->y - targetY) * (curr.pe->y - targetY)) < 10) {
				/*TPoint *tmp = new TPoint(curr.pe->x, curr.pe->y);
				return tmp;*/
				return curr.pe;
			}

			tmp = curr.pe;

			if (!st.empty()) {
				curr = st.top();
				st.pop();

				if (!curr.pb) {
					curr.pb = tmp;
				}
				else {
					curr.pe = tmp;
				}

				st.push(curr);
			}
		}
	}
	return nullptr;
}

TChart *TChart::Hit(int targetX, int targetY) {
	TCurrLine curr;
	TPoint *tmp;

	curr.tc = this;
	curr.pb = curr.pe = nullptr;

	while (!st.empty()) {
		st.pop();
	}
	st.push(curr);

	while (!st.empty()) {
		curr = st.top();
		st.pop();

		while (!curr.pb) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pBegin);
			if (tmp) {
				curr.pb = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pBegin;
			}
		}

		if (!curr.pe) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pEnd);
			if (tmp) {
				curr.pe = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pEnd;
				curr.pb = nullptr;
				st.push(curr);
			}
		}

		if (curr.pb && curr.pe) {
			int a = curr.pe->y - curr.pb->y;
			int b = curr.pb->x - curr.pe->x;
			int c = (curr.pb->y - curr.pe->y) * curr.pb->x + (curr.pe->x - curr.pb->x) * curr.pb->y;
			double distance = fabs(a * targetX + b * targetY + c) / sqrt(a * a + b * b);

			if (distance < 10.0) {
				return curr.tc;
			}

			tmp = curr.pe;

			if (!st.empty()) {
				curr = st.top();
				st.pop();

				if (!curr.pb) {
					curr.pb = tmp;
				}
				else {
					curr.pe = tmp;
				}

				st.push(curr);
			}
		}
	}
	return nullptr;
}

TPoint *TChart::HitPoint(int targetX, int targetY) {
	TCurrLine curr;
	TPoint *tmp;

	curr.tc = this;
	curr.pb = curr.pe = nullptr;

	while (!st.empty()) {
		st.pop();
	}
	st.push(curr);

	while (!st.empty()) {
		curr = st.top();
		st.pop();

		while (!curr.pb) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pBegin);
			if (tmp) {
				curr.pb = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pBegin;
			}
		}

		if (!curr.pe) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pEnd);
			if (tmp) {
				curr.pe = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pEnd;
				curr.pb = nullptr;
				st.push(curr);
			}
		}

		if (curr.pb && curr.pe) {
			double distanceB = sqrt((curr.pb->x - targetX) * (curr.pb->x - targetX) + (curr.pb->y - targetY) * (curr.pb->y - targetY));
			double distanceE = sqrt((curr.pe->x - targetX) * (curr.pe->x - targetX) + (curr.pe->y - targetY) * (curr.pe->y - targetY));

			if (distanceB < 10) {
				return curr.pb;
			}
			if (distanceE < 10) {
				return curr.pe;
			}

			tmp = curr.pe;

			if (!st.empty()) {
				curr = st.top();
				st.pop();

				if (!curr.pb) {
					curr.pb = tmp;
				}
				else {
					curr.pe = tmp;
				}

				st.push(curr);
			}
		}
	}
	return nullptr;
}

void TChart::MakeVisible() {
	TCurrLine curr;
	TPoint *tmp;

	curr.tc = this;
	curr.pb = curr.pe = nullptr;

	while (!st.empty()) {
		st.pop();
	}
	st.push(curr);

	while (!st.empty()) {
		curr = st.top();
		st.pop();

		while (!curr.pb) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pBegin);
			if (tmp) {
				curr.pb = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pBegin;
			}
		}

		if (!curr.pe) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pEnd);
			if (tmp) {
				curr.pe = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pEnd;
				curr.pb = nullptr;
				st.push(curr);
			}
		}

		if (curr.pb && curr.pe) {
			curr.tc->SetVisible(true);
			curr.pb->SetVisible(true);
			curr.pe->SetVisible(true);

			tmp = curr.pe;

			if (!st.empty()) {
				curr = st.top();
				st.pop();

				if (!curr.pb) {
					curr.pb = tmp;
				}
				else {
					curr.pe = tmp;
				}

				st.push(curr);
			}
		}
	}
}