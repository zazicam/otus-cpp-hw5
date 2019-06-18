#pragma once

#include <list>

#include "framework.hpp"

#include "shape.hpp"

class TToolManager;
class TTool;
class TCompositor;
class TVisitor;

class TToolManager {
    std::list<TTool*> Items;
    TPoint Pos;
public:
    TToolManager(TPoint p);
    virtual ~TToolManager();
    void AddTool(TTool* tool);
    int GetCount();
    TTool* GetTool(int Handle);
    int GetActive(void);
    TPoint GetPosition(void);
};

class TTool {
    int Handle;
    bool Active;
public:
    TTool(int Handle);
    int GetHandle(void);
    bool IsActive(void);
    void SetActive(void) {Active=true;};
    void SetInactive(void) {Active=false;};
    
    virtual void MouseDown(bool right,int X,int Y);
    virtual void MouseMove(int X,int Y);
    virtual void MouseUp(int X,int Y);
    virtual void Finish(void);
};

//---------------------------------------------------------------------------
class TToolSelect: public TTool{
    TShape* shape;
    TPoint* point;
    TFrame* frame;

public:
	TToolSelect(int Handle);
	
	void Group(void);
	void Ungroup(void);
	void Foreground(void);
	void Background(void);
	void Front(void);
	void Back(void);

	void MouseDown(bool right,int X,int Y);
	void MouseMove(int X,int Y);
	void MouseUp(int X,int Y);
	void Finish(void);
};

class TToolLine: public TTool{
    bool click;
    TLine* FS;
public:
    TToolLine(int Handle);
    void MouseDown(bool right,int X,int Y);
    void MouseMove(int X,int Y);
    void MouseUp(int X,int Y);
};

class TToolRect: public TTool {
    bool click;
    TRectangle* FS;
public:
    TToolRect(int Handle);
    void MouseDown(bool right,int X,int Y);
    void MouseMove(int X,int Y);
    void MouseUp(int X,int Y);
};

class TToolCircle: public TTool {
    bool click;
    TCircle* FS;
public:
    TToolCircle(int Handle);
    void MouseDown(bool right,int X,int Y);
    void MouseMove(int X,int Y);
    void MouseUp(int X,int Y);
    
};

//---------------------------------------------------------------------------
//Glyphs

class TGlyph{
public:
    TGlyph(void);
    virtual void Draw(TBitmap* b,TRect r);
    virtual ~TGlyph(void);
};

class TDecorator : public TGlyph{
	TGlyph* Component;
public:
    TDecorator(void): TGlyph(){};
    ~TDecorator(void);
    void SetComponent(TGlyph* cmp);
    void Draw(TBitmap* b,TRect r);
};

class TBackground : public TGlyph{
    TBitmap* Image;
public:
        TBackground(void): TGlyph(){};
        void SetImage(TBitmap* b);
        void Draw(TBitmap* b,TRect r);
        ~TBackground(void);
};

class TBevels : public TGlyph {
    TColor col1,col2;
public:
    TBevels(TColor c1,TColor c2):TGlyph(){col1=c1;col2=c2;};
    void Draw(TBitmap* b,TRect r);
};

class TMoved : public TDecorator {
    int step;
public:
    void SetStep(int s);
    void Draw(TBitmap* b,TRect r);
};

class TBordered : public TDecorator {
    int width;
public:
    void SetWidth(int w);
    void Draw(TBitmap* b,TRect r);
};

class TBeveled : public TDecorator {
    TColor c1,c2;
    int width;
public:
    void SetWidth(int w);
    void SetColors(TColor c1,TColor c2);
    void Draw(TBitmap* b,TRect r);
};

//---------------------------------------------------------------------------
//TCompositor (Strategy)

class TCompositor{
    TToolBar* tb;
    TImageList* ImageList;
public:
    TCompositor(TToolBar* tbar) : tb(tbar) {}
    void SetImageList(TImageList* IList);
    void Show(TBitmap* b);
    int Pos2Number(int X,int Y);
};

class TCompositor2X: public TCompositor{
public:
    TCompositor2X(TToolBar* tbar): TCompositor(tbar) {}
    void Show(TBitmap* b);
};

//---------------------------------------------------------------------------
//TVisitor

class TVisitor{
    TToolBar* tb;
public:
    TVisitor(TToolBar* tbar):tb(tbar) {}
    void VisitTool(TTool* tool);
    void VisitToolManager(TToolManager* TManager);
};

