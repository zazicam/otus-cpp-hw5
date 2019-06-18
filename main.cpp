#include "shape.hpp"
#include "tools.hpp"

#include "framework.hpp"

class TMainForm : public TForm {
public:
	TToolBar* ToolBar;
	TContainerShape* ContainerShape;
	
	void FormMouseDown(TMouseButton Button, int X, int Y);
	void FormMouseMove(int X, int Y);
	void FormMouseUp(TMouseButton Button, int X, int Y);
};

int main() {
	
	TMainForm* form = new TMainForm();
	form->exec();
	
	return 0;
}
