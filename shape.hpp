#pragma once

#include <list>
#include <fstream>

class TContainerShape;

class TShape {
public:
    TShape();
    virtual ~TShape();
    virtual int IsSelect(double x, double y); 
    virtual void Draw(double Width, double Height)=0;
    
    virtual int Save(std::ofstream& file);
    virtual int Load(std::ifstream& file);
};

class TContainerShape : public TShape {
    std::list<TShape*> items;
    double mx1, my1, mx2, my2;
    void Oriented();
public:
    TContainerShape();
    ~TContainerShape();
    void AddShape(TShape* shape);
    void DelShape(TShape* shape);
    
    int GetCount();
    TShape* GetShape(int index);
    int IsSelect(double x, double y);
    void Draw(double Width, double Height);

    int Save(std::ofstream& file) override;
    int Load(std::ifstream& file) override;
};

class TPoint : public TShape{
    double X;
    double Y;
public:
    TPoint(void);
    ~TPoint(void);

    int IsSelect(double x, double y);
    void Draw(double Width, double Height);

    int Save(std::ofstream& file) override;
    int Load(std::ifstream& file) override;
};

class TFrame : public TShape {
    double X1, Y1, X2, Y2;
public:
    TFrame(void);
    ~TFrame(void);

    void Draw(double Width, double Height);
};

class TLine : public TShape {
    double X1, Y1, X2, Y2;
    TLine();
    ~TLine();

    int IsSelect(double x, double y);
    void Draw(double Width, double Height);
    TContainerShape* GetSelection();
    
    int Save(std::ofstream& file) override;
    int Load(std::ifstream& file) override;

};

class TRectangle : public TShape {
    double X1, Y1, X2, Y2;
public:
    TRectangle();
    ~TRectangle();

    int IsSelect(double x, double y);
    void Draw(double Width, double Height);

    int Save(std::ofstream& file) override;
    int Load(std::ifstream& file) override;
};

class TCircle : public TShape {
    double X1;double X2;
    double Y1;double Y2;
    double Dist();
public:
    TCircle();
    ~TCircle();

    int IsSelect(double x, double y);
    void Draw(double Width, double Height);
    TContainerShape* GetSelection();

    int Save(std::ofstream& file) override;
    int Load(std::ifstream& file) override;
};

