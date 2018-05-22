#pragma once
#include <stack>

using namespace std;
using namespace System::Drawing;

class TRoot;
class TPoint;
class TChart;

struct TCurrLine {
	TChart *tc;
	TPoint *pb;
	TPoint *pe;
};

class TRoot {
protected:
	bool visible;
	bool active;
public:
	TRoot(bool _visible = true, bool _active = false) {
		visible = _visible;
		active = _active;
	}

	virtual void Show(Graphics ^gr) = 0;
	virtual void Hide(Graphics ^gr) = 0;
	virtual void Move(Graphics ^gr, int dx, int dy) = 0;

	void SetActive(bool val) { active = val; }
	void SetVisible(bool val) { visible = val; }

	bool GetActive() { return active; }
	bool GetVisible() { return visible; }
};

class TPoint : public TRoot {
public:
	int x;
	int y;
public:
	TPoint(int _x = 0, int _y = 0) : TRoot() {
		x = _x;
		y = _y;
	}

	virtual void Show(Graphics ^gr);
	virtual void Hide(Graphics ^gr);
	virtual void Move(Graphics ^gr, int dx, int dy);
};



class TChart :public TRoot {
protected:
	TRoot *pBegin;
	TRoot *pEnd;
	stack<TCurrLine> st;
public:
	TChart *findRes;
	bool findFlag; // it returns true if the finding point is begining of the line and false if the point is ending
public:
	TChart(TRoot *pb = nullptr, TRoot *pe = nullptr);

	void SetBegin(TRoot *pb);
	void SetEnd(TRoot *pe);

	TRoot *GetBegin() { return pBegin; }
	TRoot *GetEnd() { return pEnd; }

	TRoot *Show(Graphics ^gr, TRoot *curr);
	TRoot *Hide(Graphics ^gr, TRoot *curr);

	virtual void Show(Graphics ^gr);
	virtual void Hide(Graphics ^gr);
	virtual void Move(Graphics ^gr, int dx, int dy);

	bool Find(int targetX, int targetY);
	TPoint *FindPoint(int targetX, int targetY);

	TChart *Hit(int targetX, int targetY);
	TPoint *HitPoint(int targetX, int targetY);

	void MakeVisible();
};